#include "../include/IFigureValidator.h"

double IFigureValidator::calculateCrossProduct(const Point& p1, const Point& p2, const Point& p3) {
    return (p2.getX() - p1.getX()) * (p3.getY() - p1.getY()) -
           (p3.getX() - p1.getX()) * (p2.getY() - p1.getY());
}