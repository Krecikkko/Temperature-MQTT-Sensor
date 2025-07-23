#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include <OneWire.h>
#include <DallasTemperature.h>

class ILogger;

class TemperatureSensor {
private:
    uint8_t pin;

    OneWire oneWire;
    DallasTemperature sensors;

    ILogger* logger;
public:
    TemperatureSensor(uint8_t pin, ILogger* logger  = nullptr);
    void init();
    float read();
};

#endif // TEMPERATURE_SENSOR_H