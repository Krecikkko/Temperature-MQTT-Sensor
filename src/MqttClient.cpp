#include "MqttClient.h"
#include "Logger.h"

MqttClient::MqttClient(const char* server, int port, const char* clientId,
            const char* user, const char* password, ILogger* logger)
    : server(server), port(port), clientId(clientId),
      user(user), password(password), mqtt(wifiClient), logger(logger) {}

void MqttClient::init() {
    mqtt.setServer(server, port);
    if (logger) logger->log("MQTT client configured.");
}

void MqttClient::loop() {
    if (!mqtt.connected()) {
        if (logger) logger->log("Connecting to MQTT...");
        bool connected;

        if (user && password) {
            connected = mqtt.connect(clientId, user, password);
        } else {
            connected = mqtt.connect(clientId);
        }

        if (connected) {
            if (logger) logger->log("MQTT connected.");
        } else {
            if (logger) logger->log("MQTT connection failed.");
        }
    }
    mqtt.loop();
}

void MqttClient::publish(const char* topic, const char* payload, bool retain) {
    if (mqtt.connected()) {
        mqtt.publish(topic, payload, retain);
        if (logger) logger->log("Published to " + String(topic), payload);
    } else if (logger) {
        logger->log("MQTT not connected. Cannot publish.");
    }
}

bool MqttClient::isConnected() {
    return mqtt.connected();
}

void MqttClient::onUpdate(const SensorEvent<float>& event) {
    String topic = "esp8266/" + event.sourceId;
    String payload = String(event.value, 2);
    
    publish(topic.c_str(), payload.c_str(), true);
}
