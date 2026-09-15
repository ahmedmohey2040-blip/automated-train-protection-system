#include <NewPing.h> // Ultra Sonice Library

//Ultra Sonice Pins
int trig = 11 ; 
int echo = 10 ; 
int max_dis = 200 ;
NewPing sonic (trig , echo , max_dis);
//H-bridge Pins
#define IN1 2
#define IN2 3
#define enA 5

#define Green_Led 6
#define Yellow_Led 7
#define Red_Led 8

//Buzzel Pin
#define Buzzel 4

void setup() {

  Serial.begin(9600);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(Buzzel, OUTPUT);

    pinMode(Green_Led, OUTPUT);
  pinMode(Red_Led, OUTPUT);
  pinMode(Yellow_Led, OUTPUT);
}

void loop() {

  int us = sonic.ping();
  int dis = us / US_ROUNDTRIP_CM ;
  Serial.print("Distance :"); 
  Serial.println(dis); 

if(dis <= 15 ){

 digitalWrite(IN1, 0);
 digitalWrite(IN2, 1);
 analogWrite(enA, 0);
 digitalWrite(Buzzel, 1);
 digitalWrite(Red_Led, 1);
  digitalWrite(Yellow_Led, 1);
   digitalWrite(Green_Led, 0);

}else if(dis > 15){

 digitalWrite(IN1, 0);
 digitalWrite(IN2, 1);
 analogWrite(enA, 215);
 digitalWrite(Buzzel, 0);
  digitalWrite(Red_Led, 1);
  digitalWrite(Yellow_Led, 0);
   digitalWrite(Green_Led, 1);

}

if(dis == 0){   digitalWrite(Yellow_Led, 0);
   digitalWrite(Green_Led, 0);
    digitalWrite(Buzzel, 0);
     digitalWrite(Buzzel, 0);
      digitalWrite(IN1, 0);
 digitalWrite(IN2, 1);
 analogWrite(enA, 215);

}


}
