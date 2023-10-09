#pragma once

#include "point.h"
#include <iostream>

class Figure {
public:
    virtual operator double() const = 0;
    virtual Point getCenter() const = 0;
    virtual std::ostream& printCoordinates(std::ostream& out) const = 0;

    virtual Figure& operator=(const Figure & other) = 0;
    virtual Figure& operator=(Figure && other) = 0;
    virtual bool operator==(const Figure & other) const;

    virtual std::ostream& operator<<(std::ostream& out, const Figure & figure) = 0;
    virtual std::istream& operator>>(std::istream& input, Figure& figure) = 0;

    virtual ~Figure() = default;
};

std::ostream& operator<<(std::ostream& out, const Figure& figure);
std::istream& operator>>(std::istream& input, Figure& figure);