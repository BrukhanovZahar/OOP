//#include "../include/Figure.h"
//#include "../include/Pentagon.h"
//#include "../include/Hexagon.h"
//#include "../include/Octagon.h"
//
//template<ScalarType T>
//Figure<T>::Figure() {}
//
//template<ScalarType T>
//Figure<T>::Figure(const std::vector<Point<T>>& points) : _points(points) {}
//
//template<ScalarType T>
//std::vector<Point<T>> Figure<T>::getPoints() const {
//    return _points;
//}
//
//template<ScalarType T>
//std::ostream& operator<<(std::ostream& out, const Figure<T>& figure) {
//    for (const Point<T>& point: figure._points) {
//        out << point << std::endl;
//    }
//    return out;
//}
//
//template<ScalarType T>
//Figure<T>::operator double() const {
//    return area();
//}
//
//template<ScalarType T>
//Figure<T>* Figure<T>::createFigureWithPoints(const std::vector<Point<T>>& points) {
//    if (points.size() == 5) {
//        return Pentagon<T>::createPentagon(points);
//    } else if (points.size() == 6) {
//        return Hexagon<T>::createHexagon(points);
//    } else if (points.size() == 8) {
//        return Octagon<T>::createOctagon(points);
//    } else {
//        throw std::invalid_argument("Unsupported number of points for creating a figure.");
//    }
//}
//
//template<ScalarType T>
//double Figure<T>::triangleArea(const Point<T>& point1, const Point<T>& point2, const Point<T>& point3) const {
//    double a = point1.distanceBetweenPoints(point2);
//    double b = point2.distanceBetweenPoints(point3);
//    double c = point3.distanceBetweenPoints(point1);
//    double p = (a + b + c) / 2.0;
//    return sqrt(p * (p - a) * (p - b) * (p - c));
//}