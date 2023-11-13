#pragma once

#include "Point.h"
#include <vector>
#include <iostream>


template<ScalarType T>
class Figure {
public:
    virtual ~Figure() = default;

    virtual Figure<T>& operator=(const Figure<T>& other) = 0;

    virtual Figure<T>& operator=(Figure<T>&& other) = 0;

    virtual bool operator==(const Figure<T>& other) const = 0;

    explicit operator double() const {
        return area();
    }

    virtual double area() const = 0;

    virtual Point<T> getCenter() const = 0;

    std::vector<Point<T>> getPoints() const {
        return _points;
    }

    template<ScalarType Y>
    friend std::ostream& operator<<(std::ostream& out, const Figure<Y>& figure) {
        for (const Point<T>& point: figure._points) {
            out << point << std::endl;
        }
        return out;
    }

    virtual std::istream& operator>>(std::istream& input) = 0;

    virtual Figure<T>* createFigureWithPoints(const std::vector<Point<T>>& points) const = 0;

protected:
    Figure() = default;

    explicit Figure(const std::vector<Point<T>>& points) : _points(points) {};

    double triangleArea(const Point<T>& point1, const Point<T>& point2, const Point<T>& point3) const {
        double a = point1.distanceBetweenPoints(point2);
        double b = point2.distanceBetweenPoints(point3);
        double c = point3.distanceBetweenPoints(point1);
        double p = (a + b + c) / 2.0;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }

    std::vector<Point<T>> _points;
};

