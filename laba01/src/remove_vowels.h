#pragma once // говорит компилятору, что данный файл должен быть включен только один раз

#include <iostream>

using namespace std;

bool isVowel(char letter);
string removeVowels(const string& source_string);