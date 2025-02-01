#ifndef MY_VECTOR_H
#error Do not include this header directly. Please inlude Vector.h
#endif

template<typename T>
Vector<T>::Vector() : pBegin(new T[]), pEnd(pBegin), pCapacity(pBegin + N){}


template<typename T>
Vector<T>::~Vector()

{
    delete[] pBegin;
}

template<typename T>
typename Vector<T>& Vector<T>::operator= (const Vector& tab)
{
    std::copy(tab.begin(), tab.end(), pBegin);
    return *this;
}

template<typename T>
size_t Vector<T>::size() const
{
    return pEnd - pBegin;
}

template<typename T>
void Vector<T>::reserve()
{
    if (!pBegin && !pEnd)
    {
        pBegin = new T[N];
        pEnd = pBegin;
        pCapacity = pBegin + N;
    }
}

template<typename T>
void Vector<T>::push_back(const T& value) 
{
    auto prevSize = size();
    auto newSize = prevSize + 1;

    if (pEnd < pCapacity)
    {
        *pEnd = value;
        ++pEnd;
    }
    else
    {
        auto tmp = new T[size() + 1];
        for (auto* it = pBegin, i = 0; it != pEnd; ++it, ++i)
            tmp[i] = *it;

        tmp[prevSize] = value;

        delete[] pBegin;
        pBegin = tmp;
        pEnd = tmp + newSize;
    }
}


template<typename T>
void Vector<T>::pop_back()
{
    if (size() > 0)
    {
        --pEnd;
    }
}


template<typename T>
T& Vector<T>::operator[](size_t i)
{
    return *(pBegin + i);
}

template<typename T>
const T& Vector<T>::operator[](size_t i) const
{
    return *(pBegin + i);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T, N>& tab)
{
    os << "(";
    for (auto i = 0; i < tab.size() - 1; ++i)
    {
        os << tab.pBegin[i] << " ";
    }
    os << tab.pBegin[tab.size() - 1] << ")";
    return os;
}

template<typename T>
const T& Vector<T>::front() const
{
    return *pBegin;
}

template<typename T>
const T& Vector<T>::back() const
{
    return *(pEnd - 1);
}


template<typename T>
void Vector<T>::clear()
{
    pEnd = pBegin;
}

template<typename T>
void Vector<T>::resize(size_t newSize, T defaultValue)
{
    if (newSize > N)
        throw std::runtime_error("New size exceeds capacity");

    if (newSize > size())
    {
        std::fill(pEnd, pBegin + newSize, defaultValue);
    }
    pEnd = pBegin + newSize;
}

template<typename T>
void Vector<T>::erase(size_t index)
{
    if (index >= size())
        throw std::out_of_range("Index out of range");

    std::move(pBegin + index + 1, pEnd, pBegin + index);
    --pEnd;
}


template<typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return pBegin;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::end()
{
    return pBegin + size;
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const
{
    return pBegin;
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const
{
    return pBegin + size;
}

template<typename T>
typename Vector<T>::reverse_iterator Vector<T>::rbegin()
{
    return pBegin + size - 1;
}

template<typename T>
typename Vector<T>::reverse_iterator Vector<T>::rend()
{
    return pBegin;
}

template<typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::crbegin() const
{
    return pBegin + size - 1;
}

template<typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::crend() const
{
    return pBegin;
}

template<typename T>
bool Vector<T>::empty() const
{
    if (begin() == end())
        return true;
    else
        return false;
}

template<typename T>
T& Vector<T>::at()
{
    if (pBegin + size)
        throw std::out_of_range("Index out of range");
    return pBegin[size];
}

template<typename T>
const T& Vector<T>::at() const
{
    if (pBegin + size)
        throw std::out_of_range("Index out of range");
    return pBegin[size];
}