#include "wifi_connection.h"
#include "lib/display/display.h"
#include "lib/led/led_control.h"

void connectToWiFi(const char* ssid, const char* password) {
  WiFi.begin(ssid, password);
  displayMessage("Connecting to WiFi...", 0, 0, true);

  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED && attempts < 30) {
    setRGB (255, 255, 0); // yellow
    delay(500);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    displayMessage("WiFi Connected", 0, 0, true);
    setRGB(0, 255, 0); // green
    displayMessage("IP Address:", 0, 8, false);
    displayMessage(WiFi.localIP().toString(), 0, 16, false);
    Serial.println("\nWiFi Connected.");
  } else {
    displayMessage("WiFi Connect Failed", 0, 0, true);
    setRGB(255, 0, 0); // red
    Serial.println("\nWiFi Connection Failed.");
  }
}
