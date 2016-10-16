                                             
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
  int digitalValue;
  
//sequences
  servoSequencePoint slow[] = {{100,20},{70,20},{120,50}}; // go to position 100 at speed of 20, position 20 speed 20, position 60, speed 50
  servoSequencePoint twitchy[] = {{0,255},{180,40},{90,127},{120,60}};
  int pos, pos2;
  int haEntrado=0;



void setup() {
// initialize serial communication:
   Serial.begin(9600);

// Settings for Transistors and Servos   
   pinMode(trans1, OUTPUT);          // initialize the Transistors 1 - 3 as output:
   pinMode(trans2, OUTPUT);
// pinMode(trans3, OUTPUT);          // DISABLED IN THE 360° Version - interferes with the servo positioning
   
   //read values for threshold of ping sensor
   potval = analogRead(potpin);                  // reads the value of the potentiometer (value 0 to 1023)
   threshold = map(potval, 0, 1023, 100, 150);   // scale it to set distance Threshold between 100 and 150cm
   
   startAbanico();
}


void loop(){


  //PING SENSOR WORKAROUND
  calculatePing();
  Serial.println(digitalValue);
  
   if(digitalValue < 80) { //true) {                 // If the measured distance drops below Threshold start full movement of the fan
     if(haEntrado==0){
       haEntrado=1;
       Serial.println("dentro");
	counter = 0;                            // reset counter to 0
        //inside=1;
     
        //delay(2000);
        //hello2();
        
        
        
        llegada();
        delay(3000);
        abanicando();
        delay(1000);
        giraXY();
        delay(500);
        giraXY();
        radarAbre();
        delay(24000);
        
        digitalWrite(trans1, HIGH);
        digitalWrite(trans2, HIGH);
        servo2.slowmove(580,35);
        servo1.slowmove(620,35);    //go home
        delay(1500);
        
        
        
        for(int i=0;i<16;i++){
          doBuleria(0,12, 150, 620, 780, 900, 1, 120, 160);
        }
        
        doBuleria(0,1, 150, 620, 780, 900, 1, 120, 160);
        
        delay(2000);
        digitalWrite(trans1, HIGH);
         digitalWrite(trans2, HIGH);
     
         servo2.slowmove(2200,90); 
         delay(1250);
         servo2.slowmove(580,35);
        servo1.slowmove(620,35);
        digitalWrite(trans1, LOW);
        digitalWrite(trans2, LOW);
        /*
        delay(24000);
        giraXY();
        delay(3000);
        giraXY();
        delay(3000);
        giraXY();
        delay(2000);
        dance1();
        */
        
        //delay(3000);
        //doCompas(0, 2, 1000, 620, 780, 780, 1, 80);
        
        
        /*
        
        //MOVE IT!
        delay(5000);
        wakeUp();
        delay(10000);    
        vueltas();    
        delay(10000);
        dance1();
        delay(6000);         
        vueltas();
        delay(4000);
        giraXY();
        
        //Buleria
        delay(3000);
        for(int i=0;i<3;i++){
          doBuleria(0,12, 250, 620, 780, 900, 1, 80, 120);
        }
        */
        
       haEntrado=0;
	
     } //ha entrado (run the abanico movements in loop only once)
    }
    Serial.println("fuera");
}





// settings for UltraSonicRanger
  long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

  void calculatePing(){
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
  
    digitalValue = microsecondsToCentimeters(duration);
    //Serial.println(digitalValue);
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
