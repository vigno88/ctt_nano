#include "temperature.hpp"

TemperatureSensor::TemperatureSensor() {
    // Use hardware SPI
    thermometer = Adafruit_MAX31865(CS);
    thermometer.begin(MAX31865_3WIRE);
}

float TemperatureSensor::readTemp() {
    return thermometer.temperature(100, 430.0);
}