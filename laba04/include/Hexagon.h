#pragma once

#include "Figure.h"
#include "FigureValidator.h"
#include "HexagonValidator.h"

template<ScalarType T>
class Hexagon : public Figure<T> {
public:
    Hexagon() = default;

    Hexagon(const std::vector<Point<T>>& points) {
        HexagonValidator<T> hexagonValidator;
        FigureValidator<T>::validateFigure(static_cast<const IFigureValidator<T>*>(&hexagonValidator), points);
        this->_points = points;
    }

    Hexagon<T>& operator=(const Figure<T>& other) override {
        if (this != &other) {
            const Hexagon* otherHexagon = dynamic_cast<const Hexagon*>(&other);
            if (otherHexagon) {
                this->_points.clear();
                this->_points = other.getPoints();
            } else {
                throw std::invalid_argument("Invalid assignment. Expected Figure to be a Pentagon.");
            }
        }
        return *this;
    }

    Hexagon<T>& operator=(Figure<T>&& other) override {
        Hexagon* otherHexagon = dynamic_cast<Hexagon*>(&other);
        if (otherHexagon) {
            this->_points = std::move(otherHexagon->_points);
        } else {
            throw std::invalid_argument("Invalid move assignment. Expected Figure to be a Pentagon.");
        }

        return *this;
    }

    bool operator==(const Figure<T>& other) const override {
        const Hexagon* otherHexagon = dynamic_cast<const Hexagon*>(&other);
        if (otherHexagon) {
            return this->_points == otherHexagon->_points;
        }
        return false;
    }

    std::istream& operator>>(std::istream& input) override {
        this->_points.clear();
        for (int i = 0; i < 6; ++i) {
            Point<T> point;
            input >> point;
            this->_points.push_back(point);
        }
        HexagonValidator<T> validator;
        FigureValidator<T>::validateFigure(static_cast<const IFigureValidator<T>*> (&validator), this->_points);
        return input;
    }

    double area() const override {
        double area = 0.0;

        for (int i{0}; i < 4; ++i) {
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

        centerX /= 6.0;
        centerY /= 6.0;

        return Point<T>(centerX, centerY);
    }

//    static Hexagon<T>* createHexagon(const std::vector<Point<T>>& points) {
//        HexagonValidator<T> hexagonValidator;
//        FigureValidator<T>::validateFigure(static_cast<const IFigureValidator<T>*>(&hexagonValidator), points);
//        return new Hexagon<T>(points);
//    }

    Figure<T>* createFigureWithPoints(const std::vector<Point<T>>& points) const override {
        HexagonValidator<T> hexagonValidator;
        FigureValidator<T>::validateFigure(static_cast<const IFigureValidator<T>*>(&hexagonValidator), points);
        return new Hexagon<T>(points);
    }
};
