#pragma once

#include "Observer.h"
#include <fstream>
#include <stdexcept>

class FileObserver : public Observer {
public:
    void update(const std::string& message) override {
        std::ofstream file("log.txt", std::ios::app);

        if (!file.is_open()) {
            throw std::runtime_error("FileObserver failed to open log.txt for writing.");
        }

        file << "File Observer: " << message << std::endl;
        file.close();
    }
};