byte ledPin[] = {4,5,6,7,8,9,10,11,12};
int ledDelay;
int direction = 1;
int currentLED = 0;
unsigned long changeTime;
int potPin = 2; //Potenciometro

void setup() {
  for(int x=0; x<10;x++){ //define todos os leds de saida
    pinMode(ledPin[x], OUTPUT);
  }
  changeTime = millis();

}

void loop() {
  ledDelay = (int)analogRead(potPin)/2;
  if((millis() - changeTime) > ledDelay){
    changeLED();
    changeTime = millis();
  }

}

void changeLED(){
  for(int x=0; x<9; x++){
    digitalWrite(ledPin[x], LOW);
  }
  digitalWrite(ledPin[currentLED],HIGH);
  currentLED += direction;

  if(currentLED == 8){
    direction = -1;
  }
  if(currentLED ==0){
    direction = 1;
  }
}

