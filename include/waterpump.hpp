#pragma once
#include <Arduino.h>

// Not sure
#define RelayPin 14

class WaterPump {
public:
    WaterPump();
    void turnOn();
    void turnOff();
};