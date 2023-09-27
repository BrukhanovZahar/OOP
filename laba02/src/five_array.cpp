#include "../include/five_array.h"

Five::Five() : _size{0}, _array{nullptr} {
    std::cout << "Default constructor" << std::endl;
}

Five::Five(const size_t &n, unsigned char t) : _size{n}, _array{new unsigned char[_size]} {
    std::cout << "Fill constructor" << std::endl;
    // TODO : сделать проверку что числа меньше 5
    for (size_t i = 0; i < _size; ++i) {
        _array[i] = t;
    }
}

Five::Five(const std::initializer_list<unsigned char> &t) : _size{t.size()}, _array{new unsigned char[_size]} {
    std::cout << "Initializer list constructor" << std::endl;
    // TODO : сделать проверку что числа меньше 5
    size_t i{0};
    for (auto c: t) {
        _array[i++] = c;
    }
}

Five::Five(const std::string &t) : _size{t.size()}, _array{new unsigned char[_size]} {
    std::cout << "Copy string constructor" << std::endl;
    // TODO : сделать проверку что числа меньше 5
    for (size_t i{0}; i < _size; ++i) {
        _array[i] = static_cast<unsigned char>(t[i]);
    }
}

Five::Five(const Five &other) : _size{other._size}, _array{new unsigned char[other._size]} {
    std::cout << "Copy constructor" << std::endl;
    for (size_t i{0}; i < _size; ++i) {
        _array[i] = other._array[i];
    }
}

Five::Five(Five &&other) noexcept: _size{other._size}, _array{other._array} {
    std::cout << "Move constructor" << std::endl;
    other._size = 0;
    other._array = nullptr;
}

bool Five::isValidChar(const char c) {
    return (c >= '0' && c <= '4');
}

Five Five::operator+(const Five &other) const {
    Five result(_size);
    // TODO : сделать нормальный переход разрядов
    for (size_t i{0}; i < _size; ++i) {
        result._array[i] = (_array[i] + other._array[i]) % 5;
    }

    return result;
}

Five Five::operator-(const Five &other) const {
    // TODO : учесть что левое число больше правого (по заданию нет отрицательных чисел и проверить работу перехода разрядов
    Five result(_size);
    for (size_t i{0}; i < _size; ++i) {
        if (_array[i] < other._array[i]) {
            result._array[i] = 5 + _array[i] - other._array[i];
        } else {
            result._array[i] = _array[i] - other._array[i];
        }
    }
    return result;
}

bool Five::operator<(const Five &other) const {
    if (_size > other._size) {
        return false;
    } else if (_size < other._size) {
        return true;
    }

    for (size_t i{0}; i < _size; ++i) {
        if (_array[i] < other._array[i]) {
            return true;
        } else if (_array[i] > other._array[i]) {
            return false;
        }
    }

    return false;
}

bool Five::operator>(const Five &other) const {
    if (_size > other._size) {
        return true;
    } else if (_size < other._size) {
        return false;
    }

    for (size_t i{0}; i < _size; ++i) {
        if (_array[i] < other._array[i]) {
            return false;
        } else if (_array[i] > other._array[i]) {
            return true;
        }
    }

    return false;
}

bool Five::operator==(const Five &other) const {
    if (_size != other._size) {
        return false;
    }

    for (size_t i{0}; i < _size; ++i) {
        if (_array[i] != other._array[i]) {
            return false;
        }
    }

    return true;
}

Five &Five::operator=(const Five &other) {
    if (this != &other) {
        delete[] _array;
        _size = other._size;
        _array = new unsigned char[_size];
        for (size_t i{0}; i < _size; ++i) {
            _array[i] = other._array[i];
        }
    }
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Five &five) {
    for (size_t i{0}; i < five._size; i++) {
        os << static_cast<int>(five._array[i]);
    }
    return os;
}

Five::~Five() noexcept {
    if (_size > 0) {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}