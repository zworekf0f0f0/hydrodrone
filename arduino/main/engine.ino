
PCF8574 pcfEngine(0x20);

void engineInit() {
  Serial.println("engine init start");
  pcfEngine.begin(LOW);
   // pcfEngine.pinMode(0, OUTPUT);
   // pcfEngine.pinMode(1, OUTPUT);

  delay(100);

  pcfEngine.write(0, HIGH);
  delay(500);
  pcfEngine.write(0, LOW);

  delay(100);

  pcfEngine.write(1, HIGH);
  delay(500);
  pcfEngine.write(1, LOW);

  Serial.println("engine init stop");
  
  delay(100);
}

void engineLoop() {
  
}
