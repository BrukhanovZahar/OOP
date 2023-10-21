#pragma once

#include <iostream>

class Point {
public:
    Point();
    Point(const Point& other);
    Point(double x, double y);

    double getX() const;
    double getY() const;
    double distanceBetweenPoints(const Point& other) const;

    Point& operator=(const Point& other);
    Point& operator=(Point&& other) noexcept ;
    bool operator==(const Point& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Point& point);
    friend std::istream& operator>>(std::istream& input, Point& point);

    static bool areCollinear(const Point& point1, const Point& point2, const Point& point3);

private:
    double _x;
    double _y;
};

std::ostream& operator<<(std::ostream& out, const Point& point);
std::istream& operator>>(std::istream& input, Point& point);