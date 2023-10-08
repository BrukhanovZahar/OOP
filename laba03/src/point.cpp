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

Point::Point(double x, double y) : _x{x}, _y{y} {}

double Point::getX() const {
    return _x;
}

double Point::getY() const {
    return _y;
}

bool operator==(const Point& first, const Point& second) {
    double epsilon = getEPS();
    return abs(first.getX() - second.getX()) < epsilon && abs(first.getY() - second.getY()) < epsilon;
}

std::ostream& operator<<(std::ostream& out, const Point& point) {
    out << "(" << point.getX() << " " << point.getY() << ")";
    return out;
}