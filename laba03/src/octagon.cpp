#include "../include/octagon.h"

Octagon::Octagon(const std::vector <Point>& points) : Figure(points) {}

Octagon& Octagon::operator=(const Figure& other) {
    if (this != &other) {
        const auto* otherOctagon = dynamic_cast<const Octagon*>(&other);
        if (otherOctagon) {
            _points.clear();
            _points = other.getPoints();
        } else {
            throw std::invalid_argument("Invalid assignment. Expected Figure to be a Pentagon.");
        }
    }
    return *this;
}

Octagon& Octagon::operator=(Figure&& other) {
    Octagon* otherOctagon = dynamic_cast<Octagon*>(&other);
    if (otherOctagon) {
        _points = std::move(otherOctagon->_points);
    } else {
        throw std::invalid_argument("Invalid move assignment. Expected Figure to be a Pentagon.");
    }

    return *this;
}

bool Octagon::operator==(const Figure& other) const {
    const Octagon* otherOctagon = dynamic_cast<const Octagon*>(&other);
    if (otherOctagon) {
        return _points == otherOctagon->_points;
    }
    return false;
}

std::istream& Octagon::operator>>(std::istream& input) {
    _points.clear();
    for (int i = 0; i < 8; ++i) {
        Point point;
        input >> point;
        _points.push_back(point);
    }
    OctagonValidator validator;
    FigureValidator::validateFigure(static_cast<const IFigureValidator*> (&validator), _points);
    return input;
}

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

    for (const Point& point: _points) {
        centerX += point.getX();
        centerY += point.getY();
    }

    centerX /= 8.0;
    centerY /= 8.0;

    return Point(centerX, centerY);
}

Octagon* Octagon::createOctagon(const std::vector <Point>& points) {
    OctagonValidator octagonValidator;
    FigureValidator::validateFigure(static_cast<const IFigureValidator*> (&octagonValidator), points);
    return new Octagon(points);
}