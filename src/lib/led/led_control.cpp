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

void setRGB(uint32_t hexColor) {
  int red = (hexColor >> 16) & 0xFF;    // Extrahieren der Rotkomponente
  int green = (hexColor >> 8) & 0xFF;   // Extrahieren der Grünkomponente
  int blue = hexColor & 0xFF;           // Extrahieren der Blaukomponente
  
  digitalWrite(RED_PIN, !red);
  digitalWrite(GREEN_PIN, !green);
  digitalWrite(BLUE_PIN, !blue);
}