#pragma once

#include "figure.h"
#include "FigureValidator.h"
#include "HexagonValidator.h"

class Hexagon : public Figure {
public:
    Hexagon(const std::vector <Point>& points);

    Hexagon& operator=(const Figure& other) override;

    Hexagon& operator=(Figure&& other) override;

    bool operator==(const Figure& other) const override;

    std::istream& operator>>(std::istream& input) override;

    double area() const override;

    Point getCenter() const override;

    static Hexagon* createHexagon(const std::vector <Point>& points);
};