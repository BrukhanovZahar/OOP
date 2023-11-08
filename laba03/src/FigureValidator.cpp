#include "../include/FigureValidator.h"

void FigureValidator::validateFigure(const IFigureValidator* validator, const std::vector <Point>& points) {
    if (validator == nullptr) {
        throw std::invalid_argument("Invalid validator provided.");
    }
    validator->validate(const_cast<std::vector<Point>&>(points));
}