#ifndef WEBSERVER_H
#define WEBSERVER_h

#include <ESP8266WebServer.h>
#include "SensorEvent.h"
#include "IEventObserver.h"

class TemperatureSensor;
class ILogger;

class WebServer : public IEventObserver<float> {
private:
    ESP8266WebServer server;
    ILogger* logger;

    float latestTemperature = NAN;
public:
    WebServer(ILogger* logger = nullptr);
    void begin();
    void handleClient();

    void onUpdate(const SensorEvent<float>& event) override;
};

#endif // WEBSERVER_H