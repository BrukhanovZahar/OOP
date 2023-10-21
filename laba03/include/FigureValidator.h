#pragma once

#include "IFigureValidator.h"
#include "PentagonValidator.h"
#include "HexagonValidator.h"
#include "OctagonValidator.h"

class FigureValidator {
public:
    static void validateFigure(const IFigureValidator* validator, const std::vector<Point>& points);
};
