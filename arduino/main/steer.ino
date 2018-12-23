
void steerInit(PCF8574 pcfSteer) {
  pcfSteer.write(2, LOW);
  pcfSteer.write(2, LOW);
}

void steerTest(PCF8574 pcfSteer) {
  pcfSteer.write(2, HIGH);
  delay(500);
  pcfSteer.write(2, LOW);
  delay(100);
  pcfSteer.write(3, HIGH);
  delay(500);
  pcfSteer.write(3, LOW);

  delay(100);
}
