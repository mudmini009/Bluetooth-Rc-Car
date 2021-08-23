//  Name:Bluetooth RC Car
//  Creater : Mudmini009
//  Version : 0.0.0.2
//  Github : https://github.com/mudmini009
//  YT Channel : https://www.youtube.com/c/mudmini009
//  YT of this project : https://www.youtube.com/playlist?list=PLeU8oAN7TPL4pmXV9D7riUzINxAzCTm_b
int speed=255;
#include<SoftwareSerial.h>
SoftwareSerial BTSerial(14,15);
//details front wheel written 3 front 5 back rear wheel written 8 left 7 right
int PWMA = 6; //Speed control 
int AIN1 = 3; //Direction
int AIN2 = 5; //Direction
int STBY = 2; 

//Motor B
int PWMB = 7; //Speed control
int BIN1 = 8; //Direction
int BIN2 = 9; //Direction
void font() {
  digitalWrite(AIN1, HIGH);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, speed);
}
 void back() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, HIGH);
  analogWrite(PWMA, speed); 
} void nomove() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, speed);
} void left() {
  digitalWrite(BIN1, HIGH);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 255); 
} void right() {
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, HIGH);
  analogWrite(PWMB, 255);
} void noturn() {
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, speed); 
}
void stopnow() {
  digitalWrite(AIN1, LOW);
  digitalWrite(AIN2, LOW);
  analogWrite(PWMA, 0);
  digitalWrite(BIN1, LOW);
  digitalWrite(BIN2, LOW);
  analogWrite(PWMB, 0); 
}

void setup(){
pinMode(STBY, OUTPUT);
pinMode(PWMA, OUTPUT);
pinMode(AIN1, OUTPUT);
pinMode(AIN2, OUTPUT);
pinMode(PWMB, OUTPUT);
pinMode(BIN1, OUTPUT);
pinMode(BIN2, OUTPUT);
Serial.begin(9600);
    BTSerial.begin(9600);
  }  

void loop() {
    digitalWrite(STBY, HIGH);

  if(BTSerial.available()>0)
  {  
  char Control=BTSerial.read();
  Serial.println(Control);
  
  if(Control=='F'){font();
 Serial.println("font");
  }
  if(Control=='B'){back();
  }
  if(Control=='S'){nomove();
  }
  if(Control=='L'){left();
  }
  if(Control=='R'){right();
  }
  if(Control=='N'){noturn();
  }
  if(Control=='Q'){
    font();
    left();
  }
  if(Control=='E'){
    font();
    right();
  }
  if(Control=='Z'){
    back();
    left();
  }
  if(Control=='C'){
    back();
    right();
  }
  if(Control=='P'){
    stopnow(); 
  }
  if(Control=='1'){
    speed=100;
  }
   if(Control=='2'){
    speed=150;
  }
  if(Control=='3'){
    speed=200;
  }
  if(Control=='4'){
    speed=255;
  }
}
}

