#include "pistons.hpp"

Pistons::Pistons() {
    pinMode(Piston1, OUTPUT);
    pinMode(Piston2, OUTPUT);
    pinMode(Piston3, OUTPUT);
    pinMode(Piston4, OUTPUT);
    pinMode(Piston5, OUTPUT);
    pinMode(Piston6, OUTPUT);
    // Open all pistons on boot up
    openPiston(1);
    openPiston(2);
    openPiston(3);
    openPiston(4);
    openPiston(5);
    openPiston(6);
}

void Pistons::closePiston(uint8_t i) {
    digitalWrite(mapPistons(i), HIGH);
}

void Pistons::openPiston(uint8_t i) {
    digitalWrite(mapPistons(i), LOW);
}

uint8_t Pistons::mapPistons(uint8_t i) {
    switch (i)
    {
    case 1:
        return Piston1;    
    case 2:
        return Piston2;  
    case 3:
        return Piston3;  
    case 4:
        return Piston4;  
    case 5:
        return Piston5;  
    case 6:
        return Piston6;  
    }
    return 0;
}