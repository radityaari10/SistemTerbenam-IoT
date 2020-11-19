int pinLed2 = 2;

void setup() {
  pinMode(pinLed2, OUTPUT);
}

void loop() {
  // S
  bip(200);
  bip(200);
  bip(200);
  delay(1000);
  // O
  bip(500);
  bip(500);
  bip(500);
  delay(700);
  // S
  bip(200);
  bip(200);
  bip(200);
  delay(3000);
}

void bip(int interval){
  digitalWrite(pinLed2, HIGH);
  delay(interval);
  digitalWrite(pinLed2, LOW);
  delay(interval);
}
