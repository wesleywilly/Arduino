#include <Servo.h>

Servo radar;
Servo head;
int ldrPin = 0;
int ledPin = 11;

int ldrValue = 0;

int minLum = 1000;
int lumPos = 0;
int radarPos = 0;


void setup() {
  radar.attach(5);
  head.attach(6);
  radar.write(0);
  head.write(0);
  pinMode(ledPin, OUTPUT);
  

}

void loop() {
  minLum = 1000;
  digitalWrite(ledPin, LOW);
  int headPos = direcao();
  head.write(headPos);
  delay(100);
  digitalWrite(ledPin, HIGH);
  delay(3000);
  

}

int direcao(){
  int pos = 0;
  while(pos<180){
    radar.write(pos);
    ler(pos);
    delay(100);
    pos +=10;
  }
  
  return lumPos;
}

void ler(int pos){
  ldrValue = analogRead(ldrPin);
  if(ldrValue<minLum){
    minLum = ldrValue;
    lumPos = pos;
  }
}

