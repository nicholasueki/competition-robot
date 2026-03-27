#include <myDuino.h>
myDuino robot(1);


bool done = 0;
bool piston_arm = 1;   
 void encHandler() {
  robot.doEncoder();
}
void setup() {
  attachInterrupt(digitalPinToInterrupt(2), encHandler, CHANGE);
  attachInterrupt(digitalPinToInterrupt(3), encHandler, CHANGE);
  Serial.begin(9600);
}
void loop() {

  ////////
  
  
  //if banana plugs and not done
  if (robot.readButton(1) && !done){

    robot.digital(1,1);
    delay(500);
    robot.digital(2,1);
    delay(1500);
    robot.moveMotor(1,1,255);
    delay(5000);
    robot.moveMotor(1,1,0);
    robot.moveMotor(2,1,255);
    delay(1500); //1.5 seconds
    robot.moveMotor(2,2,70); //Up
    delay(10000); //need to time 
    robot.moveMotor(2,2,0);

    done = 1;

  //piston 1 (arms) 1
  //delay 0.5 sec
  //piston 2 (rail) 1
  //delay 0.5 sec 
  //motor 1 1 225 - need to figure out direction 
  // delay 5 sec
  // motor 1 off
  //motor 2 (Down) - find out speed, direction
  //delay - find out duration 
  //motor 2 (Up) - find out speed, direction
  //delay - find out duration
  //motor 2 off

  //ahard off 35 seconds


  }
  



  ////////
  bool start = robot.readButton(1);  
  if(start){ 
     
    robot.digital(1,1); // activates the piston to push the arms forward
    Serial.println("piston for arm activated"); 
    delay(3000); // 3 second delay before car is deployed
    robot.digital(2,1); // activates the piston to push the drawer forward
    delay(3000);

    robot.digital(2,0); 
    robot.digital(1,0); 

    robot.moveMotor(1, 0, 100); //rotates motor 1 (arms) for 8 seconds
    delay(8000);
    robot.moveMotor(1, 0, 0);

    robot.moveMotor(2, 0, 100); //rotates motor 2 (elevator down) for 3 seconds to pick up crystal
    delay(3000);
    robot.moveMotor(2,1,100); //rotates motor 2 (elevator up) for 12 seconds to lift up crystal
    delay(12000);
    robot.moveMotor(2, 0 , 0);

     
  } else {
    //turns everything off.
    robot.digital(1, 0);
    robot.digital(2, 0);
    robot.digital(3, 0);
    Serial.println("end");
  }  
}

  

