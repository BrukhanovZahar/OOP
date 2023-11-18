#pragma once

#include "Figure.h"

template<ScalarType T>
class IFigureValidator {
public:
    virtual void validate(std::vector<Point<T>>& points) const = 0;
protected:
    static double calculateCrossProduct(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3) {
        return (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) -
               (p3.getX() - p1.getX()) * (p2.getY() - p1.getY());
    }
};