#include "../include/point.h"
#include <cmath>

static double getEPS() {
    double epsilon{1.0};
    while (1.0 + 0.5 * epsilon != 1.0) {
        epsilon *= 0.5;
    }
    return epsilon;
}

Point::Point() : _x{0}, _y{0} {}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {}

Point::Point(double x, double y) : _x{x}, _y{y} {}

Point& Point::operator=(const Point& other) {
    _x = other._x;
    _y = other._y;
    return *this;
}

Point& Point::operator=(Point&& other) noexcept {
    _x = other._x;
    _y = other._y;
    other._x = 0;
    other._y = 0;
    return *this;
}

bool Point::operator==(const Point& other) const {
    double epsilon = getEPS();
    return abs(_x - other._x) < epsilon && abs(_y - other._y) < epsilon;
}

double Point::getX() const {
    return _x;
}

double Point::getY() const {
    return _y;
}

double Point::distanceBetweenPoints(const Point& other) const {
    return sqrt((_x - other._x) * (_x - other._x) + (_y - other._y) * (_y - other._y));
}

std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << "(" << point._x << " " << point._y << ")";
    return out;
}

std::istream& operator>>(std::istream& input, Point& point) {
    input >> point._x >> point._y;
    return input;
}

bool Point::areCollinear(const Point& point1, const Point& point2, const Point& point3) {
    double slope1 = (point2._y - point1._y) / (point2._x - point1._x);
    double slope2 = (point3._y - point2._y) / (point3._x - point2._x);

    return slope1 == slope2;
}