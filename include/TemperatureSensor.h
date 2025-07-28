#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include <OneWire.h>
#include <DallasTemperature.h>
#include <vector>

#include "Observable.h"

class ILogger;

class TemperatureSensor : public Observable<float> {
private:
    uint8_t pin;

    OneWire oneWire;
    DallasTemperature sensors;

    ILogger* logger;
public:
    TemperatureSensor(uint8_t pin, ILogger* logger  = nullptr);
    void init();
    float read();

    // Read temperature and notify observers
    void notify();
};

#endif // TEMPERATURE_SENSOR_H