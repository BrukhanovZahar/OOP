#pragma once

#include <concepts>

template <typename T>
concept ScalarType = std::is_scalar<T>::value;