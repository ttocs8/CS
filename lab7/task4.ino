#include <Wire.h>
#include <Zumo32U4.h>
Zumo32U4Motors motors;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  //Spin the robot clockwise for 1 sec
   int speed = 200;
   motors.setSpeeds(speed, -speed);
   delay(1000); // Don
   motors.setSpeeds(0,0);
   
   //Spin the robot counter-clockwise for 1 sec
   motors.setSpeeds(-speed, speed);
   delay(1000);
   motors.setSpeeds(0,0);
   
}
