#ifndef MY_ARRAY_H
#define MY_ARRAY_H

#include <iostream>
#include <string>
#include "AlgoInclude.h"

template<typename T, size_t N>
class Array
{
public:
    using iterator = IteratorVecArray<T>;
    using const_iterator = IteratorVecArray<T>;

    template<typename Type, size_t size>
    friend std::ostream& operator<<(std::ostream& os, const Array<Type, size>& tab);
    using inner_type = T;
    static constexpr size_t size = N;

public:
    Array();
    Array(const std::initializer_list < inner_type>& list);
    Array(const Array& tab);
    ~Array() = default;
    Array& operator= (const Array& tab);

    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;

    void clear();
    bool empty();
    T& at(size_t index);
    const T& at(size_t index) const;
    void swap(Array& otherArray);
    void sort();

    inner_type& operator[](const size_t& index);
    const inner_type& operator[](const size_t& index) const;

private:
    inner_type m_data[size];
};

template<typename Type, size_t Size>
std::ostream& operator<<(std::ostream& os, const Array<Type, Size>& tab);

template<typename InputIt, typename OutputIt, typename Fn>
OutputIt transform(InputIt begin, InputIt end, OutputIt out, Fn fn);



#endif

#include "ArrayImpl.h"