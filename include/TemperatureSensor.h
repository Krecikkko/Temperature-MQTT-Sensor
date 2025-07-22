#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include <OneWire.h>
#include <DallasTemperature.h>

class TemperatureSensor {
private:
    uint8_t pin;

    OneWire oneWire;
    DallasTemperature sensors;
public:
    TemperatureSensor(uint8_t pin);
    void init();
    float read();
};

#endif // TEMPERATURE_SENSOR_H