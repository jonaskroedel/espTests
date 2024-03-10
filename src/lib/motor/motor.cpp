#include "motor.h"
#include <Arduino.h>
#include "lib/display/display.h"

const int freq = 50; // Servo frequency (50Hz)
const int ledChannel = 0; // Use first channel of 16 available
const int resolution = 16; // 16-bit resolution
int servoPin;

void initServo(int pin) {
  servoPin = pin;
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(servoPin, ledChannel);
}

void rotateServo() {
  // Assuming a SG90 servo motor, these duty cycles correspond to 0° and 180°.
  // These values might need to be adjusted depending on your specific servo.
  int minDuty = 1638; // ~1ms pulse width (0°)
  int maxDuty = 8191; // ~2ms pulse width (180°)

  ledcWrite(ledChannel, minDuty); // Move to 0°
  delay(1000);
  ledcWrite(ledChannel, maxDuty); // Move to 180°
  delay(1000);
  ledcWrite(ledChannel, minDuty); // Move back to 0°
  delay(1000);

  displayMessage("Servo test complete", 0, 32, false);
}
