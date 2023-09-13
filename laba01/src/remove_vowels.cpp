#include "remove_vowels.h"

bool isVowel(char letter) {
    return (letter == 'a' || letter == 'e' || letter == 'i' || letter == 'o' || letter == 'u' || letter == 'y' ||
            letter == 'A' || letter == 'E' || letter == 'I' || letter == 'O' || letter == 'U' || letter == 'Y'
    );
}

string removeVowels(const string& source_string) {
    string result_string;
    for (const char letter: source_string) {
        if (!isVowel(letter)) {
            result_string += letter;
        }
    }
    return result_string;
}