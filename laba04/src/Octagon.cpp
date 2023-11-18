//#include "../include/Octagon.h"
//
//template<ScalarType T>
//Octagon<T>::Octagon(const std::vector <Point<T>>& points) : Figure<T>(points) {}
//
//template<ScalarType T>
//Octagon<T>& Octagon<T>::operator=(const Figure<T>& other) {
//    if (this != &other) {
//        const auto* otherOctagon = dynamic_cast<const Octagon*>(&other);
//        if (otherOctagon) {
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
//Octagon<T>& Octagon<T>::operator=(Figure<T>&& other) {
//    Octagon* otherOctagon = dynamic_cast<Octagon*>(&other);
//    if (otherOctagon) {
//        this->_points = std::move(otherOctagon->_points);
//    } else {
//        throw std::invalid_argument("Invalid move assignment. Expected Figure to be a Pentagon.");
//    }
//
//    return *this;
//}
//
//template<ScalarType T>
//bool Octagon<T>::operator==(const Figure<T>& other) const {
//    const Octagon* otherOctagon = dynamic_cast<const Octagon*>(&other);
//    if (otherOctagon) {
//        return this->_points == otherOctagon->_points;
//    }
//    return false;
//}
//
//template<ScalarType T>
//std::istream& Octagon<T>::operator>>(std::istream& input) {
//    this->_points.clear();
//    for (int i = 0; i < 8; ++i) {
//        Point<T> point;
//        input >> point;
//        this->_points.push_back(point);
//    }
//    OctagonValidator<T> validator;
//    FigureValidator<T>::validateFigure(static_cast<const IFigureValidator<T>*> (&validator), this->_points);
//    return input;
//}
//
//template<ScalarType T>
//double Octagon<T>::area() const {
//    double area = 0.0;
//
//    for (int i{0}; i < 6; ++i) {
//        area += triangleArea(this->_points[0], this->_points[i + 1], this->_points[i + 2]);
//    }
//
//    return area;
//}
//
//template<ScalarType T>
//Point<T> Octagon<T>::getCenter() const {
//    double centerX = 0.0;
//    double centerY = 0.0;
//
//    for (const Point<T>& point: this->_points) {
//        centerX += point.getX();
//        centerY += point.getY();
//    }
//
//    centerX /= 8.0;
//    centerY /= 8.0;
//
//    return Point<T>(centerX, centerY);
//}
//
//template<ScalarType T>
//Octagon<T>* Octagon<T>::createOctagon(const std::vector <Point<T>>& points) {
//    OctagonValidator<T> octagonValidator;
//    FigureValidator<T>::validateFigure(static_cast<const IFigureValidator<T>*> (&octagonValidator), points);
//    return new Octagon<T>(points);
//}