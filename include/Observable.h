#ifndef OBSERVABLE_H
#define OBSERVABLE_H

#include <vector>
#include <algorithm>
#include "IObserver.h"
#include "IEventObserver.h"

template <typename T>
class Observable {
private:
    std::vector<IObserver<T>*> simpleObservers;
    std::vector<IEventObserver<T>*> eventObservers;

    String sourceId;
    String unit;
public:
    Observable(const String& id = "", const String& unit = "") 
        : sourceId(id), unit(unit) {}

    void addObserver(IObserver<T>* observer) {
        simpleObservers.push_back(observer);
    }
    void addObserver(IEventObserver<T>* observer) {
        eventObservers.push_back(observer);
    }

    void removeObserver(IObserver<T>* observer) {
        simpleObservers.erase(std::remove(simpleObservers.begin(), simpleObservers.end(), observer), simpleObservers.end());
    }
    void removeObserver(IEventObserver<T>* observer) {
        eventObservers.erase(std::remove(eventObservers.begin(), eventObservers.end(), observer), eventObservers.end());
    }


protected:
    void notifyObservers(const T& value) {
        for (auto* o : simpleObservers) {
            o->onUpdate(value);
        }
        if (!eventObservers.empty()) {
            SensorEvent<T> event{sourceId, value, millis(), unit};
            for (auto* o : eventObservers) {
                o->onUpdate(event);
            }
        }
    }
};

#endif //OBSERVABLE_H
