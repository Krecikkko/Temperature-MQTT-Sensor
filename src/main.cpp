#include <Arduino.h>

#include "config.h"
#include "TemperatureSensor.h"
#include "Logger.h"
#include "Wifi.h"
#include "MqttClient.h"
#include "WebServer.h"

#define PIN_TEMP D4

char wifi_ssid[] = WIFI_SSID;
char wifi_pass[] = WIFI_PASSWORD;

char mqtt_server[] = MQTT_SERVER;
int mqtt_port = MQTT_PORT;
char mqtt_user[] = MQTT_USER;
char mqtt_password[] = MQTT_PASSWORD;

bool discoverySent = false;

Logger logger;
Wifi wifi(wifi_ssid, wifi_pass, &logger);
TemperatureSensor temperatureSensor(PIN_TEMP, &logger);
MqttClient mqtt(mqtt_server, mqtt_port, "ESP8266-temp-sensor", mqtt_user, mqtt_password, &logger);
WebServer web(&temperatureSensor, &logger);

void setup() {
  logger.begin();
  wifi.connect();
  temperatureSensor.init();
  mqtt.init();
  web.begin();
}

void loop() {
  web.handleClient();
}
