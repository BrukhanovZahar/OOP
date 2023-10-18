#pragma once

#include "figure.h"

class Octagon : public Figure {
public:
    Octagon(const std::vector <Point>& points);

    double area() const override;

    Point getCenter() const override;

    static Octagon* createOctagon(const std::vector <Point>& points);
};
