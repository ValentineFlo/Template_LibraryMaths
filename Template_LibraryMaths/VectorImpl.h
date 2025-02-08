#ifndef VECTOR_IMPL_H
#define VECTOR_IMPL_H

#include "Vector.h"

#ifndef MY_VECTOR_H
#error Do not include this header directly. Please inlude Vector.h
#endif



template<typename T>
Vector<T>::Vector() 
    : pBegin(nullptr)
    , pEnd(nullptr)
    , pCapacity(nullptr)
{
}

template<typename T>
Vector<T>::~Vector()
{
    delete[] pBegin;
}

template<typename T>
size_t Vector<T>::size() const
{
    return pEnd - pBegin;
}

template <typename T>
void Vector<T>::reserve(int capacity) 
{
    if (capacity <= capacitySize())
        return;

    auto tmp = new T[capacity];
    auto prevSize = size();

    for (int i = 0; i < prevSize; ++i)
        tmp[i] = pBegin[i];

    delete[] pBegin;
    pBegin = tmp;
    pEnd = tmp + prevSize;
    pCapacity = tmp + capacity;
}

template<typename T>
int Vector<T>::capacitySize() const
{
    return pCapacity - pBegin;
} 

template<typename T>
bool Vector<T>::empty() const
{
    return pBegin == pEnd;
}

template<typename T>
T& Vector<T>::front()
{
    if (empty())
    {
        std::cerr << "Error: accessing front() on an empty vector. Returns a default value : " ;
        static T default_value{};
        return default_value;
    }
    return pBegin[0]; 
}

template<typename T>
T& Vector<T>::back()
{
    if (empty())
    {
        std::cerr << "Error: accessing back() on an empty vector. Returns a default value : ";
        static T default_value{};
        return default_value;
    }
    return *(pEnd - 1);
}

template<typename T>
const T& Vector<T>::front() const
{
    if (empty())
    {
        std::cerr << "Error: accessing front() on an empty vector. Returns a default value : ";
        static T default_value{};
        return default_value;
    }
    return pBegin[0];
}

template<typename T>
const T& Vector<T>::back() const
{
    if (empty())
    {
        std::cerr << "Error: accessing back() on an empty vector. Returns a default value : ";
        static T default_value{};
        return default_value;
    }
    return *(pEnd - 1);
}


template<typename T>
void Vector<T>::push_back(const T& value)
{
    {
        if (pEnd == pCapacity)
        {
            size_t newCapacity = (capacitySize() == 0) ? 1 : static_cast<size_t>(capacitySize()) * 2;
            reserve(newCapacity);
        }

        *pEnd = value;
        ++pEnd;
    }

}

template<typename T>
void Vector<T>::pop_back()
{
    if (pEnd > pBegin)
    {
        --pEnd;
    }
}


template<typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return iterator(pBegin);
}

template<typename T>
typename Vector<T>::iterator Vector<T>::end()
{
    return iterator(pEnd);
}


template<typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const
{
    return const_iterator(pBegin);
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const
{
    return const_iterator(pEnd);
}

template<typename T>
T& Vector<T>::operator[](int i)
{
    return *(pBegin + i);
}

template<typename T>
const T& Vector<T>::operator[](int i) const
{
    return *(pBegin + i);
}

template<typename T>
T& Vector<T>::at(size_t elem)
{
    if (elem >= size())
    {
        std::cerr << "Error: accessing at() on an empty vector. Returns a default value : ";
        static T default_value{};
        return default_value;
    }
    return pBegin[elem];
}

template<typename T>
const T& Vector<T>::at(size_t elem) const 
{
    if (elem >= size())
        throw std::out_of_range("Index out of range");
    return pBegin[elem];
}

template<typename T>
void Vector<T>::clear()
{

    delete[] pBegin;
    pBegin = nullptr;
    pEnd = nullptr;
    pCapacity = nullptr;
}


///Supprime un element 
template<typename T>
void Vector<T>::erase(size_t index)
{
    if (index >= size()) 
    {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < size() - 1; ++i) 
    {
        pBegin[i] = pBegin[i + 1];
    }

    --pEnd;
}

template<typename T>
void Vector<T>::sort()
{
    sortimpl(pBegin, size()); 
}


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
