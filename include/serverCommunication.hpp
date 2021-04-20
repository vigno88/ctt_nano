 #pragma once
#include <Arduino.h>
#include "pistons.hpp"
#include "waterpump.hpp"
#include "controller.hpp"

const int stringLength = 30;

class ServerCommunication {
public:
    ServerCommunication(Controller *controller, WaterPump *pump, Pistons *pistons);
    void run();

private:
    Controller *_controller;
    WaterPump *_pump;
    Pistons *_pistons;

    void parsePacket(char* str);

    void parseParameter(char* arg);
    void parsePiston(char* arg);
    void parseWater(char* arg);
};