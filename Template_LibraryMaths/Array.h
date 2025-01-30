#pragma once

#include <iostream>
#include <string>


template<typename T, size_t N>

class Array
{
    using iterator = T*;
    using reverse_iterator = T*; 
    using const_iterator = const T*;
    using const_reverse_iterator = const T*;
    template<typename Type, size_t Size>
    friend std::ostream& operator<<(std::ostream& os, const Array<Type, Size>& tab);

public:
    using inner_type = T;
    static constexpr size_t size = N;
    Array()
    {
        std::fill(m_data, m_data + size, inner_type());
    }

    Array(const std::initializer_list < inner_type>& list)
    {
        if (list.size() != size)
            throw std::runtime_error("Size is different");
        std::copy(list.begin(), list.end(), m_data);
    }

    Array(const Array& tab)
    {
        std::copy(tab.begin(), tab.end(), m_data);
    }

    ~Array() = default;

    Array& operator= (const Array& tab)
    {
        std::copy(tab.begin(), tab.end(), m_data);
        return *this;
    }


    iterator begin()
    {
        return m_data;
    }

    iterator end()
    {
        return m_data + size;
    }

    const_iterator begin() const
    {
        return m_data;
    }
    
    const_iterator end() const
    {
        return m_data + size;
    }

    reverse_iterator rbegin()
    {
        return m_data + size - 1;
    }

    reverse_iterator rend()
    {
        return m_data;
    }

    const_reverse_iterator rbegin() const
    {
        return m_data + size - 1;
    }

    const_reverse_iterator rend() const
    {
        return m_data;
    }


    inner_type& operator[](const size_t& index)
    {
        if (index >= size)
            throw std::runtime_error("out of range");
        return m_data[index];
    }


private:
    inner_type m_data[size];
};

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
