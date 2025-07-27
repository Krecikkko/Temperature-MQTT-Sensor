#ifndef WEBSERVER_H
#define WEBSERVER_h

#include <ESP8266WebServer.h>

class TemperatureSensor;
class Logger;

class WebServer {
private:
    ESP8266WebServer server;
    TemperatureSensor* temperatureSensor;
    Logger* logger;
public:
    WebServer(TemperatureSensor* sensor, Logger* logger = nullptr);
    void begin();
    void handleClient();
};

#endif // WEBSERVER_H