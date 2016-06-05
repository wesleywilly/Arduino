int ledPin = 6;
int botao = 2;
void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(botao, INPUT);

  
}

void loop() {
  
  if(digitalRead(botao) == HIGH)
    digitalWrite(ledPin, HIGH);
  else
    digitalWrite(ledPin, LOW);
}
