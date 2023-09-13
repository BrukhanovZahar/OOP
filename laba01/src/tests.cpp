#include <gtest/gtest.h>
#include "remove_vowels.h"

class VowelRemovalTest : public testing::TestWithParam<std::tuple<std::string, std::string>> {
};

TEST_P(VowelRemovalTest, TestVowelRemoval) {
    std::string input, expectedOutput;
    std::tie(input, expectedOutput) = GetParam();
    ASSERT_EQ(removeVowels(input), expectedOutput);
}

INSTANTIATE_TEST_SUITE_P(
        VowelRemovalTestParameters,
        VowelRemovalTest,
        testing::Values(
                std::make_tuple("This website is for losers LOL!", "Ths wbst s fr lsrs LL!"),
                std::make_tuple("qwe r t y uiop", "qw r t  p"),
                std::make_tuple("zaqws x?!cderfv", "zqws x?!cdrfv"),
                std::make_tuple("AEIOU", ""),
                std::make_tuple("lkjhgfds", "lkjhgfds"),
                std::make_tuple("dn't cmmnt", "dn't cmmnt"),
                std::make_tuple("12345/.,!±+_0", "12345/.,!±+_0"),
                std::make_tuple("", "")
        )
);

class VowelCheckTest : public testing::TestWithParam<std::tuple<char, bool>> {
};

TEST_P(VowelCheckTest, TestIsVowel) {
    char inputChar;
    bool expectedValue;
    std::tie(inputChar, expectedValue) = GetParam();
    ASSERT_EQ(isVowel(inputChar), expectedValue);
}

INSTANTIATE_TEST_SUITE_P(
        VowelCheckTestParameters,
        VowelCheckTest,
        testing::Values(
                std::make_tuple('f', false),
                std::make_tuple('.', false),
                std::make_tuple('2', false),
                std::make_tuple('a', true),
                std::make_tuple('o', true)
        )
);

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}