#pragma once

#include "Figure.h"

template<typename T>
class Array {
public:
    Array();
    Array(const Array& other);
    ~Array();
    Array& operator=(const Array& other);
    void resize(int newCapacity);
    void push_back(const T figure);
    void remove(int index);
    int length() const;
    T operator[](int index) const;
private:
    T* _elems;
    int _size;
    int _capacity;
};

#include "../src/Array.cpp"