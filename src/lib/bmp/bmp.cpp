#include "bmp.h"
#include "lib/display/display.h"

Adafruit_BMP085 bmp;

void initBMP() {
    if (!bmp.begin()) {
        displayMessage("Could not find a valid BMP085 sensor, check wiring!", 0, 24, false, true);
        while (1) {}
    }
    displayMessage("BMP180 Sensor found", 0, 24, false, true);
}

float readBMPTemperature() {
    return bmp.readTemperature();
}
