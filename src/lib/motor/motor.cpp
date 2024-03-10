#include "motor.h"
#include <Arduino.h>
#include "lib/display/display.h"

Servo motor;

void initMotor(int pin) {
    // Initialize the motor on a specific pin
    motor.setPeriodHertz(50); // Standard 50hz servo
    motor.attach(pin, 500, 2400); // attaches the servo on pin to the servo object
    // 500-2400 us is a common pulse width range for servos, adjust if necessary
}

void moveServoAndWait(int pin, int targetPosition, int returnPosition, int delayTime) {
    initMotor(pin); // Initialize the servo motor
    setMotorPosition(targetPosition); // Move servo to target position
    delay(delayTime); // Wait for 0.5 seconds
    setMotorPosition(returnPosition); // Move servo back to return position
}

void setMotorPosition(int degrees) {
    // Set the servo position in degrees
    // Make sure to constrain the degrees to the servo's range if needed
    degrees = constrain(degrees, 0, 180);
    motor.write(degrees);
}