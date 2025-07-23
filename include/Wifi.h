#ifndef WIFI_H
#define WIFI_H

#include <ESP8266WiFi.h>

class ILogger;

class Wifi {
private:
    const char* ssid;
    const char* pass;

    ILogger* logger;
public:
    Wifi(const char* ssid, const char* pass, ILogger* logger = nullptr);
    
    void connect();
    bool isConnected();
    IPAddress getIP();
};

#endif // WIFI_H