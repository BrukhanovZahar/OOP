#include "../include/hexagon.h"

Hexagon::Hexagon(const std::vector <Point>& points) : Figure(points) {}

double Hexagon::area() const {
    double area = 0.0;

    for (int i{0}; i < 4; ++i) {
        area += triangleArea(_points[0], _points[i + 1], _points[i + 2]);
    }

    return area;
}

Point Hexagon::getCenter() const {
    double centerX = 0.0;
    double centerY = 0.0;

    for (const Point& point: _points) {
        centerX += point.getX();
        centerY += point.getY();
    }

    centerX /= 6.0;
    centerY /= 6.0;

    return Point(centerX, centerY);
}

Hexagon* Hexagon::createHexagon(const std::vector <Point>& points) {
    HexagonValidator hexagonValidator;
    FigureValidator::validateFigure(hexagonValidator, points);
    return new Hexagon(points);
}