#include "web_routes.h"
#include "lib/motor/motor.h"


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


    server.on("/move-servo", HTTP_GET, [](AsyncWebServerRequest *request) {
        int position = 30; // Default position
        int returnPosition = 0; // Return position
        int delayTime = 500; // Delay time in milliseconds
        if (request->hasParam("position")) {
            position = request->getParam("position")->value().toInt();
        }
        // Assuming your moveServoAndWait function and servo are properly set up
        moveServoAndWait(12, position, returnPosition, delayTime);
        request->send(200, "text/plain", "Servo moved");
    });

    server.on("/test", HTTP_GET, [](AsyncWebServerRequest *request) {
        request->send(200, "text/plain", "Test route is working!");
    });
}
