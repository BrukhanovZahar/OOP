#include "remove_vowels.h"

bool isVowel(char c) {
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' || c == 'Y'
    );
}

string removeVowels(const string& input) {
    string result;
    for (const char c: input) {
        if (!isVowel(c)) {
            result += c;
        }
    }
    return result;
}