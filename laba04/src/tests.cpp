#include <gtest/gtest.h>
#include "../include/Figure.h"
#include "../include/Pentagon.h"
#include "../include/Hexagon.h"
#include "../include/Octagon.h"

class FigureTestArea : public testing::TestWithParam<std::tuple<Figure<double>*, double>> {
};

TEST_P(FigureTestArea, TestAddition) {
    double expectedArea, shapeArea;

    auto params = GetParam();
    Figure<double>* figure = std::get<0>(params);
    expectedArea = std::get<1>(params);

    shapeArea = figure->area();

    ASSERT_DOUBLE_EQ(expectedArea, shapeArea);
}

INSTANTIATE_TEST_SUITE_P(
        FiveAdditionTestParameters,
        FigureTestArea,
        testing::Values(
                std::make_tuple(Pentagon<double>().createFigureWithPoints(
                        {Point(0.0, 0.0), Point(1.0, 0.0), Point(1.5, 1.0), Point(0.5, 2.0), Point(0.0, 1.0)}), 2.0),
                std::make_tuple(Hexagon<double>().createFigureWithPoints(
                        {Point(0.0, 0.0), Point(2.0, 0.0), Point(3.0, 1.0), Point(2.0, 2.0), Point(0.0, 2.0),
                         Point(1.0, 1.0)}), 6.0),
                std::make_tuple(Octagon<double>().createFigureWithPoints(
                        {Point(0.0, 0.0), Point(3.0, 0.0), Point(4.0, 1.0), Point(4.0, 3.0), Point(3.0, 4.0),
                         Point(0.0, 4.0), Point(1.0, 3.0), Point(1.0, 1.0)}), 18.0)
        )
);

class FigureTestCenter : public testing::TestWithParam<std::tuple<Figure<double>*, Point<double>>> {
};

TEST_P(FigureTestCenter, TestAddition) {
        Point<double> expectedCenter, shapeCenter;

        auto params = GetParam();
        Figure<double>* figure = std::get<0>(params);
        expectedCenter = std::get<1>(params);

        shapeCenter = figure->getCenter();

        ASSERT_EQ(expectedCenter, shapeCenter);
}

INSTANTIATE_TEST_SUITE_P(
        FiveAdditionTestParameters,
        FigureTestCenter,
        testing::Values(
                std::make_tuple(Pentagon<double>().createFigureWithPoints(
                                        {Point(0.0, 0.0), Point(1.0, 0.0), Point(1.5, 1.0), Point(0.5, 2.0), Point(0.0, 1.0)}),
                                Point(0.6, 0.8)),
                std::make_tuple(Hexagon<double>().createFigureWithPoints(
                        {Point(0.0, 0.0), Point(2.0, 0.0), Point(3.0, 1.0), Point(2.0, 2.0), Point(0.0, 2.0),
                         Point(1.0, 1.0)}), Point(1.3333333333333333, 1.0)),
                std::make_tuple(Octagon<double>().createFigureWithPoints(
                        {Point(0.0, 0.0), Point(3.0, 0.0), Point(4.0, 1.0), Point(4.0, 3.0), Point(3.0, 4.0),
                         Point(0.0, 4.0), Point(1.0, 3.0), Point(1.0, 1.0)}), Point(2.0, 2.0))
        )
);

TEST(ConstructorTest, TestPentagon) {
        const std::vector<Point<double>> pentagonPoints = {Point(0.0, 0.0), Point(1.0, 0.0), Point(1.5, 1.0), Point(0.5, 2.0)};
        Pentagon<double>* pentagon;
        ASSERT_THROW({
                         pentagon = dynamic_cast<Pentagon<double>*>(Pentagon<double>().createFigureWithPoints(pentagonPoints));
                     }, std::invalid_argument);
}

TEST(ConstructorTest, TestHexagon) {
        const std::vector<Point<double>> pentagonPoints = {Point(0.0, 0.0), Point(1.0, 0.0), Point(1.5, 1.0), Point(0.5, 2.0)};
        Hexagon<double>* hexagon;
        ASSERT_THROW({
                         hexagon = dynamic_cast<Hexagon<double>*>(Hexagon<double>().createFigureWithPoints(pentagonPoints));
                     }, std::invalid_argument);
}

TEST(ConstructorTest, TestOctagon) {
        std::vector<Point<double>> pentagonPoints = {Point(0.0, 0.0), Point(1.0, 0.0), Point(1.5, 1.0), Point(0.5, 2.0)};
        Octagon<double>* octagon;
        ASSERT_THROW({
                         octagon = dynamic_cast<Octagon<double>*>(Octagon<double>().createFigureWithPoints(pentagonPoints));
                     }, std::invalid_argument);
}


int main(int argc, char** argv) {
        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}