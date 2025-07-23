#include <Arduino.h>

#include "config.h"
#include "TemperatureSensor.h"
#include "Logger.h"
#include "Wifi.h"

#define PIN_TEMP D4

char wifi_ssid[] = WIFI_SSID;
char wifi_pass[] = WIFI_PASSWORD;

Logger logger;
TemperatureSensor temperatureSensor(PIN_TEMP, &logger);
Wifi wifi(wifi_ssid, wifi_pass, &logger);

void setup() {
  logger.begin();
  temperatureSensor.init();
  pinMode(PIN_TEMP, INPUT);
  wifi.connect();
}

void loop() {
  temperatureSensor.read();
  delay(1000);
}
