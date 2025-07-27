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
  mqtt.loop();

  // Publish temperature every 5 seconds
  static unsigned long lastPublish = 0;
  unsigned long now = millis();

  if (now - lastPublish > 5000) {
    lastPublish = now;

    float temperature = temperatureSensor.read();
    mqtt.publish("esp8266/temperature", String(temperature, 1).c_str());
  }

  // Send MQTT discovery config (once)
  if (!discoverySent && mqtt.isConnected()) {
    mqtt.publish(
      "homeassistant/sensor/esp8266_temp/config",
      R"({
        "name": "ESP8266 Temperature",
        "state_topic": "esp8266/temperature",
        "unit_of_measurement": "°C",
        "device_class": "temperature",
        "unique_id": "esp8266_temp_sensor"
      })",
      true
    );
    discoverySent = true;
  }
}
