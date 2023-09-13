#include <iostream>

#include "remove_vowels.h"

using namespace std;

int main() {
    string input_string;
    getline(cin, input_string);
    string result_string = removeVowels(input_string);
    cout << result_string << endl;
    return 0;
}
