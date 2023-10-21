#pragma once

#include "IFigureValidator.h"

class HexagonValidator : public IFigureValidator {
public:
    void validate(std::vector<Point>& points) const override;
};