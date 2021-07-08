#include "ctt.hpp"

void setup() {
  Serial.begin(115200);
  temperatureSensor = TemperatureSensor();
  
}

void loop() {
  waterHeater.run();
  communication.run();
  run();
}