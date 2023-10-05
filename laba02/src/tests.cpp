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

    ASSERT_EQ(result.toString(), expectedOutput);
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


int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
