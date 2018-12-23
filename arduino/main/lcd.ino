#include <LiquidCrystal_PCF8574.h>

LiquidCrystal_PCF8574 lcd(0x27);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int show;
String padder = "                ";
boolean isHbEven = true; 

void lcdInit() {
  int error;

  // Serial.begin(115200);
  Serial.println("LCD...");
  Serial.println("Dose: check for LCD");

  // See http://playground.arduino.cc/Main/I2cScanner
  // Wire.begin();
  Wire.beginTransmission(0x27);
  error = Wire.endTransmission();
  Serial.print("Return: ");
  Serial.print(error);

  if (error == 0) {
    Serial.println("Success: LCD found.");
  } else {
    Serial.println("Error: LCD not found.");
  }

  lcd.begin(16, 2); // initialize the lcd
  lcd.clear();
  lcd.setBacklight(255);
}

void lcdTest() {
  // lcd.setBacklight(255);
  // lcd.home();
  // lcd.clear();
  // lcd.setBacklight(0);
  // lcd.setBacklight(255);
  // lcd.cursor();
  // lcd.blink();
  // lcd.noBlink();
  // lcd.noCursor();
  // lcd.noDisplay();
  // lcd.display();
  // lcd.scrollDisplayLeft();
  // lcd.scrollDisplayRight();
}

void lcdPrintLines(String first, String second) {
  // lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(first + padder);
  lcd.setCursor(0, 1);
  lcd.print(second + padder);
}

void lcdPrintTitle(String msg) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(msg + padder);
}

void lcdPrintMessage(String msg) {
  lcd.setCursor(0, 1);
  lcd.print(msg + padder);
}

void lcdHb() {
  lcd.setCursor(15, 0);
  if (isHbEven) {
    lcd.print("x");
  } else {
    lcd.print("o");
  }

  isHbEven = !isHbEven;
}
