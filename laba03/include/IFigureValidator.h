#pragma once

#include "figure.h"

class IFigureValidator {
public:
    virtual void validate(std::vector<Point>& points) const = 0;
protected:
    static double calculateCrossProduct(const Point& p1, const Point& p2, const Point& p3);
};