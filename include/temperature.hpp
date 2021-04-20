#pragma once
#include <Arduino.h>
#include <Adafruit_MAX31865.h>

#define CS 10

// Temperature sensor based on the MAX31865
class TemperatureSensor {
public:
    TemperatureSensor();
    float readTemp();

    // Depends if the library is blocking??
    // void run();
private:
    Adafruit_MAX31865 thermometer = NULL;
};