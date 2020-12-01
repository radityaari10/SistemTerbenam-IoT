int analogInPin = A0;
int sensorValue = 0;
int outputValue = 0;
#define ledS 6

int pinLEDs[] = {6,5,4,3,2};

void setup() {
  Serial.begin(9600);

  // set mode pinLed
  for(int i=0; i < ledS; i++){
    pinMode(pinLEDs[i], OUTPUT);
    Serial.println("Led " + String(i+1) + " OUTPUT");
  }
}

void loop() {
  sensorValue = analogRead(analogInPin);
  outputValue = map(sensorValue, 0, 1023, 0, 4); // menghasilkan 5 kondisi (0,1,2,3,4)

  Serial.println("Nilai Mapping = "+ String(outputValue));

  for(int x=0; x<=outputValue; x++){
    if(sensorValue == 0){
      ledOn(-1);
      Serial.println("Nilai sensor = 0");
      delay(1000);
    }
    else{
      ledOn(outputValue);
    }
  }
  delay(1000);
}

// untuk menyalkan lampu
void ledOn(int i){
  ledOff(0);
  for(int x=0; x<=i; x++){
    digitalWrite(pinLEDs[x], HIGH);
  }
  Serial.println("Kondisi "+String(i+1));
}

// matikan led
void ledOff(int i){
  for(int x=4; x>=i; x--){
    digitalWrite(pinLEDs[x], LOW);
  }
}
