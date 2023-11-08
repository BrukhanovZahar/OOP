#include <gtest/gtest.h>
#include "../include/figure.h"
#include "../include/pentagon.h"
#include "../include/hexagon.h"
#include "../include/octagon.h"
#include <vector>

class FigureTestArea : public testing::TestWithParam<std::tuple<Figure*, double>> {
};

TEST_P(FigureTestArea, TestAddition) {
    double expectedArea, shapeArea;

    auto params = GetParam();
    Figure* figure = get<0>(params);
    expectedArea = get<1>(params);

    shapeArea = figure->area();

    ASSERT_DOUBLE_EQ(expectedArea, shapeArea);
}

INSTANTIATE_TEST_SUITE_P(
        FiveAdditionTestParameters,
        FigureTestArea,
        testing::Values(
                std::make_tuple(Pentagon::createPentagon(
                        {Point(0.0, 0.0), Point(1.0, 0.0), Point(1.5, 1.0), Point(0.5, 2.0), Point(0.0, 1.0)}), 2.0),
                std::make_tuple(Hexagon::createHexagon(
                        {Point(0.0, 0.0), Point(2.0, 0.0), Point(3.0, 1.0), Point(2.0, 2.0), Point(0.0, 2.0),
                         Point(1.0, 1.0)}), 6.0),
                std::make_tuple(Octagon::createOctagon(
                        {Point(0.0, 0.0), Point(3.0, 0.0), Point(4.0, 1.0), Point(4.0, 3.0), Point(3.0, 4.0),
                         Point(0.0, 4.0), Point(1.0, 3.0), Point(1.0, 1.0)}), 18.0)
        )
);

class FigureTestCenter : public testing::TestWithParam<std::tuple<Figure*, Point>> {
};

TEST_P(FigureTestCenter, TestAddition) {
    Point expectedCenter, shapeCenter;

    auto params = GetParam();
    Figure* figure = get<0>(params);
    expectedCenter = get<1>(params);

    shapeCenter = figure->getCenter();

    ASSERT_EQ(expectedCenter, shapeCenter);
}

INSTANTIATE_TEST_SUITE_P(
        FiveAdditionTestParameters,
        FigureTestCenter,
        testing::Values(
                std::make_tuple(Pentagon::createPentagon(
                                        {Point(0.0, 0.0), Point(1.0, 0.0), Point(1.5, 1.0), Point(0.5, 2.0), Point(0.0, 1.0)}),
                                Point(0.6, 0.8)),
                std::make_tuple(Hexagon::createHexagon(
                        {Point(0.0, 0.0), Point(2.0, 0.0), Point(3.0, 1.0), Point(2.0, 2.0), Point(0.0, 2.0),
                         Point(1.0, 1.0)}), Point(1.3333333333333333, 1.0)),
                std::make_tuple(Octagon::createOctagon(
                        {Point(0.0, 0.0), Point(3.0, 0.0), Point(4.0, 1.0), Point(4.0, 3.0), Point(3.0, 4.0),
                         Point(0.0, 4.0), Point(1.0, 3.0), Point(1.0, 1.0)}), Point(2.0, 2.0))
        )
);

TEST(ConstructorTest, TestPentagon) {
    std::vector<Point> pentagonPoints = {Point(0.0, 0.0), Point(1.0, 0.0), Point(1.5, 1.0), Point(0.5, 2.0)};
    Pentagon* pentagon;
    ASSERT_THROW({
                     pentagon = Pentagon::createPentagon(pentagonPoints);
                 }, std::invalid_argument);
}

TEST(ConstructorTest, TestHexagon) {
    std::vector<Point> pentagonPoints = {Point(0.0, 0.0), Point(1.0, 0.0), Point(1.5, 1.0), Point(0.5, 2.0)};
    Hexagon* hexagon;
    ASSERT_THROW({
                     hexagon = Hexagon::createHexagon(pentagonPoints);
                 }, std::invalid_argument);
}

TEST(ConstructorTest, TestOctagon) {
    std::vector<Point> pentagonPoints = {Point(0.0, 0.0), Point(1.0, 0.0), Point(1.5, 1.0), Point(0.5, 2.0)};
    Octagon* octagon;
    ASSERT_THROW({
                     octagon = Octagon::createOctagon(pentagonPoints);
                 }, std::invalid_argument);
}

TEST(ConstructorTest, TestFigure) {
    std::vector<Point> pentagonPoints = {Point(0.0, 0.0), Point(1.0, 0.0), Point(1.5, 1.0), Point(0.5, 2.0)};
    Figure* figure;
    ASSERT_THROW({
                     figure = Figure::createFigureWithPoints(pentagonPoints);
                 }, std::invalid_argument);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
