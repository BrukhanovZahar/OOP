#include <iostream>
#include "../include/Figure.h"
#include "../include/Pentagon.h"
#include "../include/Hexagon.h"

using namespace std;

int main() {
    std::vector<Point<double>> pentagonPoints = {Point(0.0, 0.0), Point(1.0, 0.0), Point(1.5, 1.0), Point(0.5, 2.0),
                                                 Point(0.0, 1.0)};
    std::vector<Point<double>> hexagonPoints = {Point(0.0, 0.0), Point(2.0, 0.0), Point(3.0, 1.0), Point(2.0, 2.0),
                                                Point(0.0, 2.0), Point(1.0, 1.0)};
    std::vector<Point<double>> octagonPoints = {Point(0.0, 0.0), Point(3.0, 0.0), Point(4.0, 1.0), Point(4.0, 3.0),
                                                Point(3.0, 4.0), Point(0.0, 4.0), Point(1.0, 3.0), Point(1.0, 1.0)};

    Figure<double>* figure = Pentagon<double>().createFigureWithPoints(pentagonPoints);
    cout << figure->area() << endl;
    Figure<double>* figure2 = Hexagon<double>().createFigureWithPoints(hexagonPoints);
    cout << figure2->area() << endl;

//    Figure<double>* pentagon = Figure<double>::createFigureWithPoints(pentagonPoints);
//    Figure<double>* hexagon = Figure<double>::createFigureWithPoints(hexagonPoints);
//    Figure<double>* octagon = Figure<double>::createFigureWithPoints(octagonPoints);

//    if (pentagon && hexagon && octagon) {
//        Figure<double>* figures[] = {pentagon, hexagon, octagon};
//        int size = 3;
//        for (auto& figure: figures) {
//            std::cout << "Area: " << static_cast<double>(*figure) << std::endl;
//            std::cout << "Center: " << static_cast<Point<double>>(figure->getCenter()) << std::endl;
//        }
//
//        int index = 1;
//        for (int i = 0; i < size; ++i) {
//            if (i == index) {
//                figures[i] = nullptr;
//            } else if (i > index) {
//                figures[i - 1] = figures[i];
//                figures[i] = nullptr;
//            }
//        }
//        size -= 1;
//
//        std::cout << "DELETE" << std::endl;
//        for (auto& figure: figures) {
//            std::cout << "Area: " << static_cast<double>(*figure) << std::endl;
//            std::cout << "Center: " << static_cast<Point<double>>(figure->getCenter()) << std::endl;
//        }
//    } else {
//        std::cout << "Failed to create one or more figures." << std::endl;
//    }

//    delete pentagon;
//    delete hexagon;
//    delete octagon;

    return 0;
}
