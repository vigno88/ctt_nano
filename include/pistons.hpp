#pragma once
#include <Arduino.h>

#define Piston1 2
#define Piston2 3
#define Piston3 4
#define Piston4 5
#define Piston5 6
#define Piston6 7

class Pistons {
public:
    Pistons();
    void openPiston(uint8_t index);
    void closePiston(uint8_t index);
private:
    uint8_t mapPistons(uint8_t index);
};