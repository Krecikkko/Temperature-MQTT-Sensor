#include <Arduino.h>

#include "config.h"
#include "TemperatureSensor.h"
#include "Logger.h"
#include "Wifi.h"
#include "MqttClient.h"

#define PIN_TEMP D4

char wifi_ssid[] = WIFI_SSID;
char wifi_pass[] = WIFI_PASSWORD;

char mqtt_server[] = MQTT_SERVER;
int mqtt_port = MQTT_PORT;
char mqtt_user[] = MQTT_USER;
char mqtt_password[] = MQTT_PASSWORD;

bool discoverySent = false;

Logger logger;
TemperatureSensor temperatureSensor(PIN_TEMP, &logger);
Wifi wifi(wifi_ssid, wifi_pass, &logger);
MqttClient mqtt(mqtt_server, mqtt_port, "ESP8266-temp-sensor", mqtt_user, mqtt_password, &logger);

void setup() {
  logger.begin();
  wifi.connect();
  temperatureSensor.init();
  mqtt.init();
}

void loop() {
  mqtt.loop();

  float temp = temperatureSensor.read();
  char buffer[32];
  snprintf(buffer, sizeof(buffer), "%.2f", temp);
  mqtt.publish("esp8266/temperature", String(temp).c_str());

  if (!discoverySent) {
    mqtt.publish("homeassistant/sensor/esp8266_temperature/config",
      R"({
        "name": "ESP8266 Temp",
        "state_topic": "esp8266/temperature",
        "unit_of_measurement": "°C",
        "device_class": "temperature",
        "unique_id": "esp8266_temp_sensor"
      })", true);
    discoverySent = true;
  }

  delay(5000);
}
