# Temperature MQTT Sensor

A simple project for reading temperature data from a DS18B20 sensor and publishing it to an MQTT broker.

## Features

- Reads temperature data from a DS18B20 sensor
- Publishes sensor data to a configurable MQTT topic
- Easy configuration for Wi-Fi and MQTT settings
- Lightweight and suitable for microcontrollers (e.g., ESP8266, ESP32)

## Structure
![UML Diagram](/assets/uml_diagram.png)

## Getting Started

### Prerequisites

- Microcontroller ([ESP8266](https://www.espressif.com/en/products/socs/esp8266) / [ESP32](https://www.espressif.com/en/products/socs/esp32) recommended)
- [DS18B20 temperature sensor](https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf)
- MQTT broker (e.g., [EMQX](https://www.emqx.com/en/), [Mosquitto](https://mosquitto.org/))
- [Arduino IDE](https://www.arduino.cc/en/software) or [PlatformIO](https://platformio.org/)

### Installation

1. Clone this repository:
    ```bash
    git clone https://github.com/yourusername/Temperature-MQTT-Sensor.git
    ```
2. Open the project in your preferred IDE.
3. Install required libraries (see `platformio.ini` or `lib_deps`).
4. Configure Wi-Fi and MQTT settings in `config.h`.
5. Upload the code to your device.

## Usage

- Connect your DS18B20 sensor as described in the wiring diagram.
- Power up the device.
- Monitor MQTT messages on your broker under the configured topic.

## Configuration

Edit `config.h` to set:

- Wi-Fi SSID and password
- MQTT broker address and port
- MQTT topic
- Sensor pin

## License

This project is licensed under the MIT License.

## Acknowledgments

- [Adafruit DHT library](https://github.com/adafruit/DHT-sensor-library)
- [PubSubClient](https://github.com/knolleary/pubsubclient)
- [EMQX MQTT Broker](https://www.emqx.com/en/)
- [Mosquitto MQTT Broker](https://mosquitto.org/)
- Community contributors

Designed for educational, smart home, and IoT projects.
Made with ❤️ using ESP8266 and C++ by Krecikkko.
