#ifndef WEBSERVER_H
#define WEBSERVER_h

#include <ESP8266WebServer.h>

class TemperatureSensor;
class ILogger;

class WebServer {
private:
    ESP8266WebServer server;
    TemperatureSensor* temperatureSensor;
    ILogger* logger;
public:
    WebServer(TemperatureSensor* sensor, ILogger* logger = nullptr);
    void begin();
    void handleClient();
};

#endif // WEBSERVER_H