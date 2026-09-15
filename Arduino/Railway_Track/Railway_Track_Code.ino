//Flasher
unsigned long interval_1 = 150;
unsigned long interval_2 = 300; 
unsigned long previousTime_1 = 0;
unsigned long previousTime_2 = 0;

//IR Sensors Pins 
#define Sensor1 2
#define Sensor2 3
#define Sensor3 4
#define Sensor4 5
#define Sensor5 6
#define Sensor6 7

//H-bridge Mazlakan Pins
#define IN1 8
#define IN2 9
#define enA 10

#define Mazlakan_LED1 29
#define Mazlakan_LED2 30
#define Mazlakan_Buzzel 31

#define Limit_Switch_1 11
#define Limit_Switch_2 12

//Station Pins
#define LED1 13
#define LED2 14
#define Buzzel 15

//##################################//
//          Semafors Pins
//*********************************//
//Semafor 1
#define Semafor1_Green 16
#define Semafor1_Yellow 17
#define Semafor1_Red 18

//Semafor 2
#define Semafor2_Green 19
#define Semafor2_Yellow 20
#define Semafor2_Red 21

//Semafor 3
#define Semafor3_Green 42
#define Semafor3_Yellow 43
#define Semafor3_Red 44
#define Semafor3_Mazlakan 45

//Semafor 4
#define Semafor4_Green 26
#define Semafor4_Yellow 27
#define Semafor4_Red 28

//Read Sensors Var
int sensor1 ;
int sensor2 ;
int sensor3 ;
int sensor4 ;
int sensor5 ;
int sensor6 ;

int limit_switch1 ;
int limit_switch2 ;


// ON or OFF Var
bool s1 = true ;
bool s2 = false;
bool s3 = false;
bool s4 = false;
bool s5 = false;
bool s6 = false;

bool start    = true ;
bool semafor1 = false;
bool semafor2 = false;
bool semafor3 = false;
bool semafor4 = false;
bool set      = false;

bool locked1 = false;
bool locked2 = false;

bool switch_case = false;

void setup() {

Serial.begin(9600);

//Input Pins Mods
pinMode(Sensor1,INPUT);
pinMode(Sensor2,INPUT);
pinMode(Sensor3,INPUT);
pinMode(Sensor4,INPUT);
pinMode(Sensor5,INPUT);
pinMode(Sensor6,INPUT);

pinMode(Limit_Switch_1,INPUT_PULLUP);
pinMode(Limit_Switch_2,INPUT_PULLUP);

//Output Pins Mods
pinMode(IN1,OUTPUT);
pinMode(IN2,OUTPUT);
pinMode(enA,OUTPUT);

pinMode(Mazlakan_LED1,OUTPUT);
pinMode(Mazlakan_LED2,OUTPUT);
pinMode(Mazlakan_Buzzel,OUTPUT);

//Station
pinMode(LED1,OUTPUT);
pinMode(LED2,OUTPUT);
pinMode(Buzzel,OUTPUT);


// Semafor 1
pinMode(Semafor1_Green,OUTPUT);
pinMode(Semafor1_Yellow,OUTPUT);
pinMode(Semafor1_Red,OUTPUT);

//Semafor 2
pinMode(Semafor2_Green,OUTPUT);
pinMode(Semafor2_Yellow,OUTPUT);
pinMode(Semafor2_Red,OUTPUT);

//Semafor 3
pinMode(Semafor3_Green,OUTPUT);
pinMode(Semafor3_Yellow,OUTPUT);
pinMode(Semafor3_Red,OUTPUT);
pinMode(Semafor3_Mazlakan,OUTPUT);

//Semafor 4
pinMode(Semafor4_Green,OUTPUT);
pinMode(Semafor4_Yellow,OUTPUT);
pinMode(Semafor4_Red,OUTPUT);

digitalWrite(Semafor3_Green, 0);
digitalWrite(Semafor3_Yellow, 0);
digitalWrite(Semafor3_Red, 1);
digitalWrite(Semafor3_Mazlakan,1);

digitalWrite(IN1,1);// down
digitalWrite(IN2,0);// up
analogWrite(enA,75);
}





void loop() {

Read_Print(); // IR & Limit Switch Read Values and Printing
if(limit_switch1 == 1){ locked1 = true;} if(limit_switch1 == 0){ locked1 = false;}
if(limit_switch2 == 1){ locked2 = true;} if(limit_switch2 == 0){ locked2 = false;}



if(sensor1 == 0 && s1 == true){start =false; semafor1 =true;  s2 = true; s1 = false;}
if(sensor2 == 0 && s2 == true){semafor1 =false; semafor2 =true; s3 = true; s2 = false;}
if(sensor3 == 0 && s3 == true){semafor2 =false; set = true; s4 = true ;  s3 = false;}
if(sensor4 == 0 && s4 == true){set = false; semafor3 = true; s5 = true ; switch_case = true ; s4 = false; }
if(sensor5 == 0 && s5 == true){semafor3 = false; semafor4 = true; s6 = true; s5 = false;}
if(sensor6 == 0 && s6 == true){semafor4 = false; start = true ; s1 = true ; s6 = false ;}



if(start == true){Start();}
if(semafor1 == true){Semafor1_Case();}
if(semafor2 == true){Semafor2_Case();}
if(   set   == true){Set();}
if(semafor3 == true){Semafor3_Case();}
if(semafor4 == true){Semafor4_Case();}

/*
if(locked1 == false || locked2 == false){
digitalWrite(Semafor3_Green, 0);
digitalWrite(Semafor3_Yellow, 0);
digitalWrite(Semafor3_Red, 1);
digitalWrite(Semafor3_Mazlakan,1);

}else if(locked1 && locked2 == true){

if(switch_case == false){
digitalWrite(Semafor3_Green, 1);
digitalWrite(Semafor3_Yellow, 0);
digitalWrite(Semafor3_Red, 0);
digitalWrite(Semafor3_Mazlakan,0);
}else if(switch_case == true) {
digitalWrite(Semafor3_Green, 0);
digitalWrite(Semafor3_Yellow, 0);
digitalWrite(Semafor3_Red, 1);
digitalWrite(Semafor3_Mazlakan,0);
}

}*/

}// End of Loop()



//###################################################### Funcation #####################################################################################//

//Start Case
void Start(){

digitalWrite(IN1,1);// down
digitalWrite(IN2,0);// up
analogWrite(enA,0);

digitalWrite(LED1, 0);
digitalWrite(LED2, 0);
digitalWrite(Buzzel,0);

digitalWrite(Mazlakan_LED1, 0);
digitalWrite(Mazlakan_LED2, 0);
digitalWrite(Mazlakan_Buzzel,0);

digitalWrite(Semafor1_Green, 1);
digitalWrite(Semafor1_Yellow, 0);
digitalWrite(Semafor1_Red, 0);

Flasher(Semafor2_Green);
digitalWrite(Semafor2_Yellow, 0);
digitalWrite(Semafor2_Red, 0);

digitalWrite(Semafor3_Green, 0);
digitalWrite(Semafor3_Yellow, 1);
digitalWrite(Semafor3_Red, 0);

digitalWrite(Semafor4_Green, 0);
digitalWrite(Semafor4_Yellow, 1);
digitalWrite(Semafor4_Red, 0);
switch_case = false ;
}




//if semafor1 sensor is busy
void Semafor1_Case(){

digitalWrite(IN1,1);// down
digitalWrite(IN2,0);// up
analogWrite(enA,0);

digitalWrite(LED1, 0);
digitalWrite(LED2, 0);
digitalWrite(Buzzel,0);

digitalWrite(Mazlakan_LED1, 0);
digitalWrite(Mazlakan_LED2, 0);
digitalWrite(Mazlakan_Buzzel,0);

digitalWrite(Semafor1_Green, 0);
digitalWrite(Semafor1_Yellow, 0);
digitalWrite(Semafor1_Red, 1);

Flasher(Semafor2_Green);
digitalWrite(Semafor2_Yellow, 0);
digitalWrite(Semafor2_Red, 0);

digitalWrite(Semafor3_Green, 0);
digitalWrite(Semafor3_Yellow, 1);
digitalWrite(Semafor3_Red, 0);

digitalWrite(Semafor4_Green, 0);
digitalWrite(Semafor4_Yellow, 1);
digitalWrite(Semafor4_Red, 0);
}




//if semafor2 sensor is busy
void Semafor2_Case(){

digitalWrite(IN1,0);// down
digitalWrite(IN2,1);// up
analogWrite(enA,0);

digitalWrite(LED1, 0);
digitalWrite(LED2, 0);
digitalWrite(Buzzel,0);

Flasher(Mazlakan_LED1);

Flasher(Mazlakan_Buzzel);

digitalWrite(Semafor1_Green, 0);
digitalWrite(Semafor1_Yellow, 0);
digitalWrite(Semafor1_Red, 1);

digitalWrite(Semafor2_Green, 0);
digitalWrite(Semafor2_Yellow, 0);
digitalWrite(Semafor2_Red, 1);


digitalWrite(Semafor3_Green, 0);
digitalWrite(Semafor3_Yellow, 1);
digitalWrite(Semafor3_Red, 0);

digitalWrite(Semafor4_Green, 0);
digitalWrite(Semafor4_Yellow, 1);
digitalWrite(Semafor4_Red, 0);
Flasher(Mazlakan_LED2);
}






//if Sensor 3 is busy
void Set(){

digitalWrite(IN1,0);// down
digitalWrite(IN2,1);// up
analogWrite(enA,75);

digitalWrite(LED1, 0);
digitalWrite(LED2, 0);
digitalWrite(Buzzel,0);

Flasher(Mazlakan_LED1);

Flasher(Mazlakan_Buzzel);

digitalWrite(Semafor1_Green, 0);
digitalWrite(Semafor1_Yellow, 0);
digitalWrite(Semafor1_Red, 1);

digitalWrite(Semafor2_Green, 0);
digitalWrite(Semafor2_Yellow, 0);
digitalWrite(Semafor2_Red, 1);

digitalWrite(Semafor3_Green, 0);
digitalWrite(Semafor3_Yellow, 1);
digitalWrite(Semafor3_Red, 0);

digitalWrite(Semafor4_Green, 0);
digitalWrite(Semafor4_Yellow, 1);
digitalWrite(Semafor4_Red, 0);
Flasher(Mazlakan_LED2);
}





//if Semafor 3 sensor is busy
void Semafor3_Case(){

digitalWrite(IN1,0);// down
digitalWrite(IN2,1);// up
analogWrite(enA,75);

digitalWrite(LED1, 0);
digitalWrite(LED2, 0);
digitalWrite(Buzzel,0);

Flasher(Mazlakan_LED1);

Flasher(Mazlakan_Buzzel);

digitalWrite(Semafor1_Green, 0);
digitalWrite(Semafor1_Yellow, 0);
digitalWrite(Semafor1_Red, 1);

digitalWrite(Semafor2_Green, 0);
digitalWrite(Semafor2_Yellow, 0);
digitalWrite(Semafor2_Red, 1);

digitalWrite(Semafor3_Green, 0);
digitalWrite(Semafor3_Yellow, 0);
digitalWrite(Semafor3_Red, 1);

digitalWrite(Semafor4_Green, 0);
digitalWrite(Semafor4_Yellow, 1);
digitalWrite(Semafor4_Red, 0);
Flasher(Mazlakan_LED2);
}





//if Semafor 4 sensor is busy
void Semafor4_Case(){

digitalWrite(IN1,1);// down
digitalWrite(IN2,0);// up
analogWrite(enA,75);

Flasher(LED1);

Flasher(Buzzel);

digitalWrite(Mazlakan_LED1, 0);
digitalWrite(Mazlakan_LED2, 0);
digitalWrite(Mazlakan_Buzzel, 0);

digitalWrite(Semafor1_Green, 0);
digitalWrite(Semafor1_Yellow, 0);
digitalWrite(Semafor1_Red, 1);

digitalWrite(Semafor2_Green, 0);
digitalWrite(Semafor2_Yellow, 0);
digitalWrite(Semafor2_Red, 1);

digitalWrite(Semafor3_Green, 0);
digitalWrite(Semafor3_Yellow, 0);
digitalWrite(Semafor3_Red, 1);

digitalWrite(Semafor4_Green, 0);
digitalWrite(Semafor4_Yellow, 0);
digitalWrite(Semafor4_Red, 1);
digitalWrite(LED2, 1);
}








void Read_Print(){

sensor1 = digitalRead(Sensor1);
sensor2 = digitalRead(Sensor2);
sensor3 = digitalRead(Sensor3);
sensor4 = digitalRead(Sensor4);
sensor5 = digitalRead(Sensor5);
sensor6 = digitalRead(Sensor6);

limit_switch1 = digitalRead(Limit_Switch_1);
limit_switch2 = digitalRead(Limit_Switch_2);


Serial.print("sensor1 : ");
Serial.print(sensor1);

Serial.print(" sensor2 : ");
Serial.print(sensor2);

Serial.print(" sensor3 : ");
Serial.print(sensor3);

Serial.print(" sensor4 : ");
Serial.print(sensor4);

Serial.print(" sensor5 : ");
Serial.print(sensor5);

Serial.print(" sensor6 : ");
Serial.print(sensor6);



Serial.print(" limit_switch1 : ");
Serial.print(limit_switch1);

Serial.print(" limit_switch2 : ");
Serial.println(limit_switch2);
}





//############### Flasher Funcation #####################
uint8_t Flasher( uint8_t Which_semafor){
unsigned long currentMillis = millis();
if (currentMillis - previousTime_1 >= interval_1){
digitalWrite(Which_semafor, LOW);
previousTime_1 = currentMillis;
}
if (currentMillis - previousTime_2 >= interval_2){
digitalWrite(Which_semafor, HIGH);
previousTime_2 = currentMillis;
}
}
