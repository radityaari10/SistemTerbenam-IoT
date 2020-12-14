#include <Stepper.h>
 
#define STEPS 50
 
Stepper stepper(STEPS, 4, 5, 6, 7);
 
#define btn 2
const int button[] =  {2,3}; // kiri, kanan 

void setup()
{
  Serial.begin(9600);
  stepper.setSpeed(60);
  for(int x=0; x<btn; x++){
    pinMode(button[x], INPUT_PULLUP); 
  }
}
 
int speed_ = 0;
int direction_;

void loop()
{
  if ( digitalRead(button[0]) == 0 ){
    if ( debounce(0) ){
      direction_ = 1;
      while ( debounce(0) );
    }
    Serial.println(String(direction_));
  }
  
  if ( digitalRead(button[1]) == 0 ){
    if ( debounce(1) ){
      direction_ = -1;
      while ( debounce(1) );
    }
    Serial.println(String(direction_));
  }
  
  stepper.step(direction_);
}
 
bool debounce(int x)
{
  byte count = 0;
  for(byte i = 0; i < 5; i++) {
    if (digitalRead(button[x]) == 0)
      count++;
    delay(10);
  }
  if(count > 2)  return 1;
  else           return 0;
}
