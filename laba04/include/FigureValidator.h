#pragma once

#include "IFigureValidator.h"
#include "PentagonValidator.h"
#include "HexagonValidator.h"
#include "OctagonValidator.h"

template<ScalarType T>
class FigureValidator {
public:
    template<class Y>
    static void validateFigure(const IFigureValidator<Y>* validator, const std::vector<Point<T>>& points) {
        if (validator == nullptr) {
            throw std::invalid_argument("Invalid validator provided.");
        }
        validator->validate(const_cast<std::vector<Point<T>>&>(points));
    }
};
