#ifndef IEVENTOBSERVER_H
#define IEVENTOBSERVER_H

#include "SensorEvent.h"

template <typename T>
class IEventObserver {
public:
    virtual void onUpdate(const SensorEvent<T>& event) = 0;
    virtual ~IEventObserver() {}
};

#endif // IEVENTOBSERVER_H