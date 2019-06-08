#include <Servo.h>
#include "servoReader.h"

servoConfig servo1 = {
  /*pin =*/ 2,
  /*min =*/ 536,
  /*max =*/ 2375,
  /*scaleMin =*/ 0,
  /*scaleMax =*/ 1023
};

int min = 3000, max=0, tmp;


void setup() {
//  pinMode(servo1InputPin, INPUT);
  servoReader::begin(servo1);
  Serial.begin(115200);
  Serial.println("Start...");
}

void loop() {
  delay(10);
  //Serial.println(servoReader::read(servo1));
  tmp = servoReader::read(servo1);
  if(tmp<0)return;
//  tmp = pulseIn(servo1InputPin, HIGH);
  if(tmp > max)
  {
    max = tmp;
    //Serial.println("Max: " + String(max));
  }
  else if(tmp < min)
  {
    min = tmp;
    //Serial.println("Min: " + String(min));
  }
  Serial.println("Max: " + String(max) + " Min: " + String(min) + " High: " + String(tmp));
}
