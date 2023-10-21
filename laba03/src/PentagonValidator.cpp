#include "../include/PentagonValidator.h"

void PentagonValidator::validate(std::vector<Point>& points) const {
    if (points.size() != 5) {
        throw std::invalid_argument("Pentagon must have exactly 5 points.");
    }

//    double sideLength = points[0].distanceBetweenPoints(points[1]);
//    for (int i = 1; i < 5; ++i) {
//        double currentSideLength = points[i].distanceBetweenPoints(points[(i + 1) % 5]);
//        if (fabs(currentSideLength - sideLength) > 1e-6) {
//            throw std::invalid_argument("Pentagon sides are not of equal length.");
//        }
//    }
//
//    bool isConvex = true;
//    for (int i = 0; i < 5; ++i) {
//        int j = (i + 1) % 5;
//        int k = (i + 2) % 5;
//        double crossProduct = IFigureValidator::calculateCrossProduct(points[i], points[j], points[k]);
//        if (crossProduct <= 0) {
//            isConvex = false;
//            break;
//        }
//    }
//
//    if (!isConvex) {
//        throw std::invalid_argument("Pentagon is not convex.");
//    }
}