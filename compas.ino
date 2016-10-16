

void doCompas(int tCompas,int nCompas, int tempo, int pos1, int pos2, int pos3, int nServo, int vel, int vel2){
  
  digitalWrite(trans1, HIGH);
  /*
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
  */
  //servo1.slowmove(pos1,vel);
  //delay(1000);
  
  if(nServo==1){
    for(int i=0;i<nCompas;i++){
        if(i==1 || i==4 || i==7 || i==9 || i==11 ) {      
           servo1.slowmove(pos3,vel2);
           delay(tempo);
           servo1.slowmove(pos1,vel2);
           delay(tempo);
        } else {
           servo1.slowmove(pos2,vel);
           delay(tempo);
           servo1.slowmove(pos1,vel);
           delay(tempo);
        }
    }
    //servo1.slowmove(pos1,vel);
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
  
  digitalWrite(trans1, LOW);
  digitalWrite(trans2, LOW);
  
}

void doBuleria(int tCompas,int nCompas, int tempo, int pos1, int pos2, int pos3, int nServo, int vel, int vel2){
  
  digitalWrite(trans1, HIGH);
  /*
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
  */
  //servo1.slowmove(pos1,vel);
  //delay(1000);
  
  if(nServo==1){
    for(int i=0;i<nCompas;i++){
        if(i==0 || i==3 || i==6 || i==9 ) {      
           servo1.slowmove(pos3,vel2);
           delay(tempo);
           servo1.slowmove(pos1,vel2);
           delay(tempo);
        } else {
           servo1.slowmove(pos2,vel);
           delay(tempo);
           servo1.slowmove(pos1,vel);
           delay(tempo);
        }
    }
    //servo1.slowmove(pos1,vel);
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
  
  digitalWrite(trans1, LOW);
  digitalWrite(trans2, LOW);
  
}
