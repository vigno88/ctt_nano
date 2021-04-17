 #pragma once
#include <Arduino.h>
#include "heater.hpp"
#include "pistons.hpp"
#include "temperature.hpp"
#include "waterpump.hpp"

const int stringLength = 30;

class ServerCommunication {
public:
    ServerCommunication(WaterHeater *fan, Heater *heater, Motor *motor, Timer *timer);
    void run();

private:
    Motor *_motor;
    Fan *_fan;
    Heater *_heater;
    Timer *_timer;

    void setTemperature(char* arg);
    void setMotorSpeed(char* arg);
    void setRotationTime(char* arg);

    void parsePacket(char* str);

};