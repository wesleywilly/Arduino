int ledVerde = 4;
int ledAmarelo = 3;
int ledVermelho = 2;
int ledPedVerde = 6;
int ledPedVermelho = 5;
int botao = 7;
int pressionado = LOW;
int pisca = -1;
long unsigned tempo;
int tLimite = 10000;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledPedVerde, OUTPUT);
  pinMode(ledPedVermelho, OUTPUT);  
  pinMode(botao, INPUT);
  verde();
  tempo = millis();
}

void loop() {
  int state = digitalRead(botao);
  if(state == HIGH){
    pressionado = HIGH;
  }
    
  if(pressionado == HIGH && (millis()-tempo>=tLimite)){
    amarelo();
    delay(2000);
    vermelho();
    delay(6000);
    for(int i=0;i<10;i++)
      amareloPed(400);
    tempo = millis();
    pressionado = LOW;
    verde();
  }
}

void verde(){
  digitalWrite(ledVerde, HIGH);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledPedVerde, LOW);
  digitalWrite(ledPedVermelho, HIGH);
}

void vermelho(){
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, HIGH);
  digitalWrite(ledPedVerde, HIGH);
  digitalWrite(ledPedVermelho, LOW);
}

void amareloPed(int tdelay){
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledVermelho, HIGH);
  digitalWrite(ledPedVerde, LOW);
  if(pisca > 0)
    digitalWrite(ledPedVermelho, HIGH);
  else
    digitalWrite(ledPedVermelho, LOW);
  pisca = -pisca;
  delay(tdelay);  
}

void amarelo(){
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, HIGH);
  digitalWrite(ledVermelho, LOW);
  digitalWrite(ledPedVerde, LOW);
  digitalWrite(ledPedVermelho, HIGH);
}


