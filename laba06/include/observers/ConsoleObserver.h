#pragma once

#include "Observer.h"
#include <iostream>

class ConsoleObserver : public Observer {
public:
    void update(const std::string& message) override {
        std::cout << "Console Observer: " << message << std::endl;
    }
};