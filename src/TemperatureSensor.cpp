#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor(uint8_t pin) : pin(pin), oneWire(pin), sensors(&oneWire) {}

void TemperatureSensor::init() {
    sensors.begin();
}

float TemperatureSensor::read() {
    sensors.requestTemperatures(); 
    return sensors.getTempCByIndex(0);
}