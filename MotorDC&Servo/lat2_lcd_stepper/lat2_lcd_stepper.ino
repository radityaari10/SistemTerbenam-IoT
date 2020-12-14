#include <Stepper.h>
#include <LiquidCrystal_I2C.h>

#define STEPS 200
#define button 3
 
Stepper stepper(STEPS, 4, 5, 6, 7);
LiquidCrystal_I2C lcd(0x20, 16, 2);  

void setup()
{
  Serial.begin(9600);
  lcd.init();
  stepper.setSpeed(60);
  pinMode(button, INPUT_PULLUP);

  lcd.print("By : Raditya Ari");
  delay(2000);
  lcd.clear();
}
 
int direction_ = 0, stepValue;
float derajat;

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("Step : " + String(stepValue)+"   ");
  lcd.setCursor(0,1);
  lcd.print("Derajat : " + String(derajat)+"   ");
  int readBtn = digitalRead(button);
  if ( readBtn == 0 ){
    if ( debounce() )  
    {
      if(direction_ != 1){
        direction_ = 1;
      }else{
        direction_ = 0;
      }
      while ( debounce() );
    }
    Serial.println(String(direction_));
  }
  
  if(direction_){
    stepValue++;
    if(stepValue > 200) stepValue = 0;
  }
  derajat = stepValue*1.8;
  stepper.step(direction_);
}

bool debounce()
{
  byte count = 0;
  for(byte i = 0; i < 5; i++) {
    if (digitalRead(button) == 0)
      count++;
    delay(10);
  }
  if(count > 2)  return 1;
  else           return 0;
}
