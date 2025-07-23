#include <Arduino.h>

#include "Logger.h"

Logger::Logger() {}

void Logger::begin(long baud) {
    Serial.begin(baud);
    while (!Serial) {}
}

void Logger::log(const String& message) {
    Serial.println(message);
}