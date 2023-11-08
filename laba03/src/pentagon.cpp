#include "../include/pentagon.h"

Pentagon::Pentagon(const std::vector <Point>& points) : Figure(points) {}

Pentagon& Pentagon::operator=(const Figure& other) {
    if (this != &other) {
        const Pentagon* otherPentagon = dynamic_cast<const Pentagon*>(&other);
        if (otherPentagon) {
            _points.clear();
            _points = other.getPoints();
        } else {
            throw std::invalid_argument("Invalid assignment. Expected Figure to be a Pentagon.");
        }
    }
    return *this;
}

Pentagon& Pentagon::operator=(Figure&& other) {
    Pentagon* otherPentagon = dynamic_cast<Pentagon*>(&other);
    if (otherPentagon) {
        _points = std::move(otherPentagon->_points);
    } else {
        throw std::invalid_argument("Invalid move assignment. Expected Figure to be a Pentagon.");
    }

    return *this;
}

bool Pentagon::operator==(const Figure& other) const {
    const Pentagon* otherPentagon = dynamic_cast<const Pentagon*>(&other);
    if (otherPentagon) {
        return _points == otherPentagon->_points;
    }
    return false;
}

std::istream& Pentagon::operator>>(std::istream& input) {
    _points.clear();
    for (int i = 0; i < 5; ++i) {
        Point point;
        input >> point;
        _points.push_back(point);
    }
    PentagonValidator validator;
    FigureValidator::validateFigure(static_cast<const IFigureValidator*> (&validator), _points);
    return input;
}


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

    for (const Point& point: _points) {
        centerX += point.getX();
        centerY += point.getY();
    }

    centerX /= 5.0;
    centerY /= 5.0;

    return Point(centerX, centerY);
}

Pentagon* Pentagon::createPentagon(const std::vector <Point>& points) {
    PentagonValidator pentagonValidator;
    FigureValidator::validateFigure(static_cast<const IFigureValidator*> (&pentagonValidator), points);
    return new Pentagon(points);
}