#include "tasks.h"
#include "Arduino.h"

// globals
float ultrasonicDistanceCm;

// setup + loop

void setup() {
  Serial.begin(115200);
  // setupMPU();
  setupLaser();
}

void loop() {
  // loopMPU();
  loopHCSR();
  loopLaser();
}