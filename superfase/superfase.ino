int ledVerde1 = 11;
int ledVerde2 = 10;
int ledAmarelo = 9;
int ledVermelho = 8;
int forca = 0;
int max = 255;
double brig = 0;
int cut[3] = {25,50,75};

void setup() {
  
  pinMode(ledVerde1, OUTPUT);
  pinMode(ledVerde2, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

}

void loop() {
  if(forca>=cut[2]){
    brig = ((forca-cut[2])/25)*255;
    digitalWrite(ledVerde1, HIGH);
    digitalWrite(ledVerde2, HIGH);
    digitalWrite(ledAmarelo, HIGH);
    analogWrite(ledVermelho, brig);
  }else{
    if(forca>=cut[1]){
      brig = ((forca-cut[1])/25)*255;
      digitalWrite(ledVerde1, HIGH);
      digitalWrite(ledVerde2, HIGH);
      analogWrite(ledAmarelo, brig);
      digitalWrite(ledVermelho, LOW);
    }else{
      if(forca>=cut[0]){
         brig = ((forca-cut[0])/25)*255;
         digitalWrite(ledVerde1, HIGH);
         analogWrite(ledVerde2, brig);
         digitalWrite(ledAmarelo, LOW);
         digitalWrite(ledVermelho, LOW);
      }else{
        brig = ((forca-cut[0])/25)*255;
        analogWrite(ledVerde1, brig);
        digitalWrite(ledVerde2, LOW);
        digitalWrite(ledAmarelo, LOW);
        digitalWrite(ledVermelho, LOW);
      }
    }
  }
  
  if(forca>=100){
    forca = 0;
  }else{
    forca++;
  }
  
}
