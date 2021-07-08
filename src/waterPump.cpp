#include "waterpump.hpp"

WaterPump::WaterPump() {
    pinMode(RELAYPIN_PUMP2, OUTPUT);
    pinMode(RELAYPIN_PUMP1, OUTPUT);
    digitalWrite(RELAYPIN_PUMP2, HIGH);
    digitalWrite(RELAYPIN_PUMP1, HIGH);
}

void WaterPump::turnOn() {
    digitalWrite(RELAYPIN_PUMP2, LOW);
    digitalWrite(RELAYPIN_PUMP1, LOW);
}

void WaterPump::turnOff() {
    digitalWrite(RELAYPIN_PUMP2, HIGH);
    digitalWrite(RELAYPIN_PUMP1, HIGH);
}