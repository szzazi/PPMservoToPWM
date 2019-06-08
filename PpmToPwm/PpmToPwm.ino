#include <Servo.h>
#include "servoReader.h"
#include "HBridgeController.h"

/* servo1 config */
servoConfig servo1 = {
  /* pin      = */ 2,
  /* min      = */ 536,
  /* max      = */ 2375,
  /* scaleMin = */ 0,
  /* scaleMax = */ 1023
};

HBridgeConfig motor1 ={
  /* PwmPin               */  8,
  /* DirectionalPin       */  9,
  /* directionalTresshold */  255
};

/*statistic variables */
int min = 3000, max=0, tmp;


void setup() {
  /* Servo init */
  servoReader::begin(servo1);
  HBridgeController::begin(motor1);

  /* for debug only */
  Serial.begin(115200);
  Serial.println("Start...");
}

void loop() {
  delay(10);
  //Serial.println(servoReader::read(servo1));
  tmp = servoReader::read(servo1);

  /* It is not valid value */
  if(tmp<0)return;

  Serial.println("Value: " + String(tmp) + " /2: " + String(tmp/2));
  HBridgeController::write(motor1, tmp/2);
  /* statistic for test */
  /*if(tmp > max)
  {
    max = tmp;
  }
  else if(tmp < min)
  {
    min = tmp;
  }*/
  /* for debug */
  //Serial.println("Max: " + String(max) + " Min: " + String(min) + " High: " + String(tmp));
}
