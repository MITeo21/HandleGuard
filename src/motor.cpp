#include "tasks.h"

enum HapticState {
    HAPTIC_ON,
    HAPTIC_OFF
};

HapticState hapticState = HAPTIC_ON;
int hapticTime;
int hapticStart;

void setupMotor() {
    pinMode(MOTOR_PIN, OUTPUT);
}

void turnOnMotor(int timeDurationMillis) {
    hapticTime = timeDurationMillis;
    hapticStart = millis();
    hapticState = HAPTIC_ON;
}

void turnOffMotor() {
    hapticState = HAPTIC_OFF;
}

void loopMotor() {
    static uint32_t prev_ms = millis();
    if (millis() > prev_ms + MOTOR_PERIOD_MS) {
        switch (hapticState) {
            case HAPTIC_ON:
                analogWrite(MOTOR_PIN, HIGH);
                if (millis() - hapticStart > hapticTime) {
                    hapticState = HAPTIC_OFF;
                }
                break;
            case HAPTIC_OFF:
                analogWrite(MOTOR_PIN, LOW);
                break;
            default:
                Serial.println("Haptic Error");
                break;
        }
        prev_ms = millis();
    }
}