#include "ctt.hpp"

void setup() {
  Serial.begin(115200);

  // Init things ..
}

void loop() {
  waterHeater.run();
  communication.run();
  run();
}