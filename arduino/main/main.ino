
#include <Wire.h>
#include <PCF8574.h>

unsigned long time;
unsigned long ticksCounter = 0;
bool isHBLedOn = false;
bool isResetedNewSecond = false;
bool isExecutingNewSecond = false;

// pin 2 becomes high right after Wire.begin
// pin 4 is high during boot time

void setup() {
  lcdInit();
  lcdTest();

  PCF8574 pcf24(0x24);
  pcf24.begin(LOW);

  lcdPrintTitle("initializing");

  pinMode(LED_BUILTIN, OUTPUT);

  Serial.begin(9600);

  lcdPrintMessage("... serial");
  delay(999);
  serialInit();

  lcdPrintMessage("... i2c");
  delay(999);
  Wire.begin();
  Serial.println("zrobione");

  i2cInit();
  i2cScan();

  lcdPrintMessage("... tower");
  cameraInit(pcf24);
  cameraTest(pcf24);

  lcdPrintMessage("... steer");
  steerInit(pcf24);
  steerTest(pcf24);

  lcdPrintMessage("... engine");
  engineInit();
  
  lcdPrintMessage("... done");

  delay(999);
  lcdPrintLines("", "");
}

void loop() {
  time = millis() % 1000;

  isExecutingNewSecond = false;
  if (time <= 100 && !isResetedNewSecond) {
    isResetedNewSecond = true;
    isExecutingNewSecond = true;
  } else if (time > 100 && isResetedNewSecond) {
    isResetedNewSecond = false;
  }
  
  if (time <= 100 && !isHBLedOn) {
    digitalWrite(LED_BUILTIN, HIGH);
    isHBLedOn = true;
  } else if (time > 100 && isHBLedOn) {
    digitalWrite(LED_BUILTIN, LOW);
    isHBLedOn = false;
  }

  if (isExecutingNewSecond) {
    Serial.print("hb+tps: ");
    Serial.println(ticksCounter);
    ticksCounter = 0;
    lcdHb();
  }

  if (ticksCounter > 100) {
    delay(1);
  }

  ticksCounter++;
}
