#ifndef WEB_ROUTES_H
#define WEB_ROUTES_H

#include <ESPAsyncWebServer.h>
#include <SPIFFS.h>
#include "lib/bmp/bmp.h"

void setupWebRoutes(AsyncWebServer& server);

#endif
