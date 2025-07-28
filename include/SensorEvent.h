#ifndef SENSOR_EVENT_H
#define SENSOR_EVENT_H

#include <Arduino.h>

template <typename T>
struct SensorEvent {
    String sourceId;
    T value;
    unsigned long timestamp;
    String unit;
};

#endif // SENSOR_EVENT_H