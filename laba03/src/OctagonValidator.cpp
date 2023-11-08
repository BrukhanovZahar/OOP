#include "../include/OctagonValidator.h"

void OctagonValidator::validate(std::vector <Point>& points) const {
    if (points.size() != 8) {
        throw std::invalid_argument("Octagon must have exactly 8 points.");
    }

//    double sideLength = points[0].distanceBetweenPoints(points[1]);
//    for (int i = 1; i < 8; ++i) {
//        double currentSideLength = points[i].distanceBetweenPoints(points[(i + 1) % 8]);
//        if (fabs(currentSideLength - sideLength) > 1e-6) {
//            throw std::invalid_argument("Octagon sides are not of equal length.");
//        }
//    }
//
//    bool isConvex = true;
//    for (int i = 0; i < 8; ++i) {
//        int j = (i + 1) % 8;
//        int k = (i + 2) % 8;
//        double crossProduct = IFigureValidator::calculateCrossProduct(points[i], points[j], points[k]);
//        if (crossProduct <= 0) {
//            isConvex = false;
//            break;
//        }
//    }
//
//    if (!isConvex) {
//        throw std::invalid_argument("Octagon is not convex.");
//    }
}