/*
  Created by Jochen Zeirzer
  http://www.jochen_zeirzer.public2.linz.at/
  project: Abanico
  year:    2013
  modified for 360° Servo 15 June 2014
 
   Ping))) Sensor
   http://www.arduino.cc/en/Tutorial/Ping
   
   created 3 Nov 2008
   by David A. Mellis
   modified 30 Aug 2011
   by Tom Igoe 
*/

                                             
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
   delay(250);
   
   servo1.attach(11);                // Servo 1 (Fan Tilt) on pin 11
   servo1.writeMicroseconds(620);    // variable speed servo1 position in Microdseconds
   servo2.attach(10);                // Servo 2 (Fan open/close) on pin 10
   servo2.writeMicroseconds(580);    // variable speed servo2 position in Microdseconds
   servo3.attach(9);                 // Servo 3 (Base rotation) on pin 9
   servo3.writeMicroseconds(800);    // variable speed servo3 position in Microdseconds
   delay(2000);
    
   digitalWrite(trans1, LOW);        // Set default state of Transistors 1 - 3 to LOW :
   digitalWrite(trans2, LOW);
// digitalWrite(trans3, LOW);	     // DISABLED IN THE 360° Version - interferes with the servo positioning  
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
  
  Serial.print(cm);
  Serial.print("cm");
  Serial.print(", counter ");
  Serial.print(counter);
  Serial.println();  
  delay(100);

// If the counter reaches the benchmark of "wait" (31500 distance measurments) start calibration movement
       if(counter >= wait) {                           

        digitalWrite(trans1, HIGH);                  
        digitalWrite(trans2, HIGH);
//        digitalWrite(trans3, HIGH);
        servo1.writeMicroseconds(620);
        servo2.writeMicroseconds(580);
        servo3.writeMicroseconds(800);
        delay(100);
        servo2.slowmove(2200, 25);
        delay(2800);
        digitalWrite(trans1, LOW);
        digitalWrite(trans2, LOW);
//        digitalWrite(trans3, LOW);
        delay(5000);
        digitalWrite(trans1, HIGH);                  
        digitalWrite(trans2, HIGH);
//        digitalWrite(trans3, HIGH);
        servo2.slowmove(600, 25);
        delay(2600);
        servo2.writeMicroseconds(580);
        delay(100);
        digitalWrite(trans1, LOW);
        digitalWrite(trans2, LOW);
//        digitalWrite(trans3, LOW);
	counter = 0;                            // reset counter to 0
}

// Full movement of the fan 

  potval = analogRead(potpin);                  // reads the value of the potentiometer (value 0 to 1023)
  threshold = map(potval, 0, 1023, 100, 150);   // scale it to set distance Threshold between 100 and 150cm

 if(digitalValue < threshold) {                 // If the measured distance drops below Threshold start full movement of the fan
	counter = 0;                            // reset counter to 0
	
        digitalWrite(trans1, HIGH);                  
        digitalWrite(trans2, HIGH);
//        digitalWrite(trans3, HIGH);
        servo1.slowmove(1625, 120);
        delay(350);
        servo2.slowmove(2200, 160);       
        delay(600);
        digitalWrite(trans2, LOW);
//        digitalWrite(trans3, LOW);
        delay(500);
        digitalWrite(trans1, HIGH);
//        digitalWrite(trans3, HIGH);                
        servo1.slowmove(880, 24);
        servo3.slowmove(1350, 22);
        delay(1300);
        servo3.writeMicroseconds(1350);        
        delay(500);        
//        digitalWrite(trans3, LOW);        
        digitalWrite(trans1, LOW);
        delay(3550);
        digitalWrite(trans1, HIGH);                  
        digitalWrite(trans2, HIGH);
//        digitalWrite(trans3, HIGH);
        servo1.slowmove(620, 8);
        servo2.slowmove(600, 37);
        servo3.slowmove(800, 18);        
        delay(1650);
        servo3.writeMicroseconds(800);
        servo2.writeMicroseconds(580);
        delay(200);
        digitalWrite(trans1, LOW);                  
        digitalWrite(trans2, LOW);
//        digitalWrite(trans3, LOW);
        delay(4000);
        
        counter = 0;                            // reset counter to 0
	
  }
}

