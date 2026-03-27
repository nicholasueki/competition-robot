#include <myDuino.h>
myDuino robot(1);
 
bool piston = 1; //  o 1
bool solanoid1 = 1; // (walls) o 2
bool solanoid2 = 1; // (car) o 3
void encHandler() {
robot.doEncoder();
}

void setup() {
attachInterrupt(digitalPinToInterrupt(2), encHandler, CHANGE);
attachInterrupt(digitalPinToInterrupt(3), encHandler, CHANGE);
Serial.begin(9600);
}
void loop() {
  bool but = robot.readButton(1);
 
  if (piston){
    piston = 0;
    robot.digital(1, 1);
    delay(2000);
  } else if(solanoid1){
    robot.digital(2, 1);
    delay(1000);

    solanoid1 = 0;
  } else if (solanoid2){
    robot.digital(3, 1);

    solanoid2 = 0;
  }  
    
}
  

