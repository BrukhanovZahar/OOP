#pragma once

#include <string>
#include <iostream>
#include <stdexcept>
#include <fstream>

class Five {

public:
    class Builder;

    Five();

    Five(const size_t& n, unsigned char t = '0');

    Five(const std::initializer_list<unsigned char>& t);

    Five(const std::string& t);

    Five(const Five& other);

    Five(Five&& other) noexcept;

    // Предупреждает, что результат функции не должен быть проигнорирован
    [[nodiscard]] size_t getSize() const;

    // Предупреждает, что результат функции не должен быть проигнорирован
    [[nodiscard]] std::string getValue() const;

    Five operator+(const Five& other) const;

    Five operator-(const Five& other) const;

    bool operator>(const Five& other) const;

    bool operator<(const Five& other) const;

    bool operator==(const Five& other) const;

    Five& operator=(const Five& other);

    friend std::ostream& operator<<(std::ostream& os, const Five& five);

    void serialize(const std::string& filename) const;

    void deserialize(const std::string& filename);

    static Builder createBuilder();

    virtual ~Five() noexcept;

private:
    size_t _size;
    unsigned char* _array;

    static bool isValidChar(unsigned char c);

    static unsigned char convertChar(const unsigned char c);

    void removeLeadingZeros();
};

class Five::Builder {
public:
    Builder();

    Builder& size(size_t size);

    Builder& addValue(unsigned char value);

    Five build() const;

    ~Builder();

private:
    size_t _size;
    size_t _currentIndex = 0;
    unsigned char* _values = nullptr;
};