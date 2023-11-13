//#include "../include/Hexagon.h"
//
//template<ScalarType T>
//Hexagon<T>::Hexagon(const std::vector<Point<T>>& points) : Figure<T>(points) {}
//
//template<ScalarType T>
//Hexagon<T>& Hexagon<T>::operator=(const Figure<T>& other) {
//    if (this != &other) {
//        const Hexagon* otherHexagon = dynamic_cast<const Hexagon*>(&other);
//        if (otherHexagon) {
//            this->_points.clear();
//            this->_points = other.getPoints();
//        } else {
//            throw std::invalid_argument("Invalid assignment. Expected Figure to be a Pentagon.");
//        }
//    }
//    return *this;
//}
//
//template<ScalarType T>
//Hexagon<T>& Hexagon<T>::operator=(Figure<T>&& other) {
//    Hexagon* otherHexagon = dynamic_cast<Hexagon*>(&other);
//    if (otherHexagon) {
//        this->_points = std::move(otherHexagon->_points);
//    } else {
//        throw std::invalid_argument("Invalid move assignment. Expected Figure to be a Pentagon.");
//    }
//
//    return *this;
//}
//
//template<ScalarType T>
//bool Hexagon<T>::operator==(const Figure<T>& other) const {
//    const Hexagon* otherHexagon = dynamic_cast<const Hexagon*>(&other);
//    if (otherHexagon) {
//        return this->_points == otherHexagon->_points;
//    }
//    return false;
//}
//
//template<ScalarType T>
//std::istream& Hexagon<T>::operator>>(std::istream& input) {
//    this->_points.clear();
//    for (int i = 0; i < 6; ++i) {
//        Point<T> point;
//        input >> point;
//        this->_points.push_back(point);
//    }
//    HexagonValidator<T> validator;
//    FigureValidator<T>::validateFigure(static_cast<const IFigureValidator<T>*> (&validator), this->_points);
//    return input;
//}
//
//template<ScalarType T>
//double Hexagon<T>::area() const {
//    double area = 0.0;
//
//    for (int i{0}; i < 4; ++i) {
//        area += triangleArea(this->_points[0], this->_points[i + 1], this->_points[i + 2]);
//    }
//
//    return area;
//}
//
//template<ScalarType T>
//Point<T> Hexagon<T>::getCenter() const {
//    double centerX = 0.0;
//    double centerY = 0.0;
//
//    for (const Point<T>& point: this->_points) {
//        centerX += point.getX();
//        centerY += point.getY();
//    }
//
//    centerX /= 6.0;
//    centerY /= 6.0;
//
//    return Point<T>(centerX, centerY);
//}
//
//template<ScalarType T>
//Hexagon<T>* Hexagon<T>::createHexagon(const std::vector<Point<T>>& points) {
//    HexagonValidator<T> hexagonValidator;
//    FigureValidator<T>::validateFigure(static_cast<const IFigureValidator<T>*>(&hexagonValidator), points);
//    return new Hexagon<T>(points);
//}