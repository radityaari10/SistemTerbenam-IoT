#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20,16,2);

long first =0;
long scnd = 0;
double total = 0;

char customKey;
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'7', '8', '9', '/'}, // disesuiakan dengan keypad
  {'4', '5', '6', '*'},
  {'1', '2', '3', '-'},
  {'C', '0', '=', '+'}
};

byte rowPins[ROWS] = {9,8,7,6};
byte colPins[COLS] = {5,4,3,2};

Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();

  lcd.print("KALKULATOR");
  lcd.setCursor(0,1);
  lcd.print("By : Raditya Ari");

  delay(2000);
  lcd.clear();
}

void loop() {
  customKey = customKeypad.getKey();

  switch(customKey){
    case '0' ... '9':
//      lcd.setCursor(0,0);
      first = first * 10 + (customKey - '0');
      lcd.print(customKey);
      Serial.println(first);
      break;
    case '+':
      first = (total != 0 ? total : first);
//      lcd.setCursor(0,1);
      lcd.print(" + ");
      scnd = SecondNumber();
      total = first + scnd;
      lcd.setCursor(0,1);
      lcd.print(total);
      first = 0;
      scnd = 0;
      break;
    case '-':
      first = (total != 0 ? total : first);
//      lcd.setCursor(0,1);
      lcd.print(" - ");
      scnd = SecondNumber();
      total = first - scnd;
      lcd.setCursor(0,1);
      lcd.print(total);
      first = 0;
      scnd = 0;
      break;
    case '*':
      first = (total != 0 ? total : first);
//      lcd.setCursor(0,1);
      lcd.print(" * ");
      scnd = SecondNumber();
      total = first * scnd;
      lcd.setCursor(0,1);
      lcd.print(total);
      first = 0;
      scnd = 0;
      break;
    case '/':
      first = (total != 0 ? total : first);
//      lcd.setCursor(0,1);
      lcd.print(" / ");
      scnd = SecondNumber();
      total = first / scnd;
      lcd.setCursor(0,1);
      lcd.print(total);
      first = 0;
      scnd = 0;
      break;
    case 'C':
      total = 0;
      lcd.clear();
      break;
  }
}

long SecondNumber(){
  while(1){
    customKey = customKeypad.getKey();
    if(customKey >= '0' && customKey <= '9'){
      scnd = scnd * 10 + (customKey - '0');
//      lcd.setCursor(0,2);
      lcd.print(customKey);
      Serial.println(scnd);
    }

    if(customKey == '=') break;
  }
  return scnd;
}
