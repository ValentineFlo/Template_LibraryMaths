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
    return pBegin[0]; 
}

template<typename T>
T& Vector<T>::back()
{
    if (empty())
        throw std::out_of_range("Vector is empty");
    return *(pEnd - 1);
}

template<typename T>
const T& Vector<T>::front() const
{
    return pBegin[0];
}

template<typename T>
const T& Vector<T>::back() const
{
    if (empty())
        throw std::out_of_range("Vector is empty");
    return *(pEnd - 1);
}


template<typename T>
void Vector<T>::push_back(const T& value)
{
    {
        if (pEnd == pCapacity)
        {
            size_t newCapacity = (capacitySize() == 0) ? 1 : capacitySize() * 2;
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
    return pBegin;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::end()
{
    return pEnd;
}


template<typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const
{
    return pBegin;
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const
{
    return pEnd;
}

template<typename T>
typename Vector<T>::reverse_iterator Vector<T>::rbegin()
{
    return pEnd - 1;
}

template<typename T>
typename Vector<T>::reverse_iterator Vector<T>::rend()
{
    return pBegin - 1;
}

template<typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::crbegin() const
{
    return pEnd - 1;
}

template<typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::crend() const
{
    return pBegin - 1;
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
std::ostream& operator<<(std::ostream& os, const Vector<T>& tab) 
{
    size_t size = tab.size();
    if (size == 0)
    {
        os << "()";
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

template<typename T>
T& Vector<T>::at(size_t elem)
{
    if (elem >= size())
        throw std::out_of_range("Index out of range");
    return pBegin[elem];
}


//template<typename T>
//void Vector<T>::clear()
//{
//    m_size = 0;
//}
//
//template<typename T>
//void Vector<T>::erase(size_t index)
//{
//    if (index >= m_size) 
//    {
//        throw std::out_of_range("Index out of range");
//    }
//    for (size_t i = index; i < m_size - 1; ++i) {
//        m_data[i] = m_data[i + 1];
//    }
//
//    --m_size;
//}
//
//
//


//template<typename T>
//bool Vector<T>::empty() const
//{
//    if (m_data[0] == m_data[m_size])
//    return true;
//    else
//        return false;
//}
//

//
//template<typename T>
//const T& Vector<T>::at(size_t elem) const
//{
//    if (elem >= m_size || m_data == nullptr)
//        throw std::out_of_range("Index out of range");
//    else
//        return m_data[elem];
//}