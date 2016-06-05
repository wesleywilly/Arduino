#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  lcd.begin(16,1);

}

void loop() {
  basicPrintDemo();
  displayOnOffDemo();
  setCursorDemo();
  scrollLeftDemo();
  scrollRightDemo();
  cursorDemo();
  createGlyphDemo();

}

void basicPrintDemo(){
  lcd.clear();
  lcd.print("Hello World!");
  delay(3000);
}

void displayOnOffDemo(){
  lcd.clear();
  lcd.print("Display ON/OFF");
  for(int i = 0; i<3; i++){
    lcd.noDisplay();
    delay(1000);
    lcd.display();
    delay(1000);
  }
}

void setCursorDemo(){
  lcd.clear();
  lcd.print("SetCursor Demo");
  delay(2000);
  lcd.clear();
  lcd.setCursor(10,0); //Coluna 10, Linha 1
  lcd.print("C10,L1");
  delay(2000);
  lcd.clear();
  lcd.setCursor(3,0);
  lcd.print("C3,L1");
  delay(2000);
}

void scrollLeftDemo(){
  lcd.clear();
  lcd.print("Scroll Left Demo");
  delay(1000);
  lcd.clear();
  lcd.setCursor(7,0);
  lcd.print("Beginning");
  lcd.setCursor(9,0);
  lcd.print("Arduino");
  delay(3000);
  for(int i = 0; i<16; i++){
    lcd.scrollDisplayLeft();
    delay(250);
  }
}

void scrollRightDemo(){
  lcd.clear();
  lcd.print("Scroll Right");
  delay(1000);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Beginning");
  lcd.setCursor(3,0);
  lcd.print("Arduino");
  delay(3000);
  for(int i = 0; i<16; i++){
    lcd.scrollDisplayRight();
    delay(250);
  }
}

void cursorDemo(){
  lcd.clear();
  lcd.cursor();
  lcd.print("Cursor On");
  delay(3000);
  lcd.clear();
  lcd.noCursor();
  lcd.print("Cursor Off");
  delay(3000);
  lcd.clear();
  lcd.cursor();
  lcd.blink();
  lcd.print("Cursor Blink On");
  delay(3000);
  lcd.noCursor();
  lcd.noBlink();
}
void createGlyphDemo(){
  lcd.clear();

  byte happy[8] = {
    B00000,
    B00000,
    B10001,
    B00000,
    B10001,
    B01110,
    B00000,
    B00000};

    byte sad[8] = {
     B00000,
     B00000,
     B10001,
     B00000,
     B01110,
     B10001,
     B00000,
     B00000};

     lcd.createChar('0', happy);
     lcd.createChar('1', sad);

     for(int i = 0; i<5; i++){
      lcd.setCursor(8,0);
      lcd.write('0');
      delay(3000);
      lcd.setCursor(8,0);
      lcd.write('1');
      delay(3000);
     }
}


