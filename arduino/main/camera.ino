

// const int motorCamUDpwm = 3;
const int motorCamUDforward = 12;
const int motorCamUDreverse = 5;

// const int motorCamLRpwm = 5;
const int motorCamLRforward = 7;
const int motorCamLRreverse = 8;

void cameraInit() {
  pinMode(motorCamUDforward, OUTPUT);
  pinMode(motorCamUDreverse, OUTPUT);

  // pinMode(motorCamLRpwm, OUTPUT);
  pinMode(motorCamLRforward, OUTPUT);
  pinMode(motorCamLRreverse, OUTPUT);

  digitalWrite(motorCamUDforward, LOW);
  digitalWrite(motorCamUDreverse, LOW);
  digitalWrite(motorCamLRforward, LOW);
  digitalWrite(motorCamLRreverse, LOW);
}

void cameraTest() {
  // analogWrite(motorCamUDpwm, 255);
  digitalWrite(motorCamUDforward, HIGH);
  delay(500);
  digitalWrite(motorCamUDforward, LOW);
  delay(100);
  digitalWrite(motorCamUDreverse, HIGH);
  delay(500);
  digitalWrite(motorCamUDreverse, LOW);

  delay(100);
  Serial.println("camLR");
  digitalWrite(motorCamLRforward, HIGH);
  delay(1000);
  digitalWrite(motorCamLRforward, LOW);

  delay(100);

  digitalWrite(motorCamLRreverse, HIGH);
  delay(2000);
  digitalWrite(motorCamLRreverse, LOW);

  delay(100);

  digitalWrite(motorCamLRforward, HIGH);
  delay(1000);
  digitalWrite(motorCamLRforward, LOW);
  delay(100);
  Serial.println("apiCamTest ended");
}
