#include <NewPing.h>
#include <Servo.h>

#define trigPin 12
#define echoPin 13
#define MAX_DISTANCE 200

NewPing sonar(trigPin, echoPin, MAX_DISTANCE);
Servo myservo;

int LEDhijau = 3;
int LEDmerah = 2;

void setup() {
  Serial.begin(115200);
//  pinMode(trigPin, OUTPUT);
//  pinMode(echoPin, INPUT);
  pinMode(LEDhijau, OUTPUT);
  pinMode(LEDmerah, OUTPUT);
  myservo.attach(10);
  Serial.println("By : Raditya Ari");
}

void loop() {
//  int duration, jarak, posisi = 0, i;
  int jarak;
//  digitalWrite(trigPin, LOW);
//  delayMicroseconds(2);
//  digitalWrite(trigPin, HIGH);
//  delayMicroseconds(10);
//  digitalWrite(trigPin, LOW);
//  duration = pulseIn(echoPin, HIGH);
  jarak = sonar.ping_cm(); //(duration/2) / 29.1; // distance = duration/58.2
  Serial.print(jarak);
  Serial.println(" cm");

  if(jarak<=15){
    digitalWrite(LEDhijau, LOW);
    digitalWrite(LEDmerah, HIGH);
    myservo.write(180); // 1
    delay(450);
    digitalWrite(LEDmerah, LOW);
    myservo.write(90);
    delay(450);
    digitalWrite(LEDmerah, HIGH);
    myservo.write(0);
    delay(450);
    digitalWrite(LEDmerah, LOW);
    myservo.write(90);
  }else{
    digitalWrite(LEDmerah, LOW);
    digitalWrite(LEDhijau, HIGH);
    myservo.write(90);
  }
  delay(450);
}
