#ifndef DISPLAY_H
#define DISPLAY_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

void initDisplay();
void displayMessage(String message, int x, int y, bool clearDisplay);

#endif
