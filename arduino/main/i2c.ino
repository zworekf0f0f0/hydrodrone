
void i2cInit() {
  // Wire.begin(); // Odkommentowanie wlacza na stale kamere. Sprawdzic na necie. Serialdziała
  //  hmm po przepieci z 2 na 4 ustalo
  // ale nie 4 jest high podczas startu
 
  // Serial.begin(9600);
  // while (!Serial); // Leonardo: wait for serial monitor
  // Serial.println("I2C Scanner");
}

void i2cScan() {
  byte error;
  byte address;
  int nDevices;

  Serial.println("Scanning...");
 
  nDevices = 0;
  for (address = 1; address < 127; address++ ) {
    // The i2c_scanner uses the return value of
    // the Write.endTransmisstion to see if
    // a device did acknowledge to the address.
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
 
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.print(address,HEX);
      Serial.println("  !");
 
      nDevices++;
    }
    else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address<16) {
        Serial.print("0");
      }
      Serial.println(address,HEX);
    }    
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices found\n");
  } else {
    Serial.println("done\n");
  }

  delay(1000);
}
