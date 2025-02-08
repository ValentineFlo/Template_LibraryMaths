#ifndef MY_ARRAY_H 
#error Do not include this header directly. Please inlude Array.h
#endif

#include <iostream>
#include <string>

template<typename T, size_t N>
Array<T,N>::Array()
{
    std::fill(m_data, m_data + size, inner_type());
}

template<typename T, size_t N>
Array<T, N>::Array(const std::initializer_list < inner_type>& list)
{
    if (list.size() != size)
        throw std::runtime_error("Size is different");
    std::copy(list.begin(), list.end(), m_data);
}

template<typename T, size_t N>
Array<T, N>::Array(const Array& tab)
{
    std::copy(tab.begin(), tab.end(), m_data);
}

template<typename T, size_t N>
typename Array<T, N>& Array<T, N>::operator= (const Array& tab) 
{
    std::copy(tab.begin(), tab.end(), m_data);
    return *this;
}

template<typename T, size_t N>
typename Array<T, N>::iterator Array<T, N>::begin()
{
    return IteratorVecArray<T>(m_data); 
}

template<typename T, size_t N>
typename Array<T, N>::iterator Array<T,N>::end()
{
    return IteratorVecArray<T>(m_data + size);
}

template<typename T, size_t N>
typename Array<T, N>::const_iterator Array<T, N>::cbegin() const
{
    return IteratorVecArray<T>(m_data); 
}

template<typename T, size_t N>
typename Array<T, N>::const_iterator Array<T,N>::cend() const 
{
    return IteratorVecArray<T>(m_data + size); 
}


template<typename T, size_t N>
bool Array<T, N>::empty()
{
    return N == 0;
}

template<typename T, size_t N>
T& Array<T, N>::at(size_t index)
{
    if (index > N)
        throw std::out_of_range("Index out of range");
    return m_data[index];
}


template<typename T, size_t N>
const T& Array<T, N>::at(size_t index) const 
{
    if (index >= size)
        throw std::out_of_range("Index out of range");
    return m_data[index];
}

template<typename T, size_t N> 
void Array<T, N>::clear() 
{
    std::fill(m_data, m_data + size, T()); 
}

///Ameliorer le std::swap

template<typename T, size_t N>
void Array<T, N>::swap(Array& otherArray)
{
    T tmp[N];

    for (size_t i = 0; i < N; ++i) 
    {
        tmp[i] = m_data[i];
    }

    for (size_t i = 0; i < N; ++i) 
    {
        m_data[i] = otherArray.m_data[i];
    }

    for (size_t i = 0; i < N; ++i) 
    {
        otherArray.m_data[i] = tmp[i];
    }
}

template<typename T, size_t N>
typename Array<T, N>::inner_type& Array<T, N>::operator[](const size_t& index)
{
    if (index >= size)
        throw std::runtime_error("out of range");
    return m_data[index];
}

template<typename T, size_t N>
const typename Array<T, N>::inner_type& Array<T, N>::operator[](const size_t& index) const
{
    if (index >= size)
        throw std::runtime_error("out of range");
    return m_data[index];
}

template<typename Type, size_t Size>
std::ostream& operator<<(std::ostream& os, const Array<Type, Size>& tab)
{
    for (auto i = 0; i < tab.size - 1; ++i)
    {
        os << tab.m_data[i] << " ";
    }
    os << tab.m_data[tab.size - 1];
    return os;
}

template<typename T, size_t N>
void Array<T, N>::sort()
{
    sortimpl(m_data, size); 
}

template<typename InputIt, typename OutputIt, typename Fn>
OutputIt transform(InputIt begin, InputIt end, OutputIt out, Fn fn)
{
    for (auto it = begin; it != end; ++it, ++out)
        *out = fn(*it);

    return out;
}


