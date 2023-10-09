#pragma once

#include "figure.h"
#include <iostream>

class Pentagon : public Figure {
public:
    Pentagon();

    Pentagon(const Point& first, const Point& second, const Point& third, const Point& fourth, const Point& fifth);

    Pentagon(const Pentagon& other);

    Pentagon(Pentagon&& other) noexcept;

    operator double() const override;

    Point getCenter() const override;

    Figure& operator=(const Figure& other) override;

    Figure& operator=(Figure&& other) override;

    std::ostream& operator<<(std::ostream& out, const Figure& figure) override;

    std::istream& operator>>(std::istream& input, Figure& figure) override;

private:
    Point _first;
    Point _second;
    Point _third;
    Point _fourth;
    Point _fifth;

    bool isValidPentagon(const Point& first, const Point& second, const Point& third, const Point& fourth,
                         const Point& fifth) const;

    double triangleArea(const Point& point1, const Point& point2, const Point& point3) const;
};