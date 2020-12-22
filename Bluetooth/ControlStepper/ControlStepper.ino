#include <Stepper.h>
 
#define STEPS 50
 
Stepper stepper(STEPS, 4, 5, 6, 7);
int state;

void setup() {
  Serial.begin(9600);
  stepper.setSpeed(60);
}

void loop() {
  if(Serial.available() > 0){
    state = Serial.read();
  }

  if(state  == '0'){
    stepper.step(1);
  }
  if(state  == '1'){
    stepper.step(-1);
  }
  if(state  == '2'){
    stepper.step(0);
  }
}
