#include "TemperatureSensor.h"
#include "Logger.h"

TemperatureSensor::TemperatureSensor(uint8_t pin, ILogger* logger) : pin(pin), oneWire(pin), sensors(&oneWire), logger(logger) {}

void TemperatureSensor::init() {
    sensors.begin();
    if (logger) logger->log("Temperature sensor initialized.");
}

float TemperatureSensor::read() {
    sensors.requestTemperatures();
    float temp = sensors.getTempCByIndex(0);
    if (logger) logger->log("Temperature read", temp);
    return temp;
}