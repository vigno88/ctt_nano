#pragma once
#include <Arduino.h>

#define CLK 12
#define SDO 11
#define SDI 10
#define CS 9

// Temperature sensor based on the MAX31865
class TemperatureSensor {
    TemperatureSensor();
    float ReadTemp();

    // Depends if the library is blocking??
    void run();
};