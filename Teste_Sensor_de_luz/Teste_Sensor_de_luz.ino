int ldrPin = 0;
int led[] = {5,6,7,8,9,10};


int aux = 0;
int minl;
int maxl = 0;
int range = 0;
int updateTime = 5; //segundos
unsigned long lastUpdate = millis();
unsigned long score;

void setup() {
  for(int i=0; i<6;i++){
    pinMode(led[i],OUTPUT);
  }
  
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("Teste do sensor de luz");
  minl = analogRead(ldrPin);
  aux = minl;
}

void loop() {
  int luz = analogRead(ldrPin);
  
  if(luz < minl)
    minl = luz;

  if(luz>maxl)
    maxl = luz;

  range = maxl-minl;
  
  //score =(((luz-minl))*100)/range;
  score =((range-(luz-minl))*100)/range;
  updateLed(score);
  /*
  Serial.print(" L:");
  Serial.print(luz);
  Serial.print(" M:");

  Serial.print(maxl);
  Serial.print(" m:");
  Serial.print(minl);
  Serial.print(" r:");
  Serial.print(range);
  Serial.print(" s:");
  Serial.println(score);
 */
  
  aux = luz;
  if(millis()-lastUpdate>updateTime*1000){
    if(range>2){
      int ml = maxl-luz;
      int lm = luz-minl;
      if(ml>lm){
        maxl--;
      }else
      minl++;
    } 
    lastUpdate = millis();
    /*
    Serial.println("Updated!");
    Serial.print("Range:");
    Serial.println(range);
    Serial.print("MAX:");
    Serial.println(maxl);
    Serial.print("MIN:");
    Serial.println(minl);
    Serial.println("");
    */
  }
  //delay(500);

  
}

void updateLed(int value){
  for(int i=0; i<6;i++){
    int ledValue = (i)*20;
    if(value>=ledValue)
      digitalWrite(led[i], HIGH);
    else
      digitalWrite(led[i], LOW);
  }
}

