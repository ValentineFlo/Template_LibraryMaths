#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <iostream>

template<typename T>
class Vector
{
public:


    using iterator = T*;
    using reverse_iterator = T*;
    using const_iterator = const T*;
    using const_reverse_iterator = const T*;

    Vector();
    ~Vector();
    Vector& operator= (const Vector& tab);
    size_t size() const;
    void reserve();

    const T& front() const;
    const T& back() const;
    void push_back(const T& value);
    void pop_back();

    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;
    reverse_iterator rbegin();
    reverse_iterator rend();
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;

    T& operator[](size_t i);
    const T& operator[](size_t i) const;

    T& at();
    const T& at() const;
    bool empty()const;
    void clear();
    void resize(size_t newSize, T defaultValue);
    void erase(size_t index);


public:
    T* pBegin;
    T* pEnd;
    T* pCapacity;
};

template<typename Type, size_t Size>
std::ostream& operator<<(std::ostream& os, const Vector<Type>& tab);




#endif

#include "VectorImpl.h"