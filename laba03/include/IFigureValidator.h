#pragma once

#include "figure.h"

class IFigureValidator {
public:
    virtual void validate(std::vector<Point> points) = 0;
protected:
    double calculateCrossProduct(const Point& p1, const Point& p2, const Point& p3);
};