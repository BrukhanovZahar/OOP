#pragma once

#include "figure.h"
#include "FigureValidator.h"
#include "PentagonValidator.h"

class Pentagon : public Figure {
public:
    Pentagon(const std::vector <Point>& points);

    Pentagon& operator=(const Figure& other) override;

    Pentagon& operator=(Figure&& other) override;

    bool operator==(const Figure& other) const override;

    std::istream& operator>>(std::istream& input) override;

    double area() const override;

    Point getCenter() const override;

    static Pentagon* createPentagon(const std::vector <Point>& points);
};