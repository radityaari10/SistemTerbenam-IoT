#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16,2);

int analogInPin = A0;
int sensorValue = 0;
int outputValue = 0;

int pinBtn = 12;
int pinBuzzer = 13;

int stateBtn, stateSensor;
int stateBtnLast=LOW;
int stateBuzzerLast = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(pinBtn, INPUT_PULLUP);
  pinMode(pinBuzzer, OUTPUT);
  // lcd
  lcd.init();
  lcd.backlight();

  lcd.print("Akses Potensio");
  lcd.setCursor(0,1);
  lcd.print("By: Raditya Ari");
  
  delay(2000);
  lcd.clear();
}

void loop() {
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue , 0, 1023, 0, 255);

  int readBtn = digitalRead(pinBtn);
  int readSensor = sensorValue;

  if(readBtn != stateBtn){
    stateBtn = readBtn;
    if(stateBtn == LOW){
      stateBtnLast = !stateBtnLast;
    }
    // serial monitor
    Serial.println("Kondidi button = " + String(stateBtnLast));
  }

  // jika potensio terdapat nilai
  if(readSensor > 0){
    if(stateBtnLast != HIGH){
      stateBuzzerLast = HIGH;
      displayAkses();
    }
    else{
      displayADC();
      stateBuzzerLast = LOW;
      Serial.println("ADC = "+String(outputValue));
    }
    setBuzzer(stateBuzzerLast);
  }

  // jika potensio 0
  else if(readSensor == 0){
    stateBuzzerLast = LOW;
    // jika kondisi pin btn HIGH
    if(stateBtnLast == HIGH){
      lcd.clear();
      lcd.print("Anda punya akses");
    }
    // jika kondisi pin btn LOW
    else{
      displayAkses();
    }
    setBuzzer(stateBuzzerLast);
  }

  delay(500);
}

// untuk onOff Buzzer
void setBuzzer(bool i){
  digitalWrite(pinBuzzer, i);
}

// untuk menampilkan nilai ADC pada lcd
void displayADC(){
  lcd.clear();
  lcd.print("Nilai ADC = "+String(outputValue));
  Serial.println("Nilai ADC = "+String(outputValue));
}

// untuk menampilkan tidak punya akses
void displayAkses(){
  lcd.clear();
  lcd.print("Anda tidak punya akses");
  delay(200);
  for(int c=0; c<6;c++){
    lcd.scrollDisplayLeft(); // menggeser tampilan lcd ke kiri
    delay(100);
  }
}
