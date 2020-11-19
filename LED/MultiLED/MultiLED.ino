// deklarasi pin
int pinLed1 = 2;
int pinLed2 = 3;
int pinLed3 = 4;

void setup() {
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
}

void loop() {
  digitalWrite(pinLed1, HIGH);
  digitalWrite(pinLed2, LOW);
  digitalWrite(pinLed3, LOW);
  delay(100);
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, HIGH);
  digitalWrite(pinLed3, LOW);
  delay(100);
  digitalWrite(pinLed1, LOW);
  digitalWrite(pinLed2, LOW);
  digitalWrite(pinLed3, HIGH);
  delay(100);
}
