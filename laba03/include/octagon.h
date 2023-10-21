#pragma once

#include "figure.h"
#include "FigureValidator.h"
#include "OctagonValidator.h"

class Octagon : public Figure {
public:
    Octagon(const std::vector <Point>& points);

    Octagon& operator=(const Figure& other) override;

    Octagon& operator=(Figure&& other) override;

    bool operator==(const Figure& other) const override;

    std::istream& operator>>(std::istream& input) override;

    double area() const override;

    Point getCenter() const override;

    static Octagon* createOctagon(const std::vector <Point>& points);
};
