
void serialInit() {
  unsigned long startTime = millis();
  unsigned long nowTime;

  while (!Serial) {
    delay(1);
    nowTime = millis();
    if (nowTime - startTime > 5000) {
      break;
    }
  }
}
