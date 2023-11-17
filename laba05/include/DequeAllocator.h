#pragma once

#include <deque>
#include <cstdlib>
#include <stdexcept>
#include <iostream>
#include <type_traits>

template<typename T, std::size_t BLOCK_SIZE = 10>
class DequeAllocator {
private:
    std::deque<T*> _buffers;
    size_t _free_index;

public:
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using size_type = std::size_t;
    using void_pointer = void *;
    using const_void_pointer = const void *;
    using reference_type = T &;
    using const_reference_type = const T &;

    template<typename U>
    struct rebind {
        using other = DequeAllocator<U, BLOCK_SIZE>;
    };

    DequeAllocator() : _free_index(0) {
        _buffers.push_back(static_cast<T*>(malloc(sizeof(T) * BLOCK_SIZE)));
    }

    ~DequeAllocator() {
        for (auto buffer: _buffers) {
            free(buffer);
        }
    }

    pointer allocate(size_type n = 1) {
        if (_free_index + n > BLOCK_SIZE) {
            _buffers.push_back(static_cast<T*>(malloc(sizeof(T) * BLOCK_SIZE)));
            _free_index = 0;
        }

        pointer result = _buffers.back() + _free_index;
        _free_index += n;

        return result;
    }

    void deallocate(pointer p, size_type n = 1) noexcept {
    }

    template<typename U, typename... Args>
    void construct(U* p, Args&& ...args) {
        new(p) U(std::forward<Args>(args)...);
    }

    void destroy(pointer p) {
        p->~T();
    }

};