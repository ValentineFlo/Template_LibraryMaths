#ifndef MY_VECTOR_H
#error Do not include this header directly. Please inlude Vector.h
#endif

template<typename T>
Vector<T>::Vector() : m_data(nullptr), m_size(0), m_capacity(0) {}


template<typename T>
Vector<T>::Vector(size_t initialCapacity) : m_size(0), m_capacity(initialCapacity)
{
    if (initialCapacity > 0) 
    {
        m_data = new T[m_capacity]();
    }
}


template<typename T>
Vector<T>::~Vector()
{
    delete[] m_data;
    m_data = nullptr;
}


template<typename T>
typename Vector<T>& Vector<T>::operator= (const Vector& other)
{
    if (this != &other) 
    {
        T* newData = nullptr;
        if (other.m_size > 0) {
            newData = new T[other.m_capacity];
            std::copy(other.m_data, other.m_data + other.m_size, newData);
        }

        delete[] m_data;
        m_data = newData;
        m_size = other.m_size;
        m_capacity = other.m_capacity;
    }
    return *this;
}


template<typename T>
void Vector<T>::push_back(const T& value) 
{
    if (m_size >= m_capacity) 
    {
        size_t newCapacity = (m_capacity == 0) ? 1 : m_capacity * 2;
        T* newData = new T[newCapacity];

        for (size_t i = 0; i < m_size; ++i) {
            newData[i] = m_data[i];
        }

        delete[] m_data;
        m_data = newData;
        m_capacity = newCapacity;
    }

    m_data[m_size++] = value;
}


template<typename T>
void Vector<T>::pop_back()
{
    if (m_size > 0)
    {
        --m_size;
    }
}


template<typename T>
T& Vector<T>::operator[](size_t i)
{
    return m_data[i];
}

template<typename T>
const T& Vector<T>::operator[](size_t i) const
{
    return m_data[i];
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& tab)
{
    os << "(";
    for (auto i = 0; i < tab.getSize() - 1; ++i)
    {
        os << tab.m_data[i] << " ";
    }
    os << tab.m_data[tab.getSize() - 1] << ")";
    return os;
}

template<typename T>
T& Vector<T>::front()
{
    return m_data[0]; 
}

template<typename T>
T& Vector<T>::back()
{
    if (empty())
        throw std::out_of_range("Vector is empty");
    return m_data[m_size - 1];
}

template<typename T>
const T& Vector<T>::front() const
{
    return m_data[0];
}

template<typename T>
const T& Vector<T>::back() const
{
    if (empty())
        throw std::out_of_range("Vector is empty");
    return m_data[m_size - 1];
}

template<typename T>
void Vector<T>::clear()
{
    m_size = 0;
}

//template<typename T>
//void Vector<T>::resize(size_t newSize, T defaultValue)
//{
//    if (newSize > m_capacity)
//        throw std::runtime_error("New size exceeds capacity");
//
//    if (newSize > m_size)
//    {
//        std::fill(pEnd, pBegin + newSize, defaultValue);
//    }
//    pEnd = pBegin + newSize;
//}

template<typename T>
void Vector<T>::erase(size_t index)
{
    if (index >= m_size) 
    {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = index; i < m_size - 1; ++i) {
        m_data[i] = m_data[i + 1];
    }

    --m_size;
}


template<typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return m_data;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::end()
{
    return m_data + m_size;
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const
{
    return m_data;
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const
{
    return m_data + m_size;
}

template<typename T>
typename Vector<T>::reverse_iterator Vector<T>::rbegin()
{
    return m_data[m_size-1]; 
}

template<typename T>
typename Vector<T>::reverse_iterator Vector<T>::rend()
{
    return m_data[0];
}

template<typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::crbegin() const
{
    return m_data[m_size-1];
}

template<typename T>
typename Vector<T>::const_reverse_iterator Vector<T>::crend() const
{
    return m_data[0];
}

template<typename T>
bool Vector<T>::empty() const
{
    if (m_data[0] == m_data[m_size])
    return true;
    else
        return false;
}

template<typename T>
T& Vector<T>::at(size_t elem)
{
    if (elem >= m_size || m_data == nullptr)
        throw std::out_of_range("Index out of range");
    else 
        return m_data[elem-1];
}

template<typename T>
const T& Vector<T>::at(size_t elem) const
{
    if (elem >= m_size || m_data == nullptr)
        throw std::out_of_range("Index out of range");
    else
        return m_data[elem];
}