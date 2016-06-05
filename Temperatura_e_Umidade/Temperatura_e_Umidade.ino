#include <dht.h>

#define dht_dpin A1

dht DHT;

int sensor;
float temp;



void setup() {
  Serial.begin(9600);
  delay(1000);
}
void loop() {
  DHT.read11(dht_dpin);
  float umid = DHT.humidity;
  float temp = DHT.temperature;
  Serial.print("Umidade = ");
  Serial.print(umid);
  Serial.print(" %  ");
  Serial.print("Temperatura = ");
  Serial.print(temp); 
  Serial.println(" Celsius  ");
  delay(2000);
}

void atualizar(int temp, int umid){
  
}

