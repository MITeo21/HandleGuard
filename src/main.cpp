#include "tasks.h"
#include "Arduino.h"

// globals
float ultrasonicDistanceCm;

// setup + loop

void setup() {
  Serial.begin(115200);
  mpuSetup();
  setupLaser();
}

void loop() {
  mpuMeasure();
  loopHCSR();
  loopLaser();
}