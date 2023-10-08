#pragma once

#include <iostream>

class Point {
public:
    Point();
    Point(double x, double y);
    double getX() const;
    double getY() const;

private:
    double _x;
    double _y;
};

bool operator== (const Point& first, const Point& second);
std::ostream& operator<< (std::ostream& out, const Point& point);