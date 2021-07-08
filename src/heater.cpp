#include "heater.hpp"

WaterHeater::WaterHeater(uint32_t t) {
    _cycleTime = t;
    _dutyCycle = t;
    _isLow = 0;
    _lastTime = millis();
    _stepTime = _cycleTime / 255;
    pinMode(SSRHeat, OUTPUT);
    digitalWrite(SSRHeat, HIGH);
}

void WaterHeater::setIntensity(uint8_t i) {
    // Scale the intensity to a time between 0 and the cycleTime
    _dutyCycle = i * _stepTime;
    Serial.print("duty cycle: ");
    Serial.println(_dutyCycle);
}

void WaterHeater::run() {
    long currentTime = millis();
    // Set the SSR to low if the _dutyCycle time as passed
    if(currentTime - _lastTime > _dutyCycle  && currentTime - _lastTime < _cycleTime && _isLow < 1) {
        digitalWrite(SSRHeat, LOW);
        Serial.println("Set ssr to low");
        _isLow = 1;

    } 
    // Set the SSR to high if the _cycleTime as passed (reset the cycle)
    if( currentTime - _lastTime > _cycleTime && currentTime - _lastTime < _cycleTime) {
        _lastTime = millis();
        digitalWrite(SSRHeat, HIGH);
        Serial.println("Set ssr to high");
        _isLow = 0;
    }
}