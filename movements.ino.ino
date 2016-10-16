  /////////////////////////////////////////
  //loop/////  Full movement of the fan ///
  /////////////////////////////////////////
  //servo 1 down value=620               //
  //        up   value=1400              //
  //servo 2    closed value value=580    //
  //           45º open     value = 725  //
  //           open 2100                 //
  //                                     //
  //servo3  init value=800               //
  //        90º  value=1000              //
  //        180º value=1300              //
  /////////////////////////////////////////



void startAbanico(){
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

}


void hello() {; 
  //go up, open 45º and wait
     digitalWrite(trans1, HIGH);
     digitalWrite(trans2, HIGH);
     servo1.slowmove(1350, 16);
     servo2.slowmove(1000,30);
     delay(3000);
   //close fan down and rest
     servo2.slowmove(2100,150);
     delay(500);
     digitalWrite(trans2, LOW);
     delay(2000);
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
     doCompas(0, 12, 300, 620, 850, 40, 1, 100, 100);
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
     servo2.slowmove(580,50);
     servo1.slowmove(620,50);  
     delay(1000); 
     
     digitalWrite(trans1, LOW);
     digitalWrite(trans2, LOW);

}

void hello2() {; 
  //go up, open 45º and wait
     digitalWrite(trans1, HIGH);
     digitalWrite(trans2, HIGH);
     servo1.slowmove(1350, 16);
     servo2.slowmove(1000,30);
     delay(3000);
   //ope fan down and rest
     servo1.slowmove(1500, 16);
     servo2.slowmove(2100,80);
     delay(1000);
     digitalWrite(trans2, LOW);
     delay(2000);
   //close fast and rest
     digitalWrite(trans2, HIGH);
     servo2.slowmove(580,150);
     servo1.slowmove(620,150);    //go home
     delay(500);
     digitalWrite(trans1, LOW);
     digitalWrite(trans2, LOW);
     delay(3000); 
     
     digitalWrite(trans1, LOW);
     digitalWrite(trans2, LOW);

}


void wakeUp(){   // rotate center is 800
    
    delay(100);
  //rotate for waking up
    servo3.slowmove(1200,6);
    delay(7000); 
    servo3.slowmove(800,8);
    delay(4000);   
  //go up, open 45º and wait
    //start transistors
    digitalWrite(trans1, HIGH);       //enable transistors          
    digitalWrite(trans2, HIGH); 
     servo1.slowmove(1350,8);
     servo2.slowmove(1000,8);
     servo3.slowmove(750,6);
     delay(6000);
  //look left   
     servo3.slowmove(850,8);
     digitalWrite(trans2, LOW);
     delay(5000);
  //look right
     servo3.slowmove(600,8);
     delay(5000);
  //look center   
     //servo3.slowmove(800,8);
     //delay(3000);
   //open yourself
     digitalWrite(trans2, HIGH);
     servo1.slowmove(950,52);
     servo2.slowmove(1700,52);
     servo3.slowmove(750,7);
     //servo3.slowmove(900,6);
     delay(6000);
     //servo2.slowmove(1500,18);
     
     //delay(6000);
     //servo3.slowmove(1300,8);
     delay(5000);
     //servo2.slowmove(1700,8);
     //servo3.slowmove(700,19);  
     //delay(4000);
     //cierra medio despacio y descansa    
     servo1.slowmove(620,12);    //go home
     servo2.slowmove(580,12);
     delay(4000);
     digitalWrite(trans1, LOW);       //disable transistors          
     digitalWrite(trans2, LOW);
     
     /*
     //un poco de compas   
     digitalWrite(trans1, HIGH);       //enable transistors          
     digitalWrite(trans2, HIGH);
     delay(100);
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
     */
}

void dance1(){
  
     digitalWrite(trans1, HIGH);
     digitalWrite(trans2, HIGH);
     //go up, and down
     servo1.slowmove(1550, 26);
     //servo1.slowmove(580, 26);
     //servo2.slowmove(1000,30);
     delay(3000);
     servo1.slowmove(620, 26);
     delay(1500);
     digitalWrite(trans1, LOW);       //disable transistors          
     digitalWrite(trans2, LOW);
     delay(1000);
     //rotate
     digitalWrite(trans1, HIGH);
     digitalWrite(trans2, HIGH);
     servo3.slowmove(1300, 10);
     delay(3000);
     servo3.slowmove(1000, 10);
     delay(3000);
     //open
     servo1.slowmove(1500,26);
     servo2.slowmove(2000,26);
     delay(4000);
     servo3.slowmove(800,16);
     delay(2500);
     servo1.slowmove(720, 16);
     servo2.slowmove(680, 16);
     delay(2000);
     digitalWrite(trans1, HIGH);
     digitalWrite(trans2, HIGH);
     servo1.slowmove(1500,26);
     servo2.slowmove(2000,26);
     servo3.slowmove(1000,10);
     delay(4000);
     servo1.slowmove(2000,26);
     servo2.slowmove(2200,26);
     servo3.slowmove(1200,10);
     delay(3000);
     servo2.slowmove(2200,26);
     delay(3000);
     servo2.slowmove(1700,26);
     delay(3000);
     servo1.slowmove(1700,26);
     servo2.slowmove(2100,26);
     delay(2500);
     servo1.slowmove(1900,26);
     delay(3000);
     servo1.slowmove(1200,26);
     delay(3500);
     servo1.slowmove(620, 86);
     servo2.slowmove(580, 86);
     delay(2000);
     digitalWrite(trans1, LOW);       //disable transistors          
     digitalWrite(trans2, LOW);
}

void vueltas(){
     digitalWrite(trans1, HIGH);
     digitalWrite(trans2, HIGH);
     servo1.slowmove(1620,50);
     servo2.slowmove(2200,50);
     delay(3000);
     servo1.slowmove(1100,50);
     servo3.slowmove(1300,50);
     delay(2000);
     servo1.slowmove(1620,50);
     delay(2000);
     servo1.slowmove(1850,50);
     servo3.slowmove(1000,20);
     delay(1500);
     servo3.slowmove(1300,20);
     delay(1500);;
     servo1.slowmove(620, 86);
     servo2.slowmove(580, 86);
     delay(1500);
     digitalWrite(trans1, LOW);
     digitalWrite(trans2, LOW);
}

void giraXY(){
     digitalWrite(trans1, HIGH);
     digitalWrite(trans2, HIGH);
     
     servo2.slowmove(2200,130);
     delay(1500);
     //digitalWrite(trans1, HIGH);
     servo1.slowmove(1400,60);
     delay(750);
     servo1.slowmove(630,60);
     delay(1250);
     servo1.slowmove(620,60);
     servo2.slowmove(600,60);
     delay(1000);
     
     digitalWrite(trans1, LOW);
     digitalWrite(trans2, LOW);
}

void llegada(){
     digitalWrite(trans1, HIGH);
     digitalWrite(trans2, HIGH);
     
     servo2.slowmove(2200,90); 
     delay(1250);
     digitalWrite(trans1, LOW);       //disable transistors          
     digitalWrite(trans2, LOW);
     delay(4000);
     digitalWrite(trans1, HIGH);
     digitalWrite(trans2, HIGH);
   //rotate for waking up  
  //go up, open 45º and wait
    //start transistors   
     servo2.slowmove(1150,18);    
     servo1.slowmove(1150,18);
     
     servo3.slowmove(800,6);
     delay(2500);
     digitalWrite(trans1, LOW);       //disable transistors          
     digitalWrite(trans2, LOW);
     delay(2000);
     digitalWrite(trans1, HIGH);
     digitalWrite(trans2, HIGH);
  //look left   
     servo3.slowmove(900,8);
     digitalWrite(trans2, LOW);
     delay(4000);
  //look right
     servo3.slowmove(750,8);
     delay(3000);;
   //open yourself
     digitalWrite(trans2, HIGH);
     servo1.slowmove(950,15);
     servo2.slowmove(1700,15);
     servo3.slowmove(750,37);
     //servo3.slowmove(900,6);
     delay(4000);
     //servo2.slowmove(1700,8);
     //servo3.slowmove(700,19);  
     //delay(4000);
     //cierra medio despacio y descansa    
     servo1.slowmove(620,42);    //go home
     servo2.slowmove(580,42);
     delay(4000);  
     digitalWrite(trans1, LOW);       //disable transistors          
     digitalWrite(trans2, LOW);
}

void abanicando(){
     digitalWrite(trans1, HIGH);
     digitalWrite(trans2, HIGH);
     servo1.slowmove(1500,10);
     servo2.slowmove(2100,10);
     delay(5000);
     servo3.slowmove(2000,10);
     delay(6000);
     //abanicando like a real fun  
     servo3.slowmove(2400,180);
     delay(300);
     servo3.slowmove(2200,180);
     delay(300);
     servo3.slowmove(2400,180);
     delay(1300);
     /*
     servo3.slowmove(800,120);
     delay(500);
     servo3.slowmove(1000,120);
     delay(500);
     servo3.slowmove(800,120);
     delay(500);
     servo3.slowmove(1000,120);
     delay(500);
     servo3.slowmove(800,120);
     delay(500);
     */
     //rotate 
     servo3.slowmove(1300,7);
     delay(8000);
     servo3.slowmove(1500,160);
     delay(300);
     servo3.slowmove(1300,160);
     delay(300);
     servo3.slowmove(1500,160);
     delay(300);
     servo3.slowmove(1300,160);
     delay(300);
     servo3.slowmove(1500,160);
     delay(300);
     servo3.slowmove(1300,160);
     delay(300);
     servo3.slowmove(1500,160);
     delay(300);
     servo3.slowmove(800,35);
   //close fast and rest
     digitalWrite(trans2, HIGH);
     servo2.slowmove(580,35);
     servo1.slowmove(620,35);    //go home
     delay(2500);
     digitalWrite(trans1, LOW);
     digitalWrite(trans2, LOW);
     delay(3000); 
}

void radarAbre(){
  
  //servo3.slowmove(800,10);
  //delay(3000);
  servo3.slowmove(1300,10);
  delay(3000);
  //servo3.slowmove(2000,10);
  //delay(3000);
  digitalWrite(trans1, HIGH);
  digitalWrite(trans2, HIGH);
  servo1.slowmove(1500,80);
  servo2.slowmove(2100,80);
  delay(2000);
  servo2.slowmove(580,80);
  delay(1500);
  servo2.slowmove(2100,80);
  delay(1500);
  servo2.slowmove(580,80);
  delay(1500);
  servo2.slowmove(2100,80);
  delay(2500);
  servo3.slowmove(2400,40);
  delay(3000);
  servo2.slowmove(580,80);
  servo1.slowmove(620,85); 
  delay(2000);
  servo2.slowmove(2200,90); 
  delay(1250);
  digitalWrite(trans1, LOW);
  digitalWrite(trans2, LOW);
}
