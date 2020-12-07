#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x20, 16, 2);

int pinLM = A0;
int pinLDR = A1;
int pinBuz = 10;

int dataLDR = 0, suhuHasil;
float suhu, dataLM;

#define LEDs 3
int pinLEDs[] = {13,12,11}; // YGR

void setup() {
  Serial.begin(9600);
  pinMode(pinLM, INPUT);
  pinMode(pinLDR, INPUT);
  pinMode(pinBuz, OUTPUT);

  for(int x=0; x<LEDs; x++){
    pinMode(pinLEDs[x], OUTPUT);
    Serial.println("pinLed "+String(x+1)+" mode Output");
  }
  lcd.init();

  lcd.print("Perkiraan Cuaca");
  lcd.setCursor(0,1);
  lcd.print("By: Raditya Ari");
  
  delay(2000);
  lcd.clear();
}

void loop() {
  String kondisi;
  dataLM = analogRead(pinLM);
  suhu = (dataLM * 500) / 1024;
  int suhuDes = suhu;
  dataLDR = analogRead(pinLDR);
  if(suhu-suhuDes > 0.49){
    suhuHasil = suhuDes+1;
  }else{
    suhuHasil = suhuDes;
  }
  Serial.println("DataLM35 : "+String(dataLM) +", suhu : "+ String(suhuHasil));
  Serial.println("DataLDR : "+String(dataLDR));
  
  lcd.setCursor(0,0);
  lcd.print("sh : " +String(suhuHasil)+ ", lm : "+String(dataLM)+"  ");
  kondisi = cekKondisi(suhuHasil, dataLDR);
  
  displayLCD(kondisi);
  lampuLed(kondisi);
  delay(1000);
}

String cekKondisi(int sh, int ldr){
  if((sh <= 19) && (ldr < 200)) return "Dingin";
  else if((sh <= 23) && (ldr < 200)) return "Hujan";
  else if((sh <= 25) && (ldr < 200)) return "Mendung";
  else if((sh >= 30) && (ldr > 500)) return "Panas";
  else if((sh >= 25) && (ldr > 300)) return "Cerah";
  else return "Membaca Data";
}

// untuk display lcd
void displayLCD(String kon){
  lcd.setCursor(0,1);
  lcd.print(String(kon)+"          ");
}


void lampuLed(String kon){
  offLed();
  if(kon == "Cerah" || kon == "Panas") 
    digitalWrite(pinLEDs[1], HIGH);
  else if(kon == "Mendung" || kon == "Dingin") 
    digitalWrite(pinLEDs[0], HIGH);
  else if(kon == "Hujan"){
    digitalWrite(pinLEDs[2], HIGH);
    digitalWrite(pinBuz, HIGH);
  }
  else offLed();
}

void offLed(){
  digitalWrite(pinBuz, LOW);
  for(int x=0; x<LEDs; x++){
    digitalWrite(pinLEDs[x], LOW);
  }
}
