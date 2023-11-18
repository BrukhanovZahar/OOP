#pragma once

#include "Figure.h"
#include "FigureValidator.h"
#include "PentagonValidator.h"

template<ScalarType T>
class Pentagon : public Figure<T> {
public:
    Pentagon() = default;

    Pentagon(const std::vector<Point<T>>& points) {
        PentagonValidator<T> pentagonValidator;
        FigureValidator<T>::validateFigure(static_cast<const IFigureValidator<T>*>(&pentagonValidator), points);
        this->_points = points;
    }

    Pentagon<T>& operator=(const Figure<T>& other) override {
        if (this != &other) {
            const Pentagon* otherPentagon = dynamic_cast<const Pentagon*>(&other);
            if (otherPentagon) {
                this->_points.clear();
                this->_points = other.getPoints();
            }
            else {
                throw std::invalid_argument("Invalid assignment. Expected Figure to be a Pentagon.");
            }
        }
        return *this;
    }

    Pentagon<T>& operator=(Figure<T>&& other) override {
        Pentagon* otherPentagon = dynamic_cast<Pentagon*>(&other);
        if (otherPentagon) {
            this->_points = std::move(otherPentagon->_points);
        }
        else {
            throw std::invalid_argument("Invalid move assignment. Expected Figure to be a Pentagon.");
        }

        return *this;
    }

    bool operator==(const Figure<T>& other) const override {
        const Pentagon* otherPentagon = dynamic_cast<const Pentagon*>(&other);
        if (otherPentagon) {
            return this->_points == otherPentagon->_points;
        }
        return false;
    }

    std::istream& operator>>(std::istream& input) override {
        this->_points.clear();
        //        for (int i = 0; i < 5; ++i) {
        //            Point<T> point;
        //            input >> point;
        //            this->_points.push_back(point);
        //        }
        PentagonValidator<T> validator;
        FigureValidator<T>::validateFigure(static_cast<const IFigureValidator<T>*>(&validator), this->_points);
        return input;
    }

    double area() const override {
        double area = 0.0;

        for (int i{0}; i < 3; ++i) {
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

        centerX /= 5.0;
        centerY /= 5.0;

        return Point<T>(centerX, centerY);
    }

    //    static Pentagon<T>* createPentagon(const std::vector<Point<T>>& points) {
    //        PentagonValidator<T> pentagonValidator;
    //        FigureValidator<T>::validateFigure(static_cast<const IFigureValidator<T>*> (&pentagonValidator), points);
    //        return new Pentagon<T>(points);
    //    }

    Figure<T>* createFigureWithPoints(const std::vector<Point<T>>& points) const override {
        PentagonValidator<T> pentagonValidator;
        FigureValidator<T>::validateFigure(static_cast<const IFigureValidator<T>*>(&pentagonValidator), points);
        return new Pentagon<T>(points);
    }
};
