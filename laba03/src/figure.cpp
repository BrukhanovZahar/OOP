#include "../include/figure.h"

virtual bool operator==(const Figure& other) const {
    return double(*this) == double(other);
}