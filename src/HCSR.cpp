#include "tasks.h"
#include <HCSR04.h>

UltraSonicDistanceSensor distanceSensor(HCSR_TRIGGER, HCSR_ECHO);  // Initialize sensor that uses digital pins 13 and 12.

void loopHCSR () {
    // Every 500 miliseconds, do a measurement using the sensor and print the distance in centimeters.
    static uint32_t prev_ms = millis();
    if (millis() > prev_ms + HCSR_PERIOD_MS) {
        Serial.println(distanceSensor.measureDistanceCm());
        prev_ms = millis();
    }
}
