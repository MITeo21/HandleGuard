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
  setupWebsocket();
}

void loop() {
  mpuMeasure();
  loopHCSR();
  loopLaser();
  loopWebsockets();
}