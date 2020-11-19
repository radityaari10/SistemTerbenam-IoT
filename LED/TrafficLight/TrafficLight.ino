int pinLed2 = 2;
int pinLed3 = 3;
int pinLed4 = 4;
int pinLed5 = 5;
int pinLed6 = 6;
int pinLed7 = 7;

void setup() {
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinLed4, OUTPUT);
  pinMode(pinLed5, OUTPUT);
  pinMode(pinLed6, OUTPUT);
  pinMode(pinLed7, OUTPUT);
}

void loop() {
  // timur-barat hijau
  setOFF();
  digitalWrite(pinLed2, HIGH);
  digitalWrite(pinLed7, HIGH);
  delay(7000);
  // timur-barat kuning
  setOFF();
  digitalWrite(pinLed3, HIGH);
  digitalWrite(pinLed7, HIGH);
  delay(3000);
  // timur-barat merah, utara-selatan kuning
  setOFF();
  digitalWrite(pinLed4,HIGH);
  digitalWrite(pinLed6, HIGH);
  delay(2000);
  // timur-barat merah, utara-selatan hijau
  setOFF();
  digitalWrite(pinLed4, HIGH);
  digitalWrite(pinLed5, HIGH);
  delay(7000);
  // utara-selatan kuning
  setOFF();
  digitalWrite(pinLed6, HIGH);
  digitalWrite(pinLed4, HIGH);
  delay(3000);
  // utara-selatan merah, timur-barat kuning
  setOFF();
  digitalWrite(pinLed7,HIGH);
  digitalWrite(pinLed3, HIGH);
  delay(2000);
}

void setOFF(){
  digitalWrite(pinLed2, LOW);
  digitalWrite(pinLed3, LOW);
  digitalWrite(pinLed4, LOW);
  digitalWrite(pinLed5, LOW);
  digitalWrite(pinLed6, LOW);
  digitalWrite(pinLed7, LOW);
}
