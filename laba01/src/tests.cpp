#include <gtest/gtest.h>
#include "remove_vowels.h"

TEST(VowelRemovalFunction, DataWithVowels01) {
    EXPECT_EQ(removeVowels("This website is for losers LOL!"), "Ths wbst s fr lsrs LL!");
}

TEST(VowelRemovalFunction, tDataWithVowels02) {
    EXPECT_EQ(removeVowels("qwe r t y uiop"), "qw r t  p");
}

TEST(VowelRemovalFunction, DataWithVowels03) {
    EXPECT_EQ(removeVowels("zaqws x?!cderfv"), "zqws x?!cdrfv");
}

TEST(VowelRemovalFunction, DataWithVowels04) {
    EXPECT_EQ(removeVowels("AEIOU"), "");
}

TEST(VowelRemovalFunction, DataWithNoVowels01) {
    EXPECT_EQ(removeVowels("lkjhgfds"), "lkjhgfds");
}

TEST(VowelRemovalFunction, DataWithNoVowels02) {
    EXPECT_EQ(removeVowels("dn't cmmnt"), "dn't cmmnt");
}

TEST(VowelRemovalFunction, DataWithNoVowels03) {
    EXPECT_EQ(removeVowels("12345/.,!±+_0"), "12345/.,!±+_0");
}

TEST(VowelRemovalFunction, DataWithNoVowels04) {
    EXPECT_EQ(removeVowels(""), "");
}

TEST(VowelCheckFunction, DataWithNoVowels01) {
    EXPECT_EQ(isVowel('f'), false);
}

TEST(VowelCheckFunction, DataWithNoVowels02) {
    EXPECT_EQ(isVowel('.'), false);
}

TEST(VowelCheckFunction, DataWithNoVowels03) {
    EXPECT_EQ(isVowel('2'), false);
}

TEST(VowelCheckFunction, DataWithVowels01) {
    EXPECT_EQ(isVowel('a'), true);
}

TEST(VowelCheckFunction, DataWithVowels02) {
    EXPECT_EQ(isVowel('o'), true);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}