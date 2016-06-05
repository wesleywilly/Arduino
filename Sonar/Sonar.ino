#include "Ultrasonic.h"

Ultrasonic sonar(6,7);

long ms = 0;
float distanciaCM = 0;

void setup() {
  Serial.begin(9600);

}

void loop() {
  ms = sonar.timing();

  distanciaCM = sonar.convert(ms,Ultrasonic::CM);

  Serial.print(distanciaCM);
  Serial.println(" cm");
  delay(1000);

}
