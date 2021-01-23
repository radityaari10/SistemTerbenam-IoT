#include <LM35.h>

LM35 nilaiSuhu(A1);
char data = 0;

void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  if(Serial.available() > 0){
    data = Serial.read();
    if(data == 'S'){
      float T = nilaiSuhu.cel();
      Serial.println(T);
    }
    else if (data == 'A')
      digitalWrite(3,HIGH);
    else if (data == 'a')
      digitalWrite(3,LOW);
    else if (data == 'B')
      digitalWrite(8,HIGH);
    else if (data == 'b')
      digitalWrite(8,LOW);
    else if (data == 'C')
      digitalWrite(13,HIGH);
    else if (data == 'c')
      digitalWrite(13,LOW);
  }
}
