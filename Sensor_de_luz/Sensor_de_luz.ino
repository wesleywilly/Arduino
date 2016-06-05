int piezoPin = 8;
int ldrPin = 0;
int ldrValue = 0;

void setup() {
  

}

void loop() {
  ldrValue = analogRead(ldrPin);
  tone(piezoPin,ldrValue);
  delay(50);
  noTone(piezoPin);
  delay(1000);

}
