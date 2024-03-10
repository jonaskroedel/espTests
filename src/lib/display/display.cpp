#include "display.h"
#include <Wire.h>

#define OLED_WIDTH 128
#define OLED_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT, &Wire, OLED_RESET);

void initDisplay() {
  Wire.begin(); // Using default SDA and SCL pins
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.display();
}

void displayMessage(String message, int x, int y, bool clearDisplay, bool clearLine) {
  display.setCursor(x, y);
  if (clearDisplay) {
  display.clearDisplay();
  } else if (clearLine) {
    display.fillRect(0, y, OLED_WIDTH, 8, SSD1306_BLACK);
  }
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.println(message);
  display.display();
}
