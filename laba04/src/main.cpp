#include <iostream>
#include "../include/Figure.h"
#include "../include/Pentagon.h"
#include "../include/Hexagon.h"
#include "../include/Octagon.h"
#include "../include/Array.h"

using namespace std;

int main() {
    std::vector<Point<double>> pentagonPoints = {Point(0.0, 0.0), Point(1.0, 0.0), Point(1.5, 1.0), Point(0.5, 2.0),
                                                 Point(0.0, 1.0)};
    std::vector<Point<double>> hexagonPoints = {Point(0.0, 0.0), Point(2.0, 0.0), Point(3.0, 1.0), Point(2.0, 2.0),
                                                Point(0.0, 2.0), Point(1.0, 1.0)};
    std::vector<Point<double>> octagonPoints = {Point(0.0, 0.0), Point(3.0, 0.0), Point(4.0, 1.0), Point(4.0, 3.0),
                                                Point(3.0, 4.0), Point(0.0, 4.0), Point(1.0, 3.0), Point(1.0, 1.0)};


    const shared_ptr<Figure<double>> pentagon = make_shared<Pentagon<double>>(pentagonPoints);
//    cout << pentagon->area() << endl;
    const shared_ptr<Figure<double>> hexagon = make_shared<Hexagon<double>>(hexagonPoints);
//    cout << hexagon->area() << endl;
    const shared_ptr<Figure<double>> octagon = make_shared<Octagon<double>>(octagonPoints);
//    cout << octagon->area() << endl;

//    Figure<double>* pentagon = Pentagon<double>().createFigureWithPoints(pentagonPoints);
//    cout << pentagon->area() << endl;
//    Figure<double>* hexagon = Hexagon<double>().createFigureWithPoints(hexagonPoints);
//    cout << hexagon->area() << endl;
//    Figure<double>* octagon = Octagon<double>().createFigureWithPoints(octagonPoints);
//    cout << octagon->area() << endl;

    myArray<shared_ptr<Figure<double>>> array;

    array.push_back(pentagon);
    array.push_back(hexagon);
    array.push_back(octagon);

    array.print();

    for (shared_ptr<Figure<double>>& elem : array) {

        cout << "Area: " << static_cast<double>(*elem) << endl;
        cout << "Center: " << elem->getCenter() << endl;

        for (Point<double> point : elem->getPoints()) {
            cout << point << endl;
        }

    }

    cout << array.length() << endl;

    array.remove(1);

    for (shared_ptr<Figure<double>>& elem : array) {

        cout << "Area: " << static_cast<double>(*elem) << endl;
        cout << "Center: " << elem->getCenter() << endl;

        for (Point<double> point : elem->getPoints()) {
            cout << point << endl;
        }

    }

    cout << array.length() << endl;

//    delete pentagon;
//    delete hexagon;
//    delete octagon;

    return 0;
}
