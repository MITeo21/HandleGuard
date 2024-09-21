#include "tasks.h"
#include "Arduino.h"

// globals
float ultrasonicDistanceCm;

// setup + loop

void setup() {
  Serial.begin(115200);
  // setupMPU();
}

void loop() {
  // loopMPU();
  loopHCSR();
  Serial.println(ultrasonicDistanceCm);
  loopLaser();
}