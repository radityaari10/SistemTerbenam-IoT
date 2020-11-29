#include <Keypad.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define Password_Lenght 7

LiquidCrystal_I2C lcd(0x20,20,4);
char Data[Password_Lenght];
char Master[Password_Lenght] = "202003";

byte data_count = 0;
bool Pass_is_good;

char customKey;
const byte ROWS = 4;
const byte COLS = 4;

int pinLedG = 12;
int pinLedR = 13;

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
  pinMode(pinLedG, OUTPUT);
  pinMode(pinLedR, OUTPUT);
  lcd.init();
  lcd.backlight();

  lcd.print("Password");
  lcd.setCursor(0,1);
  lcd.print("By : Raditya Ari");

  delay(2000);
  lcd.clear();
}

void loop() {
  lcd.setCursor(0,0);
  lcd.print("Enter Password");
  customKey = customKeypad.getKey();

  if(customKey && customKey != '='){
    Data[data_count] = customKey;
    lcd.setCursor(data_count, 1);
    lcd.print(Data[data_count]);
    Serial.println(Data[data_count]);
    data_count++;
  }
  
  if(customKey == 'C'){
    data_count = 0;
    clearData();
    lcd.clear();
    Serial.println(Data[data_count-1]);
  }
  
  if(customKey == '='){
    lcd.clear();
    lcd.setCursor(0,0);
    Serial.println("Data : "+String(Data));
    Serial.println("Master : "+String(Master));
    if(!strcmp(Data, Master)){
      lcd.print("Selamat Datang");
      digitalWrite(pinLedG, HIGH);
    }
    else{
      lcd.print("Password Salah");
      digitalWrite(pinLedR, HIGH); 
    }
    
    delay(5000);
    lcd.clear();
    clearData();
  }

  lcd.setCursor(0,2);
  lcd.print("'C' = Cancel");
  lcd.setCursor(0,3);
  lcd.print("'=' = Confirm");
}

void clearData(){
  while(data_count != 0){
    Data[data_count--] = 0;
  }
  digitalWrite(pinLedG, LOW);
  digitalWrite(pinLedR, LOW);
  return;
}
