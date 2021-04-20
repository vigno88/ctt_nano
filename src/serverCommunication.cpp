#include "serverCommunication.hpp"

ServerCommunication::ServerCommunication(Controller *controller, WaterPump *pump, Pistons *pistons) {
    _controller = controller;
    _pump = pump;
    _pistons = pistons;
}

void ServerCommunication::run() {
    if(Serial.available()) {
        // Read packet from serial
        String packet = Serial.readStringUntil('\n');
        char str[stringLength];
        packet.toCharArray(str, stringLength);
        parsePacket(str);
    }
}

void ServerCommunication::parsePacket(char* arg) {
       // Split the packet
  char* token = strtok(arg, "#");
  void (ServerCommunication::*func_ptr)(char*);

  // Starts with "p" means that it is a parameter
  if(strcmp(token, "p") == 0) {
    func_ptr = &ServerCommunication::parseParameter;
  }
  // Starts with "pi" this means that it is a piston command
  if(strcmp(token, "pi") == 0) {
    func_ptr = &ServerCommunication::parsePiston;
  }
  if(strcmp(token, "w") == 0) {
      func_ptr = &ServerCommunication::parseWater;
  }
  (this->*func_ptr)(token);
}

void ServerCommunication::parseParameter(char* arg) {
    char* token = strtok(NULL, "#");
    if(token == NULL) {
        return;
    } else if(strcmp(token, "1") == 0) {
        token = strtok(NULL, "#");
        if(token == NULL) {
            return;
        }
        int value = atoi(token);
        _controller->setTarget(value);
    }

}

void ServerCommunication::parsePiston(char* arg) {
    char* token = strtok(NULL, "#");
    if(token == NULL) {
        return;
    }
    char* payload = strtok(NULL, "#");
    if(token == NULL) {
        return;
    }
    int index = atoi(token);
    if(index < 0 || index > 6) {
        return;
    }
    if(strcmp(payload, "open") == 0) {
        _pistons->openPiston(atoi(token));
        return;
    }
    if(strcmp(payload, "close") == 0) {
        _pistons->openPiston(atoi(token));
        return;
    }
}

void ServerCommunication::parseWater(char* arg) {
     char* token = strtok(NULL, "#");
    if(token == NULL) {
        return;
    }
    if(strcmp(token, "start")) {
        _pump->turnOn();
        return;
    }
    if(strcmp(token, "stop")) {
        _pump->turnOff();
        return;
    }
}