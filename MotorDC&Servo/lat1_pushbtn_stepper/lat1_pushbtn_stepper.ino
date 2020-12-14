#include <Stepper.h>
 
#define STEPS 50
 
Stepper stepper(STEPS, 4, 5, 6, 7);
 
const int button =  3; 

void setup()
{
  Serial.begin(9600);
  stepper.setSpeed(10);
  pinMode(button, INPUT_PULLUP);
}
 
int speed_ = 0;
bool direction_ = LOW;

void loop()
{
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
