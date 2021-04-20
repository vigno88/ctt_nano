#pragma once
#include <Arduino.h>

// Not sure
#define RELAYPIN 9

class WaterPump {
public:
    WaterPump();
    void turnOn();
    void turnOff();
};