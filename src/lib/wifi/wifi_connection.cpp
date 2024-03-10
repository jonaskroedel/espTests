#include "wifi_connection.h"
#include "lib/display/display.h"
#include "lib/led/led_control.h"

void connectToWiFi(const char* ssid, const char* password) {
  WiFi.begin(ssid, password);
  displayMessage("Connecting to WiFi...", 0, 0, true, true);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 30) {
    setRGB (0xffff00); // yellow
    delay(500);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    displayMessage("WiFi Connected", 0, 0, true, true);
    displayMessage("IP Address:", 0, 8, false, true);
    displayMessage(WiFi.localIP().toString(), 0, 16, false, true);
    Serial.println("\nWiFi Connected.");
    
    setRGB(0x00ff00); // green
    delay(1000);
    setRGB(0); // off
  } else {
    displayMessage("WiFi Connect Failed", 0, 0, true, true);
    Serial.println("\nWiFi Connection Failed.");

    setRGB(0xff0000); // red
    delay(1000);
    setRGB(0); // off
  }
}
