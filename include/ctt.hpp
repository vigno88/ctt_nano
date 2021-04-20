#pragma once
#include <Arduino.h>    

#include "heater.hpp"
#include <Wire.h>
#include "pistons.hpp"
#include "serverCommunication.hpp"
#include "temperature.hpp"
#include "waterpump.hpp"
#include "controller.hpp"

const uint32_t SAMPLE_DELAY = 20000;

WaterHeater waterHeater(SAMPLE_DELAY);
Pistons pistons;
TemperatureSensor temperatureSensor;
WaterPump waterPump;
Controller controller(21, 100);

ServerCommunication communication(&controller, &waterPump, &pistons);

double _lastTimeHeater = millis();
double _lastTimeTemp = millis();
const uint32_t SAMPLING_TIME_TEMP = 1000;

void run() {
    // PID loop
    if(millis() - _lastTimeHeater > SAMPLE_DELAY) {
        double output = controller.getOutput(temperatureSensor.readTemp());
        if (output > 255) {
            waterHeater.setIntensity(255);
        } else if(output < 0) {
            waterHeater.setIntensity(0);
        } else {
            waterHeater.setIntensity((uint8_t)output);
        }
        _lastTimeHeater = millis();
    }
    // Temperature monitoring loop
    if(millis() - _lastTimeTemp > SAMPLING_TIME_TEMP) {
        char str[30];
        sprintf(str, "m#%s#%.2f\n", "t",(double) temperatureSensor.readTemp());
        Serial.print(str);
        _lastTimeTemp = millis();
    }
}
