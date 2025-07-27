#include "WebServer.h"
#include "TemperatureSensor.h"
#include "Logger.h"

#include "html_page.h"

#define WEB_SERVER_PORT 80

WebServer::WebServer(TemperatureSensor* sensor, ILogger* logger) 
    : server(WEB_SERVER_PORT), temperatureSensor(sensor), logger(logger) {}

void WebServer::begin() {
    server.on("/", [this]() {
        server.send(200, "text/html", HTML_PAGE);
        if (logger) logger->log("Served HTML page.");
    });

    server.on("/data", [this]() {
        float temp = temperatureSensor->read();
        String json = "{\"temperature\": " + String(temp, 1) + "}";
        server.send(200, "application/json", json);
        if (logger) logger->log("Sent JSON data: " + json);
    });

    server.begin();
    if (logger) logger->log("Web server started on port 80.");
}

void WebServer::handleClient() {
    server.handleClient();
}