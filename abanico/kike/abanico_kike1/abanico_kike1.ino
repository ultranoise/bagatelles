                                             
#include <VarSpeedServo.h>

//Servos                             // create variable speed servo objects to control a servos 1-3
  VarSpeedServo servo1;              // Servo to tilt Fan ------------ on digital PIN 11       
  VarSpeedServo servo2;	             // Servo to open and close Fan -- on digital PIN 10
  VarSpeedServo servo3;              // 360° Servo to rotate Base ---- on digital PIN 9
                                     //   0° =  800 Microseconds
                                     // 180° = 1350 Microseconds 
                                     // 360° = 1955 Microseconds

// Transistors to switch Servos On/Off
  int trans1 = 6;                    // transistor to switch Servo 1 - on digital Pin 6
  int trans2 = 5;                    // transistor to switch Servo 2 - on digital Pin 5
//int trans3 = 3;                    // DISABLED IN THE 360° Version - interferes with the servo positioning
                                     // transistor to switch Servo 3 - on digital Pin 3
  
// Counter 
  int counter;                       // initialize a counter to count how often the distance has been measured
  int wait = 31500;		     // initialize a delay for the calibration movement - every 31500 measurements (approx. every 1h)

// Distance measurement  
  const int pingPin = 7;             // Grove Ultrasonic Ranger ------ on digital Pin 7
  int threshold;                     // Threshold level digital input (Ultra Sonic Ranger)
  int potpin = A0;                   // Potentiometer to adjust distance Threshold from 100 to 150 cm --- on Analog PIN 0
  int potval;                        // Variable to read Potentiometer Value

//sequences
servoSequencePoint slow[] = {{100,20},{70,20},{120,50}}; // go to position 100 at speed of 20, position 20 speed 20, position 60, speed 50
servoSequencePoint twitchy[] = {{0,255},{180,40},{90,127},{120,60}};
int pos, pos2;
int inside=0;

void setup() {
// initialize serial communication:
   Serial.begin(9600);

// Settings for Transistors and Servos   
   pinMode(trans1, OUTPUT);          // initialize the Transistors 1 - 3 as output:
   pinMode(trans2, OUTPUT);
// pinMode(trans3, OUTPUT);          // DISABLED IN THE 360° Version - interferes with the servo positioning
   
   digitalWrite(trans1, HIGH);       // Set default state of Transistors 1 - 3 to LOW :
   digitalWrite(trans2, HIGH);
// digitalWrite(trans3, HIGH);       // DISABLED IN THE 360° Version - interferes with the servo positioning
   delay(100);
   
   servo1.attach(11);                // Servo 1 (Fan Tilt) on pin 11
   servo1.writeMicroseconds(620);    // variable speed servo1 position in Microdseconds
   servo2.attach(10);                // Servo 2 (Fan open/close) on pin 10
   servo2.writeMicroseconds(580);    // variable speed servo2 position in Microdseconds
   servo3.attach(9);                 // Servo 3 (Base rotation) on pin 9
   servo3.writeMicroseconds(800);    // variable speed servo3 position in Microdseconds
   delay(100);
    
   digitalWrite(trans1, LOW);        // Set default state of Transistors 1 - 3 to LOW :
   digitalWrite(trans2, LOW);
   //digitalWrite(trans3, LOW);	     // DISABLED IN THE 360° Version - interferes with the servo positioning  

   //read values for threshold of ping sensor
   potval = analogRead(potpin);                  // reads the value of the potentiometer (value 0 to 1023)
   threshold = map(potval, 0, 1023, 100, 150);   // scale it to set distance Threshold between 100 and 150cm
}

// settings for UltraSonicRanger
  long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}


void loop(){


// Setting for the UltraSonicRanger 
  counter += 1;
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, cm;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(pingPin, INPUT);
  duration = pulseIn(pingPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  
  int digitalValue = microsecondsToCentimeters(duration);

 

/////////////////////////////////////////
//loop/////  Full movement of the fan ///
/////////////////////////////////////////
//servo 1 down value=4                 //
//        up   value=1400              //
//servo 2    closed value value=580    //
//           45º open     value = 725
//           open 2100
//
//servo3  init value=800               //
//        90º  value=1000              //
/////////////////////////////////////////

 if(digitalValue < threshold) {                 // If the measured distance drops below Threshold start full movement of the fan
   if(inside==0){
	counter = 0;                            // reset counter to 0
        inside=1;
     

    //TEST SERVO1
                                     
     
     wakeUp();    
     //hello();
     
     inside=0;
	
   } //inside
  }
}

void hello() {
  //go up, open 45º and wait
     servo1.slowmove(1350, 16);
     servo2.slowmove(1000,30);
     delay(3000);
   //open fan down and rest
     servo2.slowmove(2100,150);
     delay(500);
     digitalWrite(trans2, LOW);
   //abanicando like a real fun  
     servo3.slowmove(1000,120);
     delay(500);
     servo3.slowmove(800,120);
     delay(500);
     servo3.slowmove(1000,120);
     delay(500);
     servo3.slowmove(800,120);
     delay(500);
   //close fast and rest
     digitalWrite(trans2, HIGH);
     servo2.slowmove(580,150);
     servo1.slowmove(620,150);    //go home
     delay(500);
     digitalWrite(trans1, LOW);
     digitalWrite(trans2, LOW);
     delay(3000); 
   //play compas  
     digitalWrite(trans1, HIGH);
     digitalWrite(trans2, HIGH);
     //compas();
     doCompas(0, 12, 300, 620, 850, 40, 1, 150);
     digitalWrite(trans1, LOW);
     digitalWrite(trans2, LOW);
   //open all slowly
     digitalWrite(trans1, HIGH);
     digitalWrite(trans2, HIGH);
     servo1.slowmove(1700,25);
     servo2.slowmove(1800,35);
     delay(3000);
   //turn a bit around
     servo3.slowmove(1300,20);
     delay(3000);
     servo3.slowmove(800,20);
     delay(3000);
   //close almost
     servo2.slowmove(880,50);
     servo1.slowmove(920,50);
     delay(3000);
   //turn around like looking
     servo3.slowmove(900,50);
     delay(1000);
     servo3.slowmove(800,10);
     delay(2000);
     servo3.slowmove(700,10);
     delay(1000);
     servo3.slowmove(850,10);
     delay(1000);
     servo3.slowmove(950,10);
   //close all fast and rest
     servo2.slowmove(580,150);
     servo1.slowmove(620,150);  
     delay(1000); 
     
     digitalWrite(trans1, LOW);
     digitalWrite(trans2, LOW);

     delay(3000);
}



void doCompas(int tCompas,int nCompas, int tempo, int pos1, int pos2, int pos3, int nServo, int vel){

  if(nServo==1){
    for(int i=0;i<nCompas;i++){
      if(i==0 || i==2 || i==5 || i==7 || i==9){  //accent
       servo1.slowmove(pos1,vel);
       delay(tempo);
       servo1.slowmove(pos1,pos3);
       delay(tempo);
      } else{                                    //no accent
        servo1.slowmove(pos1,vel);
       delay(tempo);
       servo1.slowmove(pos2,vel);
       delay(tempo);
      }
    }
    servo1.slowmove(pos1,vel);
  }
  
  if(nServo==2){
    for(int i=0;i<nCompas;i++){
       servo2.slowmove(pos1,vel);
       delay(tempo);
       servo2.slowmove(pos2,vel);
       delay(tempo);
    }
    servo2.slowmove(pos1,vel);
  }
  
  if(nServo==3){
    for(int i=0;i<nCompas;i++){
       servo3.slowmove(pos1,vel);
       delay(tempo);
       servo3.slowmove(pos2,vel);
       delay(tempo);
    }
  }
  
}

void wakeUp(){
    delay(30000);
    //start transistors
    digitalWrite(trans1, HIGH);       //enable transistors          
    digitalWrite(trans2, HIGH); 
    delay(5000);
  //go up, open 45º and wait
     servo1.slowmove(1350,4);
     servo2.slowmove(1000,6);
     delay(20000);
   //open yourself
     servo1.slowmove(1000,4);
     servo2.slowmove(1700,8);
     servo3.slowmove(900,4);
     delay(5000);
     servo2.slowmove(1500,8);
     servo3.slowmove(750,4);
     delay(5000);
     servo2.slowmove(1700,8);
     servo3.slowmove(800,4);  
     delay(5000);
     //cierra despacio y descansa    
     servo1.slowmove(620,5);    //go home
     servo2.slowmove(580,5);
     delay(13000); 
     //un poco de compas   
     doCompas(0, 2, 600, 580, 650, 40, 2, 50);
     delay(2000);
     doCompas(0, 1, 600, 580, 750, 40, 2, 25);
     delay(2000);
     doCompas(0, 2, 600, 580, 650, 40, 2, 50);
     delay(10000);
     digitalWrite(trans1, LOW);
     digitalWrite(trans2, LOW);
   //open fan down and rest
     //servo2.slowmove(2100,150);
     //delay(500);
     //digitalWrite(trans2, LOW);
}

/* //old compas way
void compas() {
   
     servo1.slowmove(620,150);
     delay(300);
     servo1.slowmove(850,150);
     delay(300);
     servo1.slowmove(620,150);
     delay(300);
     servo1.slowmove(850,150);
     delay(300);
     servo1.slowmove(620,150);
     delay(300);
     servo1.slowmove(850,150);
     delay(300);
     servo1.slowmove(620,150);
     delay(300);
     servo1.slowmove(850,150);
     delay(300);
     servo1.slowmove(620,150);
     delay(300);
     servo1.slowmove(850,150);
     delay(300);
     servo1.slowmove(620,150);
     delay(300);
     servo1.slowmove(850,150);
     delay(300);
     servo1.slowmove(620,150);
     delay(300);
     servo1.slowmove(850,150);
     delay(300);
     servo1.slowmove(620,150);
     delay(300);
     servo1.slowmove(850,150);
     delay(300);
     servo1.slowmove(620,150);
     delay(300);
     servo1.slowmove(850,150);
     delay(300);
     servo1.slowmove(620,150);
     delay(300);
     servo1.slowmove(850,150);
     delay(300);
     servo1.slowmove(620,150);
     delay(300);
     servo1.slowmove(850,150);
     delay(300);
     servo1.slowmove(620,150);
     delay(300);
     servo1.slowmove(850,150);
     delay(300);
}
*/
