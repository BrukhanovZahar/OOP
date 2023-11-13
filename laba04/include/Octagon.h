#pragma once

#include "Figure.h"
#include "FigureValidator.h"
#include "OctagonValidator.h"

template<ScalarType T>
class Octagon : public Figure<T> {
public:
    Octagon(const std::vector<Point<T>>& points) : Figure<T>(points) {}

    Octagon<T>& operator=(const Figure <T>& other) override {
        if (this != &other) {
            const auto* otherOctagon = dynamic_cast<const Octagon*>(&other);
            if (otherOctagon) {
                this->_points.clear();
                this->_points = other.getPoints();
            } else {
                throw std::invalid_argument("Invalid assignment. Expected Figure to be a Pentagon.");
            }
        }
        return *this;
    }

    Octagon<T>& operator=(Figure <T>&& other) override {
        Octagon* otherOctagon = dynamic_cast<Octagon*>(&other);
        if (otherOctagon) {
            this->_points = std::move(otherOctagon->_points);
        } else {
            throw std::invalid_argument("Invalid move assignment. Expected Figure to be a Pentagon.");
        }

        return *this;
    }

    bool operator==(const Figure <T>& other) const override {
        const Octagon* otherOctagon = dynamic_cast<const Octagon*>(&other);
        if (otherOctagon) {
            return this->_points == otherOctagon->_points;
        }
        return false;
    }

    std::istream& operator>>(std::istream& input) override {
        this->_points.clear();
        for (int i = 0; i < 8; ++i) {
            Point<T> point;
            input >> point;
            this->_points.push_back(point);
        }
        OctagonValidator<T> validator;
        FigureValidator<T>::validateFigure(static_cast<const IFigureValidator<T>*> (&validator), this->_points);
        return input;
    }

    double area() const override {
        double area = 0.0;

        for (int i{0}; i < 6; ++i) {
            area += this->triangleArea(this->_points[0], this->_points[i + 1], this->_points[i + 2]);
        }

        return area;
    }

    Point<T> getCenter() const override {
        double centerX = 0.0;
        double centerY = 0.0;

        for (const Point<T>& point: this->_points) {
            centerX += point.getX();
            centerY += point.getY();
        }

        centerX /= 8.0;
        centerY /= 8.0;

        return Point<T>(centerX, centerY);
    }
//
//    static Octagon<T>* createOctagon(const std::vector<Point<T>>& points) {
//        OctagonValidator<T> octagonValidator;
//        FigureValidator<T>::validateFigure(static_cast<const IFigureValidator<T>*> (&octagonValidator), points);
//        return new Octagon<T>(points);
//    }

    Figure<T>* createFigureWithPoints(const std::vector<Point<T>>& points) const override {
        OctagonValidator<T> octagonValidator;
        FigureValidator<T>::validateFigure(static_cast<const IFigureValidator<T>*> (&octagonValidator), points);
        return new Octagon<T>(points);
    }
};