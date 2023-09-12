#include <iostream>

#ifdef MORE_INFORMATION
#include <chrono>
#endif

#include "remove_vowels.h"

using namespace std;
#ifdef MORE_INFORMATION
using namespace std::chrono;
#endif

int main() {
    string input_string;
#ifdef MORE_INFORMATION
    cout << "Введите строку: ";
#endif
    getline(cin, input_string);
#ifdef MORE_INFORMATION
    auto start = high_resolution_clock::now();
#endif
    string result_string = removeVowels(input_string);
#ifdef MORE_INFORMATION
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Строка без гласных: ";
#endif
    cout << result_string << endl;
#ifdef MORE_INFORMATION
    cout << "Время выполнения программы: " << duration.count() << " микросекунд" << endl;
#endif
    return 0;
}
