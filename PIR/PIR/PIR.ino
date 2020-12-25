#include <Servo.h>
#define pirPin 2

Servo myservo;

int calibrationTime = 30;
boolean state = true;

void setup()
{
  Serial.begin(9600);
  pinMode(pirPin, INPUT);
  myservo.attach(3);
  Serial.println("start");
}

void loop()
{
  PIRSensor();
}

void PIRSensor()
{
  if(digitalRead(pirPin) == HIGH)
  {
    if(state)
    {
      state = false;
      Serial.println("Motion Detected.");
    }
    myservo.write(180);
    delay(400);
    myservo.write(0);
    delay(450);
    myservo.write(180);
    delay(50);
  }

  if(digitalRead(pirPin) == LOW)
  {
    if(!state)
    {
      state = true;
      Serial.println("Motion Ended.");
      myservo.write(180);
      delay(50);
    }
  }
}
