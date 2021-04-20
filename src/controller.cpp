#include "controller.hpp"

Controller::Controller(uint8_t target, uint64_t samplingDelay) {
    _samplingDelay = samplingDelay;
    _target = target;
    _previousTime = millis();
    _lastError = _cumError = 0;
}

double Controller::getOutput(double input) {
    // Divide by a thousand because in our case the elapsed time will be in second
    double elapsedTime = (double) (millis() - _previousTime)/1000;
    double error = (double)_target - input; 
    // integral
    _cumError += error * elapsedTime;
    // derivative
    double rateError = (error - _lastError)/elapsedTime;
    _lastError = error;
    _previousTime = millis(); 
    return kp*error + ki*_cumError + kd*rateError;
}

void Controller::setTarget(uint8_t t) {
    _target = t;
}