#include  <LiquidCrystal.h>         // Inclui a biblioteca para utilizar o LCD.
#define          sensor           0        // Define o pino A0 como “sensor”
 
int  Ventrada;           // Variável para ler o sinal do pino do Arduino
float  Temperatura; // Variável que recebe o valor convertido para temperatura.
 
LiquidCrystal  lcd    (12, 11, 5, 4, 3, 2); 
/* Esta função acima declara quais os pinos do Arduino serão utilizados para o controle do LCD */
 
void  setup()
{
  lcd.begin(16, 1);                            // Diz para o Arduino que o display é 16x2.
  lcd.print("Temperatura: ");           // Manda o texto para a tela do display
}
 
void  loop()
{
  Ventrada = analogRead (sensor);  /*  Manda o Arduino ler o pino e armazena
 o valor em “Ventrada”. */
  Temperatura=(500*Ventrada)/1023;  /* Converte o valor de tensão em
temperatura e armazena na variável “Temperatura” */
  lcd.setCursor(0, 1);           // Move o cursor do display para a segunda linha.
  lcd.print("S: ");
  lcd.println(Ventrada);
  delay(1000);
  lcd.setCursor(0, 1); 
  lcd.print(" T: ");
  lcd.print(Temperatura);    // Exibe o valor de temperatura no display.
       // Escreve “C” para dizer que a escala é Celsius.
  
  delay(2000); /* Aguarda 1 segundo para efetuar uma nova leitura de
temperatura. */
}
