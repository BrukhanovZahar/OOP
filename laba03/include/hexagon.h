#pragma once

#include "figure.h"

class Hexagon : public Figure {
public:
    Hexagon(const std::vector <Point>& points);

    double area() const override;

    Point getCenter() const override;

    static Hexagon* createHexagon(const std::vector <Point>& points);
};