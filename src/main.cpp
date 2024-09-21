#include "tasks.h"
#include "Arduino.h"

void setup() {
  Serial.begin(115200);
  setupMPU();
}

void loop() {
  loopMPU();
  loopHCSR();
}