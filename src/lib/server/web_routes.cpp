#include "web_routes.h"
#include "lib/motor/motor.h"
#include "lib/led/led_control.h"

void setupWebRoutes(AsyncWebServer& server) {
    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request) {
        File file = SPIFFS.open("/index.html", "r");
        if (!file || file.isDirectory()) {
            Serial.println("Failed to open file for reading");
            request->send(500, "text/plain", "Failed to open file for reading");
            return;
        }
        String fileContent = file.readString();
        request->send(200, "text/html", fileContent);
        file.close();
    });

     server.on("/styles.css", HTTP_GET, [](AsyncWebServerRequest *request) {
        File file = SPIFFS.open("/styles.css", "r");
        if (!file || file.isDirectory()) {
            Serial.println("Failed to open CSS file for reading");
            request->send(500, "text/plain", "Failed to open CSS file for reading");
            return;
        }
        String fileContent = file.readString();
        request->send(200, "text/css", fileContent);
        file.close();
    });

    // Route für JavaScript-Dateien
    server.on("/scripts.js", HTTP_GET, [](AsyncWebServerRequest *request) {
        File file = SPIFFS.open("/scripts.js", "r");
        if (!file || file.isDirectory()) {
            Serial.println("Failed to open JS file for reading");
            request->send(500, "text/plain", "Failed to open JS file for reading");
            return;
        }
        String fileContent = file.readString();
        request->send(200, "application/javascript", fileContent);
        file.close();
    });

    server.on("/move-servo", HTTP_GET, [](AsyncWebServerRequest *request) {
        int position = 30; // Default position
        int returnPosition = 0; // Return position
        int delayTime = 500; // Delay time in milliseconds
        if (request->hasParam("position")) {
            position = request->getParam("position")->value().toInt();
        }
        
        moveServoAndWait(12, position, returnPosition, delayTime);
        request->send(200, "text/plain", "Servo moved");
    });

    server.on("/get-temperature", HTTP_GET, [](AsyncWebServerRequest *request) {
        float temperature = readBMPTemperature();
        request->send(200, "text/plain", String(temperature));
    });

    server.on("/set-rgb", HTTP_GET, [](AsyncWebServerRequest *request) {
    if (request->hasParam("color")) {
        String colorString = request->getParam("color")->value();
        // Konvertiere den Hex-String (ohne das führende #) in uint32_t
        uint32_t color = strtoul(colorString.c_str(), NULL, 16);
        setRGB(color);
        request->send(200, "text/plain", "Farbe gesetzt");
        } else {
            request->send(400, "text/plain", "Parameter 'color' fehlt");
        }
    });
}
