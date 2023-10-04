#include "../include/five_array.h"

Five::Five() : _size{0}, _array{nullptr} {
    std::cout << "Default constructor" << std::endl;
}

Five::Five(const size_t &n, unsigned char t) : _size{n}, _array{new unsigned char[_size]} {
    std::cout << "Fill constructor" << std::endl;
    if (!isValidChar(t)) {
        throw std::invalid_argument("The class accepts fivefold numbers, between 0-4");
    }
    for (size_t i{0}; i < _size; ++i) {
        _array[i] = t;
    }
}

Five::Five(const std::initializer_list<unsigned char> &t) : _size{t.size()}, _array{new unsigned char[_size]} {
    std::cout << "Initializer list constructor" << std::endl;
    size_t i{0};
    for (auto c: t) {
        if (!isValidChar(c)) {
            throw std::invalid_argument("The class accepts fivefold numbers, between 0-4");
        }
        _array[i++] = c;
    }
}

Five::Five(const std::string &t) : _size{t.size()}, _array{new unsigned char[_size]} {
    std::cout << "Copy string constructor" << std::endl;
    for (size_t i{0}; i < _size; ++i) {
        if (!isValidChar(t[i])) {
            throw std::invalid_argument("The class accepts fivefold numbers, between 0-4");
        }
        _array[i] = static_cast<unsigned char>(t[i]);
    }
}

Five::Five(const Five &other) : _size{other._size}, _array{new unsigned char[other._size]} {
    std::cout << "Copy constructor" << std::endl;
    for (size_t i{0}; i < _size; ++i) {
        if (!isValidChar(other._array[i])) {
            throw std::invalid_argument("The class accepts fivefold numbers, between 0-4");
        }
        _array[i] = other._array[i];
    }
}

Five::Five(Five &&other) noexcept: _size{other._size}, _array{other._array} {
    std::cout << "Move constructor" << std::endl;
    other._size = 0;
    other._array = nullptr;
}

bool Five::isValidChar(const unsigned char c) {
    return (c >= '0' && c <= '4');
}

Five Five::operator+(const Five &other) const {
    long long sz;
    long long raz;
    const Five* min = other._size > _size ? this : &other;
    const Five* max = other._size > _size ? &other : this;

    if (_size > other._size) {
        sz = _size;
        raz = _size - other._size;
    } else {
        sz = other._size;
        raz = other._size - _size;
    }

    Five result(sz);
    unsigned char carry{0};

    for (long long i = (long long) result._size - 1; i >= 0; --i) {
        unsigned char sum = (i - raz >= 0 ? min->_array[i - raz] : '0') - '0' + max->_array[i] - '0' + carry;
        result._array[i] = (sum % 5) + '0';
        carry = sum / 5;
    }

    if (carry > 0) {
        result._size++;
        auto* new_array = new unsigned char[result._size];
        new_array[0] = carry;

        for (size_t i = 0; i < result._size - 1; ++i) {
            new_array[i + 1] = result._array[i];
        }

        delete[] result._array;
        result._array = new_array;
    }

    return result;
}

Five Five::operator-(const Five &other) const {
    if (_size < other._size) {
        throw std::underflow_error("Numbers can only be positive, you can't subtract more from less");
    }

    long long raz = _size - other._size;
    Five result(_size);
    long long borrow{0};

    for (long long i = (long long) _size - 1; i >= 0; --i) {
        unsigned char diff = (_array[i] - '0') - ((i - raz >= 0 ? other._array[i - raz] : '0') - '0') - borrow;

        if (diff > _array[i]) {
            borrow = 1;
            diff += 5;
        } else {
            borrow = 0;
        }
        result._array[i] = diff + '0';
    }
    if (borrow > 0) {
        throw std::underflow_error("Numbers can only be positive, you can't subtract more from less");
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
    for (size_t i{0}; i < five._size; ++i) {
        os << five._array[i];
    }
    return os;
}

void Five::serialize(const std::string &filename) const {
    std::ofstream outFile(filename);

    if (!outFile.is_open()) {
        throw std::runtime_error("Unable to open file for serialization");
    }

    outFile << "{size: " << _size << ", number: ";
    for (size_t i{0}; i < _size; ++i) {
        outFile << _array[i];
    }
    outFile << '}';

    outFile.close();
}

void Five::deserialize(const std::string &filename) {
    std::ifstream inFile(filename);

    if (!inFile.is_open()) {
        throw std::runtime_error("Unable to open file for deserialization");
    }

    char ch;
    inFile >> ch;
    if (ch != '{') {
        throw std::runtime_error("Invalid format in the file");
    }

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    inFile >> _size;

    if (_size <= 0) {
        throw std::runtime_error("Invalid size in the file");
    }

    delete[] _array;
    _array = new unsigned char[_size];

    inFile.ignore(std::numeric_limits<std::streamsize>::max(), ':');
    for (size_t i = 0; i < _size; ++i) {
        char value;
        inFile >> value;

        if (!isValidChar(value)) {
            throw std::runtime_error("Invalid pental digit");
        }

        _array[i] = value;
    }

    // Чтение завершающей скобки
    inFile >> ch;
    if (ch != '}') {
        throw std::runtime_error("Invalid format in the file");
    }


    inFile.close();
}

Five::Builder Five::createBuilder() {
    return Builder();
}

Five::~Five() noexcept {
    if (_size > 0) {
        _size = 0;
        delete[] _array;
        _array = nullptr;
    }
}

Five::Builder::Builder() : _size(0), _values(nullptr) {}

Five::Builder &Five::Builder::size(size_t size) {
    _size = size;
    _values = new unsigned char[size];
    return *this;
}

Five::Builder &Five::Builder::addValue(unsigned char value) {
    if (!isValidChar(value)) {
        throw std::invalid_argument("The class accepts fivefold numbers, between 0-4");
    }
    if (!_values) {
        throw std::logic_error("Array is not initialized");
    }
    if (_currentIndex + 1 > _size) {
        throw std::runtime_error("Excessive addition of elements in the builder");
    }
    _values[_currentIndex++] = value;
    return *this;
}

Five Five::Builder::build() const {
    if (!_values && !_size) {
        throw std::runtime_error("Five is not create");
    }
    if (_values == nullptr) {
        return Five(_size, '0');
    } else {
        std::string tmp = "";
        for (size_t i{0}; i < _size && _values[i] != '\0'; ++i) {
            tmp += _values[i];
        }
        return Five(tmp);
    }
}

Five::Builder::~Builder() {
    delete[] _values;
    _values = nullptr;
}