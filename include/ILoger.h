#ifndef ILOGGER_H
#define ILOGGER_H

#include <Arduino.h>

class ILogger {
public:
    virtual void log(const String& message) = 0;

    template<typename T>
    void log(const String& label, T value) {
        log(label + ": " + String(value));
    }

    virtual ~ILogger() {}
};

#endif // ILOGGER_H