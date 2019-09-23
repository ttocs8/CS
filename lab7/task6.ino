#include <Zumo32U4.h>
Zumo32U4ButtonA buttonA;
Zumo32U4ProximitySensors proxSensors;


int getProximity(){
  proxSensors.read();
  int mean = 0;
  int r = proxSensors.countsFrontWithRightLeds();
  int l = proxSensors.countsFrontWithLeftLeds();
  mean = (r + l) / 2;
  Serial.print(mean);
  return mean;
}

void setup(){
  Serial.begin(115200);
  proxSensors.initThreeSensors();
}

void loop(){
  //buttonA.waitForButton();//Press A, get proximity
  getProximity();
  delay(200);
}
