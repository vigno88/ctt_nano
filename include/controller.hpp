#pragma once

#include <Arduino.h>

class Controller {
public:
    const double kp = 2;
    const double ki = 0.5;
    const double kd = 1;

    Controller(uint8_t target, uint64_t samplingDelay);
    void setTarget(uint8_t target);
    double getOutput(double input);
private:
    uint64_t  _previousTime, _samplingDelay;
    uint8_t _target;
    double  _lastError, _cumError;
};

