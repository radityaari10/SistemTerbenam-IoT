#include <NewPing.h>
#include <LiquidCrystal_I2C.h>

#define trigPin 12
#define echoPin 13
#define MAX_DISTANCE 200

NewPing sonar(trigPin, echoPin, MAX_DISTANCE);
LiquidCrystal_I2C lcd(0x20, 16, 2);

void setup() {
  Serial.begin(115200);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0,0);
  lcd.print("Tinggi Badan");
  lcd.setCursor(0,1);
  lcd.print("By : Raditya Ari");
  delay(2000);
  lcd.clear();
  lcd.print("Tinggi Badan");
  Serial.println("By : Raditya Ari");
}

void loop() {
  float jarak;
  jarak = sonar.ping_cm(); 
  Serial.print(jarak);
  Serial.println(" cm");

  lcd.setCursor(0,1);
  lcd.print("= "+String(jarak)+" cm    ");
  delay(450);
}
