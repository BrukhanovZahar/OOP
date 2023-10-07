#include <gtest/gtest.h>
#include "../include/five_array.h"

class FiveAdditionTest : public testing::TestWithParam<std::tuple<std::string, std::string, std::string>> {
};

TEST_P(FiveAdditionTest, TestAddition) {
    std::string input1, input2, expectedOutput;
    std::tie(input1, input2, expectedOutput) = GetParam();

    Five five1(input1);
    Five five2(input2);
    Five expectedFive(expectedOutput);

    Five result = five1 + five2;

    ASSERT_EQ(result, expectedOutput);
}

INSTANTIATE_TEST_SUITE_P(
        FiveAdditionTestParameters,
        FiveAdditionTest,
        testing::Values(
                std::make_tuple("123", "321", "444"),
                std::make_tuple("4321", "1111", "10432"),
                std::make_tuple("000", "222", "222"),
                std::make_tuple("444", "444", "1443"),
                std::make_tuple("0", "0000", "0")
        )
);

class FiveSubtractionTest : public testing::TestWithParam<std::tuple<std::string, std::string, std::string>> {
};

TEST_P(FiveSubtractionTest, TestSubtraction) {
    std::string input1, input2, expectedOutput;
    std::tie(input1, input2, expectedOutput) = GetParam();

    Five five1(input1);
    Five five2(input2);
    Five expectedFive(expectedOutput);

    Five result = five1 - five2;

    ASSERT_EQ(result, expectedFive);
}

INSTANTIATE_TEST_SUITE_P(
        FiveSubtractionTestParameters,
        FiveSubtractionTest,
        testing::Values(
                std::make_tuple("321", "123", "143"),
                std::make_tuple("4321", "1111", "3210"),
                std::make_tuple("222", "000", "222"),
                std::make_tuple("40", "2", "33"),
                std::make_tuple("444", "444", "0")
        )
);

class FiveComparisonTest : public testing::TestWithParam<std::tuple<std::string, std::string, bool, bool, bool>> {
};

TEST_P(FiveComparisonTest, TestComparison) {
    std::string input1, input2;
    bool expectedGreater, expectedLess, expectedEqual;
    std::tie(input1, input2, expectedGreater, expectedLess, expectedEqual) = GetParam();

    Five five1(input1);
    Five five2(input2);

    bool isGreater = five1 > five2;
    bool isLess = five1 < five2;
    bool isEqual = five1 == five2;

    EXPECT_EQ(isGreater, expectedGreater);
    EXPECT_EQ(isLess, expectedLess);
    EXPECT_EQ(isEqual, expectedEqual);
}

INSTANTIATE_TEST_SUITE_P(
        FiveComparisonTestParameters,
        FiveComparisonTest,
        testing::Values(
                std::make_tuple("123", "321", false, true, false),
                std::make_tuple("4321", "1111", true, false, false),
                std::make_tuple("000", "222", false, true, false),
                std::make_tuple("444", "444", false, false, true)
        )
);

TEST(FiveConstructorTest, TestInitializerBuildConstructor) {
    Five five1, five2;

    five1 = Five::createBuilder().size(3).addValue('1').addValue('2').addValue('3').build();
    five2 = Five::createBuilder().size(3).build();

    EXPECT_EQ(five1.getValue(), "123");
    EXPECT_EQ(five1.getSize(), (size_t) 3);
    EXPECT_EQ(five2.getValue(), "0");
    EXPECT_EQ(five2.getSize(), (size_t) 1);
}

TEST(FiveConstructorTest, TestInitializerFillConstructor) {
    Five five1;

    five1 = Five::createBuilder().size(5).addValue('4').addValue('4').addValue('4').addValue('4').addValue('4').build();
    Five five2(5, '4');

    EXPECT_EQ(five1.getValue(), five2.getValue());
    EXPECT_EQ(five1.getSize(), five2.getSize());
}

TEST(FiveConstructorTest, TestInitializerListConstructor) {
    Five five1;

    five1 = Five::createBuilder().size(3).addValue('1').addValue('2').addValue('3').build();
    Five five2 = {'1', '2', '3'};

    EXPECT_EQ(five1.getValue(), five2.getValue());
    EXPECT_EQ(five1.getSize(), five2.getSize());
}

TEST(FiveConstructorTest, TestInitializerStringConstructor) {
    Five five1;

    five1 = Five::createBuilder().size(3).addValue('1').addValue('2').addValue('3').build();
    Five five2 ("123");

    EXPECT_EQ(five1.getValue(), five2.getValue());
    EXPECT_EQ(five1.getSize(), five2.getSize());
}

TEST(FiveConstructorTest, TestInitializerCopyConstructor) {
    Five five1;

    five1 = Five::createBuilder().size(3).addValue('1').addValue('2').addValue('3').build();
    Five five2 (five1);

    EXPECT_EQ(five1.getValue(), five2.getValue());
    EXPECT_EQ(five1.getSize(), five2.getSize());
}

TEST(FiveConstructorTest, TestInitializerMoveConstructor) {
    Five five1;

    five1 = Five::createBuilder().size(3).addValue('1').addValue('2').addValue('3').build();
    Five five3("123");
    Five five2 (std::move(five3));

    EXPECT_EQ(five1.getValue(), five2.getValue());
    EXPECT_EQ(five1.getSize(), five2.getSize());
}

TEST(FiveConstructorTest, TestCreateBuilderWithoutSize) {
    Five five;

    ASSERT_THROW({
                     five = Five::createBuilder().addValue('1').build();
                 }, std::logic_error);
}

TEST(FiveConstructorTest, TestInitializerFillConstructorWithExeption) {
    ASSERT_THROW({
                     Five five(3, 1);
                 }, std::invalid_argument);
}

TEST(FiveConstructorTest, TestInitializerListConstructorWithExeption) {
    ASSERT_THROW({
                     Five five({1, 2, 3});
                 }, std::invalid_argument);
}

TEST(FiveConstructorTest, TestInitializerStringConstructorWithExeption) {
    ASSERT_THROW({
                     Five five("012345");
                 }, std::invalid_argument);
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
