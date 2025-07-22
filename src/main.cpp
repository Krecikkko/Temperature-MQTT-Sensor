#include <Arduino.h>

#include "config.h"
#include "TemperatureSensor.h"

#define PIN_TEMP D4

char wifi_ssid[] = WIFI_SSID;

TemperatureSensor temperatureSensor(PIN_TEMP);

void setup() {
  Serial.begin(9600);
  temperatureSensor.init();
  pinMode(PIN_TEMP, INPUT);
}

void loop() {
  Serial.print("Temperature: ");
  Serial.print(temperatureSensor.read());
}
