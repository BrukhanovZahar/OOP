#pragma once

#include "point.h"
#include <vector>
#include <iostream>

class Figure {
public:
    virtual ~Figure() = default;

    explicit operator double() const;

    virtual double area() const = 0;

    virtual Point getCenter() const = 0;

    std::vector<Point> getPoints() const;

    friend std::ostream& operator<<(std::ostream& out, const Figure& figure);

    friend std::istream& operator>>(std::istream& input, Figure& figure);

//    static Figure* createFigureWithPoints(const std::vector<Point>& points);

protected:
    Figure();

    Figure(const std::vector <Point>& points);

    double triangleArea(const Point& point1, const Point& point2, const Point& point3) const;

    std::vector <Point> _points;
};