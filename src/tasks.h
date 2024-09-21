#ifndef TASKS_H
#define TASKS_H

#include "pins.h"
#include "Arduino.h"

void mpuSetup();
void mpuMeasure();
#define MPU_PERIOD_MS 25

void loopHCSR();
#define HCSR_PERIOD_MS 500

#endif