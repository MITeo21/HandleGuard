#ifndef TASKS_H
#define TASKS_H

#include "pins.h"
#include "Arduino.h"

// Motor

// IMU - MPU9250
#define MPU_PERIOD_MS 25
void setupMPU();
void loopMPU();

// Laser
#define DANGER_DISTANCE 30
void loopLaser();

// Ultrasonic - HCSR04
#define HCSR_PERIOD_MS 500
void loopHCSR();

#endif