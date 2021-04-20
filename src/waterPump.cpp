#include "waterpump.hpp"

WaterPump::WaterPump() {
    pinMode(RELAYPIN, OUTPUT);
    digitalWrite(RELAYPIN, LOW);
}

void WaterPump::turnOn() {
    digitalWrite(RELAYPIN, HIGH);
}

void WaterPump::turnOff() {
    digitalWrite(RELAYPIN, LOW);
}