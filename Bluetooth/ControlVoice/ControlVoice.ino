String state;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);  
  Serial.println("Start");
}

void loop() {
  while(Serial.available()){
    delay(10);
    char c = Serial.read();
    state += c;
  }
  if(state.length()>0){
    if(state == "turn on"){
      digitalWrite(13, HIGH);
      state = "";
    }
    if(state == "turn off"){
      digitalWrite(13, LOW);
      state = "";
    }
  }
}
