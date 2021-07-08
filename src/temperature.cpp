#include "temperature.hpp"

TemperatureSensor::TemperatureSensor() {
    // Use hardware SPI
    thermometer.begin(MAX31865_3WIRE);
}

float TemperatureSensor::readTemp() {
    return thermometer.temperature(RNOMINAL, RREF);
}