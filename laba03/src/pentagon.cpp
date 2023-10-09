#include "../include/pentagon.h"

Pentagon::Pentagon() : _first{0, 0}, _second{0, 0}, _third{0, 0}, _fourth{0, 0}, _fifth{0, 0} {}

Pentagon::Pentagon(const Point& first, const Point& second, const Point& third, const Point& fourth,
                   const Point& fifth) {

    if (!isValidPentagon(first, second, third, fourth, fifth)) {
        throw std::invalid_argument("Invalid pentagon: Points do not form a valid pentagon.");
    }

    _first = first;
    _second = second;
    _third = third;
    _fourth = fourth;
    _fifth = fifth;
}

Pentagon::Pentagon(const Pentagon& other) : _first{other._first}, _second{other._second},
                                            _third{other._third}, _fourth{other._fourth},
                                            _fifth{other._fifth} {
}

Pentagon::Pentagon(Pentagon&& other) : _first(std::move(other._first)), _second(std::move(other._second)),
                                       _third(std::move(other._third)), _fourth(std::move(other._fourth)),
                                       _fifth(std::move(other._fifth)) {
    other._first = Point();
    other._second = Point();
    other._third = Point();
    other._fourth = Point();
    other._fifth = Point();
}

bool Pentagon::isValidPentagon(const Point& first, const Point& second, const Point& third, const Point& fourth,
                               const Point& fifth) const {

    if (Point::areCollinear(first, second, third) ||
        Point::areCollinear(second, third, fourth) ||
        Point::areCollinear(third, fourth, fifth) ||
        Point::areCollinear(fourth, fifth, first) ||
        Point::areCollinear(fifth, first, second)) {
        return false;
    }

    double side1 = first.distanceBetweenPoints(second);
    double side2 = second.distanceBetweenPoints(third);
    double side3 = third.distanceBetweenPoints(fourth);
    double side4 = fourth.distanceBetweenPoints(fifth);
    double side5 = fifth.distanceBetweenPoints(first);

    if (side1 + side2 + side3 + side4 <= side5 ||
        side2 + side3 + side4 + side5 <= side1 ||
        side3 + side4 + side5 + side1 <= side2 ||
        side4 + side5 + side1 + side2 <= side3 ||
        side5 + side1 + side2 + side3 <= side4) {
        return false;
    }

    return true;
}

Pentagon::operator double() const {
    Point center = getCenter();
    double area = 0.0;

    area += triangleArea(_first, _second, center);
    area += triangleArea(_second, _third, center);
    area += triangleArea(_third, _fourth, center);
    area += triangleArea(_fourth, _fifth, center);
    area += triangleArea(_fifth, _first, center);

    return area;
}

double Pentagon::triangleArea(const Point& point1, const Point& point2, const Point& point3) const {
    double a = point1.distanceBetweenPoints(point2);
    double b = point2.distanceBetweenPoints(point3);
    double c = point3.distanceBetweenPoints(point1);

    double s = (a + b + c) / 2.0;
    return sqrt(s * (s - a) * (s - b) * (s - c));
}

Point Pentagon::getCenter() const {
    double centerX = (_first.getX() + _second.getX() + _third.getX() + _fourth.getX() + _fifth.getX()) / 5.0;
    double centerY = (_first.getY() + _second.getY() + _third.getY() + _fourth.getY() + _fifth.getY()) / 5.0;
    return Point(centerX, centerY);
}


Figure& Pentagon::operator=(const Figure& other) {
    if (this == &other) {
        return *this;
    }

    const Pentagon* otherPentagon = dynamic_cast<const Pentagon*>(&other);
    if (!otherPentagon) {
        throw std::invalid_argument("Cannot assign from a non-Pentagon Figure.");
    }

    _first = otherPentagon->_first;
    _second = otherPentagon->_second;
    _third = otherPentagon->_third;
    _fourth = otherPentagon->_fourth;
    _fifth = otherPentagon->_fifth;

    return *this;
}

Figure& Pentagon::operator=(Figure&& other) {
    if (this == &other) {
        return *this;
    }

    const Pentagon* otherPentagon = dynamic_cast<const Pentagon*>(&other);
    if (!otherPentagon) {
        throw std::invalid_argument("Cannot assign from a non-Pentagon Figure.");
    }

    _first = std::move(otherPentagon->_first);
    _second = std::move(otherPentagon->_second);
    _third = std::move(otherPentagon->_third);
    _fourth = std::move(otherPentagon->_fourth);
    _fifth = std::move(otherPentagon->_fifth);

    otherPentagon->_first = Point();
    otherPentagon->_second = Point();
    otherPentagon->_third = Point();
    otherPentagon->_fourth = Point();
    otherPentagon->_fifth = Point();

    return *this;
}

std::ostream& Pentagon::operator<<(std::ostream& out, const Figure& figure) {
    const Pentagon* pentagon = dynamic_cast<const Pentagon*>(&figure);
    if (pentagon) {
        out << "Pentagon vertices:" << std::endl;
        out << "1st Point: " << pentagon->_first << std::endl;
        out << "2nd Point: " << pentagon->_second << std::endl;
        out << "3rd Point: " << pentagon->_third << std::endl;
        out << "4th Point: " << pentagon->_fourth << std::endl;
        out << "5th Point: " << pentagon->_fifth << std::endl;
    } else {
        out << "Unknown figure type" << std::endl;
    }
    return out;
}


std::istream& Pentagon::operator>>(std::istream& input, Figure& figure) {
    Pentagon* pentagon = dynamic_cast<Pentagon*>(&figure);
    if (pentagon) {
        std::cout << "Enter coordinates for the 1st Point:" << std::endl;
        input >> pentagon->_first;
        std::cout << "Enter coordinates for the 2nd Point:" << std::endl;
        input >> pentagon->_second;
        std::cout << "Enter coordinates for the 3rd Point:" << std::endl;
        input >> pentagon->_third;
        std::cout << "Enter coordinates for the 4th Point:" << std::endl;
        input >> pentagon->_fourth;
        std::cout << "Enter coordinates for the 5th Point:" << std::endl;
        input >> pentagon->_fifth;
    } else {
        std::cout << "Unknown figure type" << std::endl;
    }
    return input;
}