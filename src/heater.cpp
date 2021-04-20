#include "heater.hpp"

WaterHeater::WaterHeater(uint32_t t) {
    _cycleTime = t;
    _dutyCycle = 0;
    _isInDuty = 1;
    _lastTime = millis();
    _stepTime = _cycleTime / 256;
    pinMode(SSRHeat, OUTPUT);
    digitalWrite(SSRHeat, HIGH);
}

void WaterHeater::setIntensity(uint8_t i) {
    // Scale the intensity to a time between 0 and the cycleTime
    _dutyCycle = i * _stepTime;
}

void WaterHeater::run() {
    // Set the SSR to low if the _dutyCycle time as passed
    if(_isInDuty == 1 && millis() - _lastTime > _dutyCycle ) {
        _isInDuty = 0;
        digitalWrite(SSRHeat, LOW);
    } 
    // Set the SSR to high if the _cycleTime as passed
    if(_isInDuty == 0 && millis() - _lastTime > _cycleTime) {
        _isInDuty = 1;
        _lastTime = millis();
        digitalWrite(SSRHeat, HIGH);
    }
}