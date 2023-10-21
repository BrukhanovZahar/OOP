#include "../include/hexagon.h"

Hexagon::Hexagon(const std::vector <Point>& points) : Figure(points) {}

Hexagon& Hexagon::operator=(const Figure& other) {
    if (this != &other) {
        const Hexagon* otherHexagon = dynamic_cast<const Hexagon*>(&other);
        if (otherHexagon) {
            _points.clear();
            _points = other.getPoints();
        } else {
            throw std::invalid_argument("Invalid assignment. Expected Figure to be a Pentagon.");
        }
    }
    return *this;
}

Hexagon& Hexagon::operator=(Figure&& other) {
    Hexagon* otherHexagon = dynamic_cast<Hexagon*>(&other);
    if (otherHexagon) {
        _points = std::move(otherHexagon->_points);
    } else {
        throw std::invalid_argument("Invalid move assignment. Expected Figure to be a Pentagon.");
    }

    return *this;
}

bool Hexagon::operator==(const Figure& other) const {
    const Hexagon* otherHexagon = dynamic_cast<const Hexagon*>(&other);
    if (otherHexagon) {
        return _points == otherHexagon->_points;
    }
    return false;
}

std::istream& Hexagon::operator>>(std::istream& input) {
    _points.clear();
    for (int i = 0; i < 6; ++i) {
        Point point;
        input >> point;
        _points.push_back(point);
    }
    HexagonValidator validator;
    FigureValidator::validateFigure(static_cast<const IFigureValidator*> (&validator), _points);
    return input;
}

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
    FigureValidator::validateFigure(static_cast<const IFigureValidator*> (&hexagonValidator), points);
    return new Hexagon(points);
}