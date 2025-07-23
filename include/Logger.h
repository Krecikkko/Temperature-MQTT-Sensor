#ifndef LOGGER_H
#define LOGGER_H

#include <String>
#include "ILoger.h"

class Logger : public ILogger {
public:
    Logger();

    void begin(long baud  = 9600);
    void log(const String& message) override;
};

#endif // LOGGER_H