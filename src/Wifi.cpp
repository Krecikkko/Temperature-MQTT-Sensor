#include "Wifi.h"
#include "Logger.h"

Wifi::Wifi(const char* ssid, const char* pass, ILogger* logger) : ssid(ssid), pass(pass), logger(logger) {}

void Wifi::connect() {
    // Attempt to connect to Wifi network
    WiFi.begin(ssid, pass);

    if (logger) logger->log("Attempting to connect to", ssid);

    unsigned long startAttemptTime = millis();
    const unsigned long timeout = 50000; // 10 seconds timeout

    while (WiFi.status() != WL_CONNECTED && millis() - startAttemptTime < timeout) {
        delay(500);
        if (logger) logger->log(".");
    }

    if (WiFi.status() != WL_CONNECTED) {
        if (logger) logger->log("WiFi connection failed.");
        abort();
    }

    if (logger) {
        logger->log("WiFi connected!");
        logger->log("IP", WiFi.localIP().toString());
    }
}

bool Wifi::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}

IPAddress Wifi::getIP() {
    return WiFi.localIP();
}