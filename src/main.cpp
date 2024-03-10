#include <WiFi.h>
#include "lib/display/display.h" // Include the display header
#include "lib/led/led_control.h" // Include the LED control header
#include "lib/motor/motor.h" // Include the motor header
#include "lib/wifi/wifi_connection.h" // Include the WiFi connection header
#include "lib/credentials/wifi_credentials.h" // Include the WiFi credentials header

void setup() {
  Serial.begin(115200);
  initDisplay(); // Initialize the display
  initLEDs(); // Initialize the LEDs
  initServo(12);

  // Display initialization message
  displayMessage("Connecting to WiFi...", 0, 16, true);
  connectToWiFi(ssid, password); // Connect to WiFi
  rotateServo();
}

void loop() {
  // No need to do anything here
}