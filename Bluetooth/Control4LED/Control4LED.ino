int state;
#define LEDs 4

int pinLEDs[] = {13,12,11,10};

void setup() {
  Serial.begin(9600);
  for(int x=0; x<LEDs; x++){
    pinMode(pinLEDs[x], OUTPUT);  
  }
}

void loop() {
  if(Serial.available() > 0){
    state = Serial.read();
  }

  setON(state);
  setOFF(state);
}

void setON(int a){
  if(a == '0'){
    digitalWrite(pinLEDs[0], HIGH);
    state = 0;
  }
  if(a == '1'){
    digitalWrite(pinLEDs[1], HIGH);
    state = 0;
  }
  if(a == '2'){
    digitalWrite(pinLEDs[2], HIGH);
    state = 0;
  }
  if(a == '3'){
    digitalWrite(pinLEDs[3], HIGH);
    state = 0;
  }
}

void setOFF(int a){
    if(a == '4'){
      digitalWrite(pinLEDs[0], LOW);
      state = 0;
    }
    if(a == '5'){
      digitalWrite(pinLEDs[1], LOW);
      state = 0;
    }
    if(a == '6'){
      digitalWrite(pinLEDs[2], LOW);
      state = 0;
    }
    if(a == '7'){
      digitalWrite(pinLEDs[3], LOW);
      state = 0;
    }
}
