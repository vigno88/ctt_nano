#pragma once
#include <Arduino.h>

#define Piston1 7
#define Piston2 6
#define Piston3 5
#define Piston4 4
#define Piston5 3
#define Piston6 2

class Pistons {
public:
    Pistons();
    void openPiston(uint8_t index);
    void closePiston(uint8_t index);
private:
    uint8_t mapPistons(uint8_t index);
};