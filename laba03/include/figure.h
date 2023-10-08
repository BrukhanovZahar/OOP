#pragma once

#include "point.h"
#include <iostream>

class Figure {
public:
    virtual double getArea() const = 0;
    virtual Point getCenter() const = 0;
    virtual std::ostream& printCoordinates(std::ostream& out) const = 0;
    virtual ~Figure() = default;
};