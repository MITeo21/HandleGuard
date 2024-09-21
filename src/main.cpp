#include "tasks.h"
#include "Arduino.h"

// globals
float ultrasonicDistanceCm;
float mpuAngle = 0;

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

  if (ultrasonicDistanceCm < 5) {
    digitalWrite(MOTOR_PIN,HIGH);
  }
}