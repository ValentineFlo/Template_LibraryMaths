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
    return m_data;
}

template<typename T, size_t N>
typename Array<T, N>::iterator Array<T,N>::end()
{
    return m_data + size;
}

template<typename T, size_t N>
typename Array<T, N>::const_iterator Array<T, N>::cbegin() const
{
    return m_data;
}

template<typename T, size_t N>
typename Array<T, N>::const_iterator Array<T,N>::cend() const 
{
    return m_data + size;
}

template<typename T, size_t N>
typename Array<T, N>::reverse_iterator Array<T, N>::rbegin()
{
    return m_data + size - 1;
}

template<typename T, size_t N>
typename Array<T, N>::reverse_iterator Array<T, N>::rend()
{
    return m_data;
}

template<typename T, size_t N>
typename Array<T, N>::const_reverse_iterator Array<T,N>::crbegin() const
{
    return m_data + size - 1;
}

template<typename T, size_t N>
typename Array<T, N>::const_reverse_iterator Array<T,N>::crend() const
{
    return m_data;
}

template<typename T, size_t N>
bool Array<T, N>::empty()
{
    if (begin() == end())
        return true;
    else
        return false;
}

template<typename T, size_t N>
auto Array<T, N>::at()
{
    if (m_data + size)
        throw std::out_of_range("Index out of range");
    return m_data[size];
}

///Ameliorer le std::swap

template<typename T, size_t N>
void Array<T, N>::swap(Array& otherArray)
{
    for (size_t i = 0; i < size; ++i)
    {
        std::swap(m_data[i], otherArray.m_data[i]);
    }
}

template<typename T, size_t N>
typename Array<T, N>::inner_type& Array<T, N>::operator[](const size_t& index)
{
    if (index >= size)
        throw std::runtime_error("out of range");
    return m_data[index];
}

template<typename Type, size_t Size>
std::ostream& operator<<(std::ostream& os, const Array<Type, Size>& tab)
{
    os << "(";
    for (auto i = 0; i < tab.size - 1; ++i)
    {
        os << tab.m_data[i] << " ";
    }
    os << tab.m_data[tab.size - 1] << ")";
    return os;
}

template<typename InputIt, typename OutputIt, typename Fn>
OutputIt transform(InputIt begin, InputIt end, OutputIt out, Fn fn)
{
    for (auto it = begin; it != end; ++it, ++out)
        *out = fn(*it);

    return out;
}


