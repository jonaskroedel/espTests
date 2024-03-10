#ifndef MOTOR_H
#define MOTOR_H

#include <ESP32Servo.h>

void initMotor(int pin);
void moveServoAndWait(int pin, int targetPosition, int returnPosition, int delayTime);
void setMotorPosition(int degrees);

#endif