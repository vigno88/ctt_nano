#pragma once
#include <Arduino.h>

// Not sure
#define RELAYPIN_PUMP2 16
#define RELAYPIN_PUMP1 17

class WaterPump {
public:
    WaterPump();
    void turnOn();
    void turnOff();
};