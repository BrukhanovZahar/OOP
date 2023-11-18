#include "../include/Array.h"

template<typename T>
myArray<T>::myArray() : _size{0}, _capacity{10}, _elems{new T[this->_capacity]} {}

template<typename T>
myArray<T>::myArray(const myArray& other) : _elems(nullptr), _size(0), _capacity(0) {
    resize(other._capacity);
    for (int i{0}; i < other._size; ++i) {
        _elems[i] = other._elems[i];
    }
    _size = other._size;
}

template<typename T>
myArray<T>::~myArray() {
    _size = 0;
    _capacity = 0;
    delete[] _elems;
}

template<typename T>
myArray<T>& myArray<T>::operator=(const myArray& other) {
    if (this != &other) {

        for (int i = 0; i < other._size; ++i) {
            _elems[i] = other._elems[i];
        }

        _size = other._size;
    }
    return *this;
}

template<typename T>
void myArray<T>::push_back(const T figure) {
    if (_size == _capacity) {
        resize(_capacity * 2);
    }
    _elems[_size] = figure;
    _size += 1;
}

template<typename T>
void myArray<T>::resize(int newCapacity) {

    if (newCapacity <= 0) {
        newCapacity = 1;
    }

    T* newElems = new T[newCapacity];
    int copySize = _size < newCapacity ? _size : newCapacity;

    for (int i{0}; i < copySize; ++i) {
        newElems[i] = _elems[i];
    }

    delete[] _elems;
    _elems = newElems;
    _capacity = newCapacity;
}

template<typename T>
int myArray<T>::length() const {
    return _size;
}

template<typename T>
void myArray<T>::print() const {
    for (int i{0}; i < _size; ++i) {
        std::cout << _elems[i] << " ";
    }
    std::cout << std::endl;
}

template<typename T>
void myArray<T>::remove(int index) {
    if (index >= 0 && index < _size) {
        for (int i{index}; i < _size - 1; ++i) {
            _elems[i] = _elems[i + 1];
        }
        --_size;
    }
}

template<typename T>
T myArray<T>::operator[](int index) const {
    if (index >= 0 && index < _size) {
        return _elems[index];
    } else {
        throw std::out_of_range("Index out of bounds");
    }
}

template<typename T>
T* myArray<T>::begin() const {
    return _elems;
}

template<typename T>
T* myArray<T>::end() const {
    return _elems + _size;
}