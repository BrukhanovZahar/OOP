#pragma once

#include "IFigureValidator.h"

class PentagonValidator : public IFigureValidator {
public:
    void validate(std::vector<Point>& points) const override;
};