int pinButton = 2;
int pinLed = 13;

int stateLed = LOW;
int stateBtn;
//int stateBtnLast = HIGH;

void setup() {
  pinMode(pinButton, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);

  digitalWrite(pinLed, stateLed);
}

void loop() {
  int readBtn = digitalRead(pinButton);

  if(readBtn != stateBtn){
    stateBtn = readBtn;
    if(stateBtn == LOW){
      stateLed = !stateLed;
    }
  }

  digitalWrite(pinLed, stateLed);
//  stateBtnLast = readBtn;
}
