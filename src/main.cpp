#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>

#include "lib/display/display.h"
#include "lib/led/led_control.h"
#include "lib/motor/motor.h"
#include "lib/wifi/wifi_connection.h"
#include "lib/credentials/wifi_credentials.h"
#include "lib/server/web_routes.h"

AsyncWebServer server(80); // Instantiate the web server

void setup() {
    Serial.begin(115200);
    
    initDisplay();
    initLEDs();
    initMotor(12);

    if (!SPIFFS.begin(true)) {
        Serial.println("An Error has occurred while mounting SPIFFS");
        return;
    }

    displayMessage("Connecting to WiFi...", 0, 0, true);
    connectToWiFi(ssid, password); // Manage WiFi connectivity

    // Initialize and start the web server with defined routes
    setupWebRoutes(server);
    server.begin();
}

void loop() {
  // Main loop body remains empty for this asynchronous web server setup
}
