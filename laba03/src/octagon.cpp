#include "../include/octagon.h"

Octagon::Octagon(const std::vector <Point>& points) : Figure(points) {}

double Octagon::area() const {
    double area = 0.0;

    for (int i{0}; i < 6; ++i) {
        area += triangleArea(_points[0], _points[i + 1], _points[i + 2]);
    }

    return area;
}

Point Octagon::getCenter() const {
    double centerX = 0.0;
    double centerY = 0.0;

    for (const Point& point : _points) {
        centerX += point.getX();
        centerY += point.getY();
    }

    centerX /= 8.0;
    centerY /= 8.0;

    return Point(centerX, centerY);
}

Octagon* Octagon::createOctagon(const std::vector <Point>& points) {
    if (points.size() != 8) {
        throw std::invalid_argument("Hexagon must be created with exactly 6 points.");
    }
    return new Octagon(points);
}