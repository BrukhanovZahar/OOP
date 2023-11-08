#include "../include/HexagonValidator.h"

void HexagonValidator::validate(std::vector<Point>& points) const {
    if (points.size() != 6) {
        throw std::invalid_argument("Hexagon must have exactly 6 points.");
    }

//    double sideLength = points[0].distanceBetweenPoints(points[1]);
//    for (int i = 1; i < 6; ++i) {
//        double currentSideLength = points[i].distanceBetweenPoints(points[(i + 1) % 6]);
//        if (fabs(currentSideLength - sideLength) > 1e-6) {
//            throw std::invalid_argument("Hexagon sides are not of equal length.");
//        }
//    }
//
//    bool isConvex = true;
//    for (int i = 0; i < 6; ++i) {
//        int j = (i + 1) % 6;
//        int k = (i + 2) % 6;
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