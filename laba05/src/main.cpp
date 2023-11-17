#include "../include/DequeAllocator.h"
#include "../include/DynamicArray.h"
#include <iostream>
#include <map>

int factorial(int number) {
    return (number == 0 || number == 1) ? 1 : number * factorial(number - 1);
}

int main() {
    std::map<int, int, std::less<int>, DequeAllocator<std::pair<const int, int>>> myMap;

    for (int i{0}; i < 10; ++i) {
        myMap[i] = factorial(i);
    }

    for (auto& elem: myMap) {
        std::cout << elem.first << ' ' << elem.second << std::endl;
    }

    DynamicArray<int, DequeAllocator<int>> deque;

    for (int i{0}; i < 10; ++i) {
        deque.push_back(factorial(i));
    }

    for (int elem: deque) {
        std::cout << elem << " ";
    }


    return 0;
}