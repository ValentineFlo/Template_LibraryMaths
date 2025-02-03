#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <iostream>
#include <stdexcept>
#include <algorithm>

template<typename T>
class Vector {
public:
    using iterator = T*;
    using reverse_iterator = std::reverse_iterator<iterator>;
    using const_iterator = const T*;
    using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    // Constructeurs et destructeur
    Vector() : m_data(nullptr), m_size(0), m_capacity(0) {}

    explicit Vector(size_t initialCapacity) : m_size(0), m_capacity(initialCapacity) {
        if (initialCapacity > 0) {
            m_data = new T[m_capacity]();
        }
    }

    ~Vector() {
        delete[] m_data;
    }

    // Opérateurs
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            T* newData = nullptr;
            if (other.m_size > 0) {
                newData = new T[other.m_capacity];
                std::copy(other.m_data, other.m_data + other.m_size, newData);
            }

            delete[] m_data;
            m_data = newData;
            m_size = other.m_size;
            m_capacity = other.m_capacity;
        }
        return *this;
    }

    T& operator[](size_t i) { return m_data[i]; }
    const T& operator[](size_t i) const { return m_data[i]; }

    // Méthodes d'accès
    T& at(size_t i) 
    {
        if (i >= m_size) throw std::out_of_range("Index out of range");
        return m_data[i];
    }

    const T& at(size_t i) const 
    {
        if (i >= m_size) throw std::out_of_range("Index out of range");
        return m_data[i];
    }

    const T& front() const 
    {
        if (empty()) throw std::out_of_range("Vector is empty");
        return m_data[0];
    }

    const T& back() const 
    {
        if (empty()) throw std::out_of_range("Vector is empty");
        return m_data[m_size - 1];
    }

    // Méthodes de modification
    void push_back(const T& value) {
        if (m_size == m_capacity) {
            size_t newCapacity = (m_capacity == 0) ? 1 : m_capacity * 2;
            reserve(newCapacity);
        }
        m_data[m_size++] = value;
    }

    void pop_back() {
        if (empty()) throw std::out_of_range("Vector is empty");
        --m_size;
    }

    void clear() { m_size = 0; }

    void resize(size_t newSize, T defaultValue = T()) {
        if (newSize > m_capacity) {
            reserve(newSize);
        }
        if (newSize > m_size) {
            std::fill(m_data + m_size, m_data + newSize, defaultValue);
        }
        m_size = newSize;
    }

    void reserve(size_t newCapacity) {
        if (newCapacity > m_capacity) {
            T* newData = new T[newCapacity];
            if (m_data) {
                std::copy(m_data, m_data + m_size, newData);
                delete[] m_data;
            }
            m_data = newData;
            m_capacity = newCapacity;
        }
    }

    void erase(size_t index) {
        if (index >= m_size) throw std::out_of_range("Index out of range");
        std::move(m_data + index + 1, m_data + m_size, m_data + index);
        --m_size;
    }

    // Itérateurs
    iterator begin() { return m_data; }
    iterator end() { return m_data + m_size; }
    const_iterator cbegin() const { return m_data; }
    const_iterator cend() const { return m_data + m_size; }

    reverse_iterator rbegin() { return reverse_iterator(end()); }
    reverse_iterator rend() { return reverse_iterator(begin()); }
    const_reverse_iterator crbegin() const { return const_reverse_iterator(cend()); }
    const_reverse_iterator crend() const { return const_reverse_iterator(cbegin()); }

    // Méthodes d'information
    bool empty() const { return m_size == 0; }
    size_t size() const { return m_size; }
    size_t capacity() const { return m_capacity; }

private:
    T* m_data;
    size_t m_size;
    size_t m_capacity;
};

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& vec) {
    os << "(";
    for (size_t i = 0; i < vec.size(); ++i) {
        if (i > 0) os << " ";
        os << vec[i];
    }
    os << ")";
    return os;
}

#endif