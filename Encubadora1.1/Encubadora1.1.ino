/**
 * ENCUBADORA versão 1.1
 * Atualização:
 * - Adicionado o controle de ventilação para ajudar a baixar a temperatura ou umidade da encubadora.
 * Suporte:
 * 4 lâmpadas
 * 1 sensor DHT (temperatura e humidade)
 * 1 ventilador
 * by wesleywilly@gmail.com
 */
#include <dht.h>

#define s 1000
#define m (s*60)
#define h (m*60)
#define d (h*24)

int plusDay = 30; //Digite a idade das aves em dias. Deixe com 0 caso sejam recém nascidas

#define dht_dpin A1 //Define o pino do sensor de temperatura e umidade

dht DHT; //Cria uma variável para o sensor de temperatura e umidade

int lampada[4] = {7, 8, 9, 10};

int ventilador = 11;

float oldTemperatura; //Armazena o valor da ultima leitura de temperatura realizada
float oldUmidade; //Armazena o valor da ultima leitura de umidade realizada
unsigned long int oldMillis = 0; //Armazena a o tempo da última alálise

unsigned long int difMillis = 120000; //Intervalo de tempo de leitura
unsigned long int minDifMillis = 120000; //Limite minimo de intervalo de tempo
unsigned long int maxDifMillis = 600000; //Limite maximo de intervalo de tempo

float temperatura; //Armazena a leitura da temperatura atual do sensor
float umidade; //Armazena a leitura da umidade atual do sensor

int lampadas = 0; //Número de lampadas que devem ser ligadas 
int direcao = 0; //Identifica a intenção de controle de temperatura da encubadora

int temperaturaInicial[4] = {33, 29, 27, 26};
int temperaturaFinal[4] = {29, 27, 26, 25};
int umidadeIdeal[4] = {50, 60, 60, 70};


float temperaturaIdeal; //Armazena a temperatura ideal do ambiente
int difUmidade; //identifica se a umidade está abaixo ou acima do ideal;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(lampada[i], OUTPUT);
  }

  pinMode(ventilador,OUTPUT);

  DHT.read11(dht_dpin);
  oldUmidade = DHT.humidity;
  oldTemperatura = DHT.temperature;
  interruptores();
  delay(2000);
  
}

void loop() {
  //Leitura da temperatura e umidade
  DHT.read11(dht_dpin);
  umidade = DHT.humidity;
  temperatura = DHT.temperature;
  /**
   * Verifica se houve alteração de temperatura desde a última leitura
  **/
  if (temperatura != oldTemperatura) {
    //Ajusta o intervalo de verificação da temperatura
    if (millis() - oldMillis > difMillis && millis() - oldMillis < 600000) {
      difMillis = millis() - oldMillis;
    } else {
      if ((int)difMillis/2 > minDifMillis) {
        difMillis = (int) difMillis/2;
      } else {
        difMillis = minDifMillis;
      }
    }
  }

  /**
   * Calcula o tempo de encubação
   */
  int dia = (millis()/d)+plusDay;
  int semana = ((int) dia / 7);
  int diaSemana = dia % 7;

  /**
   * Verifica se está dentro das 4 primeiras semanas
   */
  if (semana < 4) {
    //Calcula a temperatura ideal de acordo com o tempo de encubação
    temperaturaIdeal = temperaturaInicial[semana] - (((float)diaSemana / 6) * (temperaturaInicial[semana] - temperaturaFinal[semana]));
    difUmidade = umidade - umidadeIdeal[semana];
    analise();

  } else {
    //Final do processo de encubação
    temperaturaIdeal = 23;
    analise();
  }
  
  oldTemperatura = temperatura;//Armazena a última leitura de temperatura
 
  oldMillis = millis(); //Armazena a o tempo da última alálise
  
  delay(difMillis);//Aguardar para a próxima analise
}

/*
 * Verifica se a temperatura está de acordo com a temperatura ideal e realiza o controle através das lâmpadas
 */
void analise() {
  if (temperatura < temperaturaIdeal) {
    ligarLamp();
    direcao = 1;
  } else {
    if (temperatura <= temperaturaIdeal && temperatura >= temperaturaIdeal) {
      if (direcao > 0) {
        desligarLamp();
        direcao = 0;
      } else {
        if (direcao < 0) {
          ligarLamp();
          direcao = 0;
        }
      }

    } else {
      desligarLamp();
      direcao = -1;
    }
  }
}
/**
 * Aumenta o número de lâmpadas ligadas
 */
void ligarLamp() {
  if (lampadas < 4) {
    lampadas++;
  }
  interruptores();
}
/**
 * Diminui o número de lâmpadas ligadas
 */
void desligarLamp() {
  if (lampadas > 0) {
    lampadas--;
  }
  interruptores();
}
/*
 * Define quais lâmpadas irão ligar ou desligar de acordo com a variável "lampadas"
 */
void interruptores() {
  switch (lampadas) {
    case 0:
      digitalWrite(lampada[0], HIGH);
      digitalWrite(lampada[1], LOW);
      digitalWrite(lampada[2], LOW);
      digitalWrite(lampada[3], HIGH);
      break;
    case 1:
      digitalWrite(lampada[0], LOW);
      digitalWrite(lampada[1], LOW);
      digitalWrite(lampada[2], LOW);
      digitalWrite(lampada[3], LOW);
      break;
    case 2:
      digitalWrite(lampada[0], LOW);
      digitalWrite(lampada[1], HIGH);
      digitalWrite(lampada[2], LOW);
      digitalWrite(lampada[3], LOW);
      break;
    case 3:
      digitalWrite(lampada[0], LOW);
      digitalWrite(lampada[1], HIGH);
      digitalWrite(lampada[2], HIGH);
      digitalWrite(lampada[3], LOW);
      break;
    case 4:
      digitalWrite(lampada[0], LOW);
      digitalWrite(lampada[1], HIGH);
      digitalWrite(lampada[2], HIGH);
      digitalWrite(lampada[3], HIGH);
      break;
  }
  if(difUmidade>0 || direcao<0){
    digitalWrite(ventilador,HIGH);
  }else{
    digitalWrite(ventilador,LOW);
  }
  
}

