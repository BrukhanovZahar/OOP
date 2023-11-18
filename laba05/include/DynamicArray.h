#pragma once

#include <stdexcept>
#include <type_traits>


template<typename T, class Allocator = std::allocator<T>>
class DynamicArray {
private:
    Allocator allocator;
    T* data;
    std::size_t capacity;
    std::size_t size;

    void resize() {
        if (capacity == 0) {
            capacity = 1;
        } else {
            capacity *= 2;
        }
        T* newData = allocator.allocate(capacity);
        std::move(data, data + size, newData);
        allocator.deallocate(data, capacity);
        data = newData;
    }

public:
    using value_type = T;
    using reference_type = T&;
    using pointer = T*;

    DynamicArray() : data(allocator.allocate(10)), capacity(10), size(0) {}

    DynamicArray(const DynamicArray& other) : capacity(other.capacity), size(other.size) {
        data = allocator.allocate(capacity);
        std::copy(other.data, other.data + size, data);
    }

    DynamicArray(DynamicArray&& other) noexcept: data(other.data), capacity(other.capacity), size(other.size) {
        other.data = nullptr;
        other.capacity = 0;
        other.size = 0;
    }

    DynamicArray& operator=(const DynamicArray& other) {
        if (this != &other) {
            clear();
            allocator.deallocate(data);

            capacity = other.capacity;
            size = other.size;

            data = allocator.allocate(capacity);
            std::copy(other.data, other.data + size, data);
        }
        return *this;
    }

    DynamicArray& operator=(DynamicArray&& other)

    noexcept {
        if (this != &other) {
            clear();
            allocator.deallocate(data);

            data = other.data;
            capacity = other.capacity;
            size = other.size;

            other.data = nullptr;
            other.capacity = 0;
            other.size = 0;
        }
        return *this;
    }


    ~DynamicArray() {
        clear();
        allocator.deallocate(data, capacity);
    }

    template<typename... Args>
    reference_type push_back(Args&& ... args) {
        if (size >= capacity) {
            resize();
        }

        allocator.construct(data + size, std::forward<Args>(args)...);
        return data[size++];
    }

    reference_type at(std::size_t index) {
        if (index >= size) {
            throw std::out_of_range("DynamicArray::at error: index out of range.");
        }

        return data[index];
    }

    std::size_t getSize() const {
        return size;
    }

    bool empty() const {
        return size == 0;
    }

    void clear() {
        while (!empty()) {
            pop_back();
        }
    }

    void pop_back() {
        if (empty()) {
            throw std::logic_error("DynamicArray::pop_back error: array is empty, nothing to pop");
        }

        allocator.destroy(data + size - 1);
        --size;
    }

    class iterator {
    private:
        T* ptr;

    public:
        using value_type = T;
        using reference = T&;
        using pointer = T*;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::forward_iterator_tag;

        iterator(T* p) : ptr(p) {}

        reference operator*() const {
            return *ptr;
        }

        pointer operator->() const {
            return ptr;
        }

        iterator& operator++() {
            ++ptr;
            return *this;
        }

        iterator operator++(int) {
            iterator tmp = *this;
            ++ptr;
            return tmp;
        }

        bool operator==(const iterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const iterator& other) const {
            return ptr != other.ptr;
        }
    };

    class const_iterator {
    private:
        const T* ptr;

    public:
        using value_type = const T;
        using reference = const T&;
        using pointer = const T*;
        using difference_type = std::ptrdiff_t;
        using iterator_category = std::forward_iterator_tag;

        const_iterator(const T* p) : ptr(p) {}

        reference operator*() const {
            return *ptr;
        }

        pointer operator->() const {
            return ptr;
        }

        const_iterator& operator++() {
            ++ptr;
            return *this;
        }

        const_iterator operator++(int) {
            const_iterator tmp = *this;
            ++ptr;
            return tmp;
        }

        bool operator==(const const_iterator& other) const {
            return ptr == other.ptr;
        }

        bool operator!=(const const_iterator& other) const {
            return ptr != other.ptr;
        }
    };

    iterator begin() {
        return iterator(data);
    }

    iterator end() {
        return iterator(data + size);
    }

    const_iterator begin() const {
        return const_iterator(data);
    }

    const_iterator end() const {
        return const_iterator(data + size);
    }

};