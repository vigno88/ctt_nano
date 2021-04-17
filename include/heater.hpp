#pragma once
#include <Arduino.h>

// Define the pin of the SSR

class WaterHeater {
public:
    WaterHeater();
    void setHeat(int heat);
    void run();
private:
    uint8_t _intensity;
};