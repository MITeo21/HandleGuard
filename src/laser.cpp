#include "tasks.h"

extern float ultrasonicDistanceCm;

void loopLaser() {
    if (ultrasonicDistanceCm < DANGER_DISTANCE) {
        digitalWrite(LASER_PIN, HIGH);
    }
    else {
        digitalWrite(LASER_PIN, LOW);
    }
}