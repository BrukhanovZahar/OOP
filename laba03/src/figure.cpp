#include "../include/figure.h"
#include "../include/pentagon.h"
#include "../include/hexagon.h"
#include "../include/octagon.h"

Figure::Figure() {}

Figure::Figure(const std::vector <Point>& points) : _points(points){}

Figure::~Figure() {}

std::vector<Point> Figure::getPoints() const {
    return _points;
}

std::ostream& operator<<(std::ostream& out, const Figure& figure) {
    for(const Point& point : figure._points) {
        out << point << std::endl;
    }
    return out;
}

std::istream& operator>>(std::istream& input, Figure& figure) {
    figure._points.clear();
    Point point;
    while (input >> point) {
        figure._points.push_back(point);
    }
    return input;
}

Figure::operator double() const {
    return area();
}

Figure* Figure::createFigureWithPoints(const std::vector <Point>& points) {
    if(points.size() == 5) {
        return Pentagon::createPentagon(points);
    } else if (points.size() == 6) {
        return Hexagon::createHexagon(points);
    } else if (points.size() == 8) {
        return Octagon::createOctagon(points);
    } else {
        throw std::invalid_argument("Unsupported number of points for creating a figure.");
    }
}

double Figure::triangleArea(const Point& point1, const Point& point2, const Point& point3) const {
    double a = point1.distanceBetweenPoints(p2);
    double b = point2.distanceBetweenPoints(p3);
    double c = point3.distanceBetweenPoints(p1);
    double p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}