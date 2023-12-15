#pragma once

#include <string>

class Observer {
public:
    virtual ~Observer() = default;

    virtual void update(const std::string& message) = 0;
};