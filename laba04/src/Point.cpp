#include "../include/Point.h"
#include <cmath>

//template<ScalarType T>
//Point<T>::Point() : _x{0}, _y{0} {}

//template<ScalarType T>
//Point<T>::Point(const Point<T>& other) : _x(other._x), _y(other._y) {}

//template<ScalarType T>
//Point<T>::Point(T x, T y) : _x{x}, _y{y} {}
//
//template<ScalarType T>
//Point<T>& Point<T>::operator=(const Point<T>& other) {
//    _x = other._x;
//    _y = other._y;
//    return *this;
//}

//template<ScalarType T>
//Point<T>& Point<T>::operator=(Point<T>&& other) noexcept {
//    _x = other._x;
//    _y = other._y;
//    other._x = 0;
//    other._y = 0;
//    return *this;
//}

//template<ScalarType T>
//bool Point<T>::operator==(const Point<T>& other) const {
//    double epsilon{1.0};
//    while (1.0 + 0.5 * epsilon != 1.0) {
//        epsilon *= 0.5;
//    }
//    return abs(_x - other._x) < epsilon && abs(_y - other._y) < epsilon;
//}

//template<ScalarType T>
//T Point<T>::getX() const {
//    return _x;
//}
//
//template<ScalarType T>
//T Point<T>::getY() const {
//    return _y;
//}

//template<ScalarType T>
//double Point<T>::distanceBetweenPoints(const Point<T>& other) const {
//    return sqrt((_x - other._x) * (_x - other._x) + (_y - other._y) * (_y - other._y));
//}

//template<ScalarType T>
//void Point<T>::print(std::ostream& out) const {
//    out << "(" << _x << " " << _y << ")";
//}

//template<ScalarType T>
//std::ostream& operator<<(std::ostream& out, const Point<T>& point) {
//    out << "(" << point._x << " " << point._y << ")";
//    point.print(out);
//    return out;
//}

//template<ScalarType T>
//std::istream& operator>>(std::istream& input, Point<T>& point) {
//    input >> point._x >> point._y;
//    return input;
//}

//template<ScalarType T>
//bool Point<T>::areCollinear(const Point<T>& point1, const Point<T>& point2, const Point<T>& point3) {
//    double slope1 = (point2._y - point1._y) / (point2._x - point1._x);
//    double slope2 = (point3._y - point2._y) / (point3._x - point2._x);
//
//    return slope1 == slope2;
//}