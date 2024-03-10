#include "led_control.h"
#include <Arduino.h>

#define RED_PIN 17
#define GREEN_PIN 16
#define BLUE_PIN 15

void initLEDs() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
}

void setRGB(int red, int green, int blue) {
  digitalWrite(RED_PIN, !red);
  digitalWrite(GREEN_PIN, !green);
  digitalWrite(BLUE_PIN, !blue);
}
