#ifndef MY_VECTOR_H
#define MY_VECTOR_H


/**
 * @file Vector.h
 * @brief Vector class definition
 * ***Vector***
 */

#include <iostream>
#include "AlgoInclude.h"

template<typename T>
class Vector
{
public:

    using iterator = IteratorVecArray<T>;
    using const_iterator = IteratorVecArray<const T>;

    Vector();
    ~Vector();

    size_t size()const; 
    void reserve(int capacity);
    int capacitySize()const;
    bool empty()const; 
    

    T& front();
    T& back() ;
    const T& front() const;
    const T& back() const;
    void push_back(const T& value);
    void pop_back();

    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;

    T& operator[](int i);
    const T& operator[](int i) const;

    T& at(size_t elem);
    const T& at(size_t elem) const;
    void clear();
    void erase(size_t index);

    void sort();

public:
    T* pBegin;
    T* pEnd;
    T* pCapacity;

};

template<typename Type, size_t Size>
std::ostream& operator<<(std::ostream& os, const Vector<Type>& tab);




#endif

#include "VectorImpl.h"
