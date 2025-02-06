#ifndef MY_VECTOR_H
#define MY_VECTOR_H

#include <iostream>
#include "Iterator.h"

template<typename T>
class Vector
{
public:

    using iterator = Iterator<T>;
    using const_iterator = Iterator<const T>;

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
    Vector& operator= (const Vector& tab);

    T& at(size_t elem);
    const T& at(size_t elem) const;
    void clear();
    void resize(size_t newSize, T defaultValue);
    void erase(size_t index);

    void sort();

public:
    T* pBegin;
    T* pEnd;
    T* pCapacity;

};

//template<typename Type, size_t Size>
//std::ostream& operator<<(std::ostream& os, const Vector<Type>& tab);

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& tab)
{
    size_t size = tab.size();
    if (size == 0)
    {
        os << "";
        return os;
    }
    os << "(";
    for (size_t i = 0; i < size - 1; ++i)
    {
        os << tab.pBegin[i] << " ";
    }
    os << tab.pBegin[size - 1] << ")";
    return os;
}



#endif

#include "VectorImpl.h"
