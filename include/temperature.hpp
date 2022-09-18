#pragma once
#include <Arduino.h>
#include <Adafruit_MAX31865.h>

#define CS 10
// The value of the Rref resistor. Use 430.0 for PT100 and 4300.0 for PT1000
#define RREF      430.0
// The 'nominal' 0-degrees-C resistance of the sensor
// 100.0 for PT100, 1000.0 for PT1000
#define RNOMINAL  100.0

static Adafruit_MAX31865 thermometer = Adafruit_MAX31865(10,11,12,13);

// Temperature sensor based on the MAX31865
class TemperatureSensor {
public:
    TemperatureSensor();
    float readTemp();
    void readError();
};