#pragma once
#include <Arduino.h>

// Define the pin of the SSR
#define SSRHeat 9

class WaterHeater {
public:
    WaterHeater(uint32_t t);
    // setIntensity gets a value from 0 to 255. This is the value used for the SSR PWM
    void setIntensity(uint8_t i);
    void run();
private:
    uint8_t _isLow;
    uint32_t _dutyCycle;
    uint32_t _cycleTime;
    uint32_t _stepTime;

    uint64_t _lastTime;

};