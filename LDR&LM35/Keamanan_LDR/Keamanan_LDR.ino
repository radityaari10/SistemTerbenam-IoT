#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);

int pinLDR = A0;
int pinBtn = 11;
int pinBuz = 12;
int pinLED = 13;
int dataLDR = 0;

int stateBtnLast, stateBuzzerLast = LOW;
int stateBtn;

void setup() {
  Serial.begin(9600);
  pinMode(pinLDR, INPUT);
  pinMode(pinBtn, INPUT_PULLUP);
  pinMode(pinBuz, OUTPUT);
  pinMode(pinLED, OUTPUT);
  lcd.init();

  lcd.print("Keamanan LDR");
  lcd.setCursor(0,1);
  lcd.print("By: Raditya Ari");
  
  delay(2000);
  lcd.clear();
}

void loop() {
  String kondisi;
  dataLDR = analogRead(pinLDR);
  int readBtn = digitalRead(pinBtn);
  
  Serial.println("DataLDR : "+String(dataLDR)+", Kondidi button = " + String(stateBtnLast));

  if(readBtn != stateBtn){
    stateBtn = readBtn;
    if(stateBtn == LOW){
      stateBtnLast = !stateBtnLast;
    }
  }
  
  kondisi = cekKondisi(dataLDR);
  displayLCD(kondisi);
   
  if(kondisi == "AMAN"){
    stateBtnLast = LOW;
  }
  else if(stateBtnLast == HIGH){
    stateBuzzerLast = LOW;
  }
  else{
    stateBuzzerLast = HIGH;
  }

  setBuzzer(stateBuzzerLast); 
}

String cekKondisi(int ldr){
  if(dataLDR < 250) return "AMAN";
  else return "ADA MALING!!";
}

// untuk display lcd
void displayLCD(String kon){
  lcd.setCursor(0,0);
  lcd.print(String(kon)+"          ");
}

// on off buzzer dan led
void setBuzzer(bool i){
  digitalWrite(pinBuz, i);
  if(i == HIGH){
    digitalWrite(pinLED, HIGH);
    delay(100);
    digitalWrite(pinLED, LOW);
    delay(100);
  }else{
    digitalWrite(pinLED, LOW);
    delay(1000);
  }
}
