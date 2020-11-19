// segments
int a = 1; //a
int b = 2; 
int c = 3; 
int d = 4; 
int e = 5; 
int f = 6; 
int g = 7; 
int p = 8; //p

// digits
int d4 = 12;
int d3 = 11;
int d2 = 10;
int d1 = 9;

// other
#define input A0 
int count = 0;
int cur;

void setup() {
  pinMode(d1, OUTPUT);
  pinMode(d2, OUTPUT);
  pinMode(d3, OUTPUT);
  pinMode(d4, OUTPUT);
  pinMode(a, OUTPUT);
  pinMode(b, OUTPUT);
  pinMode(c, OUTPUT);
  pinMode(d, OUTPUT);
  pinMode(e, OUTPUT);
  pinMode(f, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(p, OUTPUT);
  pinMode(input, INPUT_PULLUP);
  number(1,1,1,1,1,1,0);
  clearLEDs();

  TCCR1A = 0;
  TCCR1B = 1;
  TCNT1 = 0;
  TIMSK1 = 1;
}

ISR(TIMER1_OVF_vect){
  clearLEDs();
  pickDigit(cur);
  cur = (cur %4) +1;
}

void loop() {
  if(digitalRead(input)==LOW){
    count++;
    if(count > 9999){
      count = 0;
    }
    delay(500);
  }
}

void pickDigit(int x){
  switch(x){
    case 1:
      setNum(count/1000);
      digitalWrite(d1, HIGH);
      break;
    case 2:
      setNum((count/100) % 10);
      digitalWrite(d2, HIGH);
      break;
    case 3:
      setNum((count/10) % 10);
      digitalWrite(d3, HIGH);
      break;
    default:
      setNum(count % 10);
      digitalWrite(d4, HIGH);
      break;
  }
}

void clearLEDs(){
  digitalWrite(d1, LOW);
  digitalWrite(d2, LOW);
  digitalWrite(d3, LOW);
  digitalWrite(d4, LOW);
}

void number(int aa, int bb, int cc, int dd, int ee, int ff, int gg){
  // segment aktif low
  digitalWrite(a, !aa);
  digitalWrite(b, !bb);
  digitalWrite(c, !cc);
  digitalWrite(d, !dd);
  digitalWrite(e, !ee);
  digitalWrite(f, !ff);
  digitalWrite(g, !gg);
  digitalWrite(p, 1);
}

void setNum(int x){
  switch(x){
    case 0:
      number(1,1,1,1,1,1,0);
      break;
    case 1:
      number(0,1,1,0,0,0,0);
      break;
    case 2:
      number(1,1,0,1,1,0,1);
      break;
    case 3:
      number(1,1,1,1,0,0,1);
      break;
    case 4:
      number(0,1,1,0,0,1,1);
      break;
    case 5:
      number(1,0,1,1,0,1,1);
      break;
    case 6:
      number(1,0,1,1,1,1,1);
      break;
    case 7:
      number(1,1,1,0,0,0,0);
      break;
    case 8:
      number(1,1,1,1,1,1,1);
      break;
    case 9:
      number(1,1,1,1,0,1,1);
      break;
  }
}
