#pragma once

#include "figure.h"

class Pentagon : public Figure {
public:
    Pentagon(const std::vector <Point>& points);

    double area() const override;

    Point getCenter() const override;

    static Pentagon* createPentagon(const std::vector <Point>& points);
};