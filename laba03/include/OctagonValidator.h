#pragma once

#include "IFigureValidator.h"

class OctagonValidator : public IFigureValidator {
public:
    void validate(std::vector<Point>& points) const override;
};