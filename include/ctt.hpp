#pragma once
#include <Arduino.h>    

#include "heater.hpp"
#include "pistons.hpp"
#include "serverCommunication.hpp"
#include "temperature.hpp"
#include "waterpump.hpp"

WaterHeater waterHeater();
Pistons pistons();
TemperatureSensor temperatureSensor();
WaterPump waterPump();

ServerCommunication communication(&waterHeater, &pistons, &temperatureSensor, &waterPump);