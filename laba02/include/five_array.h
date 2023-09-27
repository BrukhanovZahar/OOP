#pragma once

#include <string>
#include <iostream>
#include <stdexcept>

class Five {

public:

    Five();

    Five(const size_t &n, unsigned char t = 0);

    Five(const std::initializer_list<unsigned char> &t);

    Five(const std::string &t);

    Five(const Five &other);

    Five(Five &&other) noexcept;


    Five operator+(const Five &other) const;

    Five operator-(const Five &other) const;

    bool operator>(const Five &other) const;

    bool operator<(const Five &other) const;

    bool operator==(const Five &other) const;

    Five &operator=(const Five &other);

    friend std::ostream &operator<<(std::ostream &os, const Five &five);

    virtual ~Five() noexcept;

private:

    size_t _size;
    unsigned char *_array;

    static bool isValidChar(const char c);
};