#include "WebServer.h"
#include "TemperatureSensor.h"
#include "Logger.h"

#define WEB_SERVER_PORT 80

WebServer::WebServer(TemperatureSensor* sensor, Logger* logger) 
    : server(WEB_SERVER_PORT), temperatureSensor(sensor), logger(logger) {}

void WebServer::begin() {
    server.on("/", [this]() {
        float temp = temperatureSensor->read();
        String html = "<html><body><h1>Temperature: " + String(temp) + " °C</h1></body></html>";
        server.send(200, "text/html", html);
        if (logger) logger->log("Server temperature web page.");
    });

    server.begin();
    if (logger) logger->log("Web server started on port 80.");
}

void WebServer::handleClient() {
    server.handleClient();
}