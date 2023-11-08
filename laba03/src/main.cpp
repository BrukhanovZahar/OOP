#include <iostream>
#include "../include/figure.h"
#include "../include/pentagon.h"
#include "../include/hexagon.h"
#include "../include/octagon.h"

int main() {
    std::vector<Point> pentagonPoints = {Point(0.0, 0.0), Point(1.0, 0.0), Point(1.5, 1.0), Point(0.5, 2.0),
                                         Point(0.0, 1.0)};
    std::vector<Point> hexagonPoints = {Point(0.0, 0.0), Point(2.0, 0.0), Point(3.0, 1.0), Point(2.0, 2.0),
                                        Point(0.0, 2.0), Point(1.0, 1.0)};
    std::vector<Point> octagonPoints = {Point(0.0, 0.0), Point(3.0, 0.0), Point(4.0, 1.0), Point(4.0, 3.0),
                                        Point(3.0, 4.0), Point(0.0, 4.0), Point(1.0, 3.0), Point(1.0, 1.0)};

    Figure* pentagon = Figure::createFigureWithPoints(pentagonPoints);
    Figure* hexagon = Figure::createFigureWithPoints(hexagonPoints);
    Figure* octagon = Figure::createFigureWithPoints(octagonPoints);

    if (pentagon && hexagon && octagon) {
        Figure* figures[] = {pentagon, hexagon, octagon};
        int size = 3;
        for (auto& figure: figures) {
            std::cout << "Area: " << static_cast<double>(*figure) << std::endl;
            std::cout << "Center: " << figure->getCenter() << std::endl;
        }

        int index = 1;
        for (int i = 0; i < size; ++i) {
            if (i == index) {
                figures[i] = nullptr;
            } else if (i > index) {
                figures[i - 1] = figures[i];
                figures[i] = nullptr;
            }
        }
        size -= 1;

        std::cout << "DELETE" << std::endl;
        for (auto& figure: figures) {
            std::cout << "Area: " << static_cast<double>(*figure) << std::endl;
            std::cout << "Center: " << figure->getCenter() << std::endl;
        }
    } else {
        std::cout << "Failed to create one or more figures." << std::endl;
    }

    delete pentagon;
    delete hexagon;
    delete octagon;

    return 0;
}
