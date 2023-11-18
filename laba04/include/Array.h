#pragma once

template<typename T>
class myArray {
public:
    myArray();
    myArray(const myArray& other);
    ~myArray();
    myArray& operator=(const myArray& other);
    void resize(int newCapacity);
    void push_back(const T figure);
    void remove(int index);
    int length() const;
    void print() const;
    T operator[](int index) const;
    T* begin() const;
    T* end() const;

private:
    T* _elems;
    int _size;
    int _capacity;
};

#include "../src/Array.cpp"