#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16,2);

#define segments 7 // banyaknya segment
#define digits 4 // banyaknya digit

int pinSegments[] = {8,7,6,5,4,3,2}; // pin segment
int pinDigits[] = {12,11,10,13}; // pin digit

int analogInPin = A0;
int analogOutPin =9;

int sensorValue = 0;
int outputValue = 0;

void setup() {
  Serial.begin(9600);
  // lcd
  lcd.init();
  lcd.backlight();
  //pin segment mode OUTPUT
  for(int x = 0; x<segments; x++){
     pinMode(pinSegments[x], OUTPUT);
     Serial.println("Seg "+ String(x) +" OKE");
  }

  // pin digit mode output
  for(int x = 0; x<digits; x++){
     pinMode(pinDigits[x], OUTPUT);
     Serial.println("d "+ String(x) +" OKE");
  }

  lcd.print("Percobaan 2");
  lcd.setCursor(0,1);
  lcd.print("By: Raditya Ari");
  number(0,0,0,0,0,0,1);
  delay(2000);
  clearDigits();
  lcd.clear();
}

void loop() {
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue , 0, 1023, 0, 255);
  analogWrite(analogOutPin, outputValue);
  
  setDisplay(outputValue); // pada multi 7segments  
  lcd.clear();
  lcd.print(outputValue); // pada lcd 16x2
  
  // pada virtual terminal/serial monitor
  Serial.print("Nilai Potensio = "+ String(sensorValue));
  Serial.println(", Nilai Output = "+ String(outputValue));
  
  delay(2);
}

// set digit HIGH == tidak dapat ditulis
void clearDigits(){
  for(int x=0; x<4;x++){
    digitalWrite(x, HIGH);
  }
}

// untuk set high dan low segment
void number(int aa, int bb, int cc, int dd, int ee,int ff, int gg){
  digitalWrite(pinSegments[0], aa);
  digitalWrite(pinSegments[1], bb);
  digitalWrite(pinSegments[2], cc);
  digitalWrite(pinSegments[3], dd);
  digitalWrite(pinSegments[4], ee);
  digitalWrite(pinSegments[5], ff);
  digitalWrite(pinSegments[6], gg);
}

// untuk memilih angka 0-9
void pickNumber(int i){
  switch(i){
    case 0:
      number(1,1,1,1,1,1,0);
      break;
    case 1:
      number(0,1,1,0,0,0,0);
      break;
    case 2:
      number(1,1,0,1,1,0,1);
      break;
    case 3:
      number(1,1,1,1,0,0,1);
      break;
    case 4:
      number(0,1,1,0,0,1,1);
      break;
    case 5:
      number(1,0,1,1,0,1,1);
      break;
    case 6:
      number(1,0,1,1,1,1,1);
      break;
    case 7:
      number(1,1,1,0,0,0,0);
      break;
    case 8:
      number(1,1,1,1,1,1,1);
      break;
    case 9:
      number(1,1,1,1,0,1,1);
      break;
  }
}

// untuk menulis digit
void dgt(int d){
  digitalWrite(pinDigits[d], LOW);
  delay(5);
  digitalWrite(pinDigits[d], HIGH);
}

// untuk set display multi 7segments
void setDisplay(int potensio){
  pickNumber(potensio/1000);
  dgt(0);
  pickNumber((potensio/100) % 10);
  dgt(1);
  pickNumber((potensio/10) % 10);
  dgt(2);
  pickNumber(potensio % 10);
  dgt(3);
}
