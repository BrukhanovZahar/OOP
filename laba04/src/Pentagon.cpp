//#include "../include/Pentagon.h"
//
//template<ScalarType T>
//Pentagon<T>::Pentagon(const std::vector <Point<T>>& points) : Figure<T>(points) {}
//
//template<ScalarType T>
//Pentagon<T>& Pentagon<T>::operator=(const Figure<T>& other) {
//    if (this != &other) {
//        const Pentagon* otherPentagon = dynamic_cast<const Pentagon*>(&other);
//        if (otherPentagon) {
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
//Pentagon<T>& Pentagon<T>::operator=(Figure<T>&& other) {
//    Pentagon* otherPentagon = dynamic_cast<Pentagon*>(&other);
//    if (otherPentagon) {
//        this->_points = std::move(otherPentagon->_points);
//    } else {
//        throw std::invalid_argument("Invalid move assignment. Expected Figure to be a Pentagon.");
//    }
//
//    return *this;
//}
//
//template<ScalarType T>
//bool Pentagon<T>::operator==(const Figure<T>& other) const {
//    const Pentagon* otherPentagon = dynamic_cast<const Pentagon*>(&other);
//    if (otherPentagon) {
//        return this->_points == otherPentagon->_points;
//    }
//    return false;
//}
//
//template<ScalarType T>
//std::istream& Pentagon<T>::operator>>(std::istream& input) {
//    this->_points.clear();
//    for (int i = 0; i < 5; ++i) {
//        Point<T> point;
//        input >> point;
//        this->_points.push_back(point);
//    }
//    PentagonValidator<T> validator;
//    FigureValidator<T>::validateFigure(static_cast<const IFigureValidator<T>*> (&validator), this->_points);
//    return input;
//}
//
//template<ScalarType T>
//double Pentagon<T>::area() const {
//    double area = 0.0;
//
//    for (int i{0}; i < 3; ++i) {
//        area += triangleArea(this->_points[0], this->_points[i + 1], this->_points[i + 2]);
//    }
//
//    return area;
//}
//
//template<ScalarType T>
//Point<T> Pentagon<T>::getCenter() const {
//    double centerX = 0.0;
//    double centerY = 0.0;
//
//    for (const Point<T>& point: this->_points) {
//        centerX += point.getX();
//        centerY += point.getY();
//    }
//
//    centerX /= 5.0;
//    centerY /= 5.0;
//
//    return Point<T>(centerX, centerY);
//}
//
//template<ScalarType T>
//Pentagon<T>* Pentagon<T>::createPentagon(const std::vector <Point<T>>& points) {
//    PentagonValidator<T> pentagonValidator;
//    FigureValidator<T>::validateFigure(static_cast<const IFigureValidator<T>*> (&pentagonValidator), points);
//    return new Pentagon<T>(points);
//}