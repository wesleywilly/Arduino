int ledPin[] = {9,8,7,6,5,4,3,2};
int ldrPin = 0;
int ldrValue = 0;
int normvalue = 0;
void setup() {
  for(int i = 0;i<10;i++){
    pinMode(ledPin[i], OUTPUT);
  }
}

void loop() {
  ldrValue = (analogRead(ldrPin));
  
  
  
  for(int i = 0; i<10; i++){
    if(normaliza(ldrValue)>i)
      digitalWrite(ledPin[i], HIGH);
    else
      digitalWrite(ledPin[i], LOW);
  }
}

int normaliza(int valor){
  return (valor/100);
}


