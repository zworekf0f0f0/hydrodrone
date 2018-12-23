

// const int motorCamUDpwm = 3;
const int motorCamUDforward = 0;
const int motorCamUDreverse = 1;

// const int motorCamLRpwm = 5;
const int motorCamLRforward = 7;
const int motorCamLRreverse = 6;

void cameraInit(PCF8574 pcfCamera) {
  // pinMode(motorCamUDforward, OUTPUT);
  // pinMode(motorCamUDreverse, OUTPUT);

  // // pinMode(motorCamLRpwm, OUTPUT);
  // pinMode(motorCamLRforward, OUTPUT);
  // pinMode(motorCamLRreverse, OUTPUT);

  pcfCamera.write(motorCamUDforward, LOW);
  pcfCamera.write(motorCamUDreverse, LOW);
  pcfCamera.write(motorCamLRforward, LOW);
  pcfCamera.write(motorCamLRreverse, LOW);
}

void cameraTest(PCF8574 pcfCamera) {
  // analogWrite(motorCamUDpwm, 255);
  pcfCamera.write(motorCamUDforward, HIGH);
  delay(500);
  pcfCamera.write(motorCamUDforward, LOW);
  delay(100);
  pcfCamera.write(motorCamUDreverse, HIGH);
  delay(500);
  pcfCamera.write(motorCamUDreverse, LOW);

  delay(100);
  Serial.println("camLR");
  pcfCamera.write(motorCamLRforward, HIGH);
  delay(1000);
  pcfCamera.write(motorCamLRforward, LOW);

  delay(100);

  pcfCamera.write(motorCamLRreverse, HIGH);
  delay(2000);
  pcfCamera.write(motorCamLRreverse, LOW);

  delay(100);

  digitalWrite(motorCamLRforward, HIGH);
  delay(1000);
  digitalWrite(motorCamLRforward, LOW);
  delay(100);
  Serial.println("apiCamTest ended");
}
