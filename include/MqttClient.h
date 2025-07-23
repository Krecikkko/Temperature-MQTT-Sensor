#ifndef MQTT_CLIENT_H
#define MQTT_CLIENT_H

#include <ESP8266WiFi.h>
#include <PubSubClient.h>

class ILogger;

class MqttClient {
private:
    const char* server;
    int port;
    const char* clientId;
    const char* user;
    const char* password;

    WiFiClient wifiClient;
    PubSubClient mqtt;
    ILogger* logger;
public:
    MqttClient(const char* server, int port, const char* clientId,
            const char* user = nullptr, const char* password = nullptr,
            ILogger* logger = nullptr);
    void init();
    void loop();
    void publish(const char* topic, const char* payload, bool retain = false);
};

#endif // MQTT_CLIENT_H