#include "tasks.h"
#include "Arduino.h"

// globals
float ultrasonicDistanceCm;
float mpuAngle;

// setup + loop

void setup() {
  Serial.begin(115200);
  mpuSetup();
  setupLaser();
  setupMotor();
  setupWebsocket();
}

void loop() {
  // input
  mpuMeasure();
  loopHCSR();
  // output
  loopLaser();
  loopMotor();
  loopWebsockets();
}