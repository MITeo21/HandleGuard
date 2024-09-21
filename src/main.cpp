#include "tasks.h"
#include "Arduino.h"

void setup() {
  Serial.begin(115200);
  mpuSetup();
}

void loop() {
  mpuMeasure();
  loopHCSR();
}