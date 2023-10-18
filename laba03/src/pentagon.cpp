#include "../include/pentagon.h"

Pentagon::Pentagon(const std::vector <Point>& points) : Figure(points) {}

double Pentagon::area() const {
    double area = 0.0;

    for (int i{0}; i < 3; ++i) {
        area += triangleArea(_points[0], _points[i + 1], _points[i + 2]);
    }

    return area;
}

Point Pentagon::getCenter() const {
    double centerX = 0.0;
    double centerY = 0.0;

    for (const Point& point : _points) {
        centerX += point.getX();
        centerY += point.getY();
    }

    centerX /= 5.0;
    centerY /= 5.0;

    return Point(centerX, centerY);
}

Pentagon* Pentagon::createPentagon(const std::vector <Point>& points) {
    if (points.size() != 5) {
        throw std::invalid_argument("Pentagon must be created with exactly 5 points.");
    }
    return new Pentagon(points);
}