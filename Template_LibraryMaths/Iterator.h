#pragma once

template <typename T>
class List;


template <typename T>
class IteratorVecArray
{

public:
    explicit IteratorVecArray(T* p) : ptr(p) {}

    T& operator*() { return *ptr; }
    IteratorVecArray& operator++() { ++ptr; return *this; }
    IteratorVecArray operator++(int) { IteratorVecArray tmp = *this; ++ptr; return tmp; }
    IteratorVecArray& operator--() { --ptr; return *this; }
    IteratorVecArray operator--(int) { IteratorVecArray tmp = *this; --ptr; return tmp; }

    bool operator==(const IteratorVecArray& other) const { return ptr == other.ptr; }
    bool operator!=(const IteratorVecArray& other) const { return ptr != other.ptr; }

private:
    T* ptr;
};


//template <typename T>
//class IteratorList
//{
//
//public:
//    explicit IteratorList(typename List<T>::Node* p) : ptr(p) {}
//
//    T& operator*() { return ptr->m_data ; }
//    IteratorList& operator++() { ptr = ptr->next; return *this; }
//    IteratorList operator++(int) { IteratorList tmp = *this; ptr = ptr->next; return tmp; }
//    IteratorList& operator--() { ptr = ptr->previous; return *this; }
//    IteratorList operator--(int) { IteratorList tmp = *this; ptr = ptr->previous; return tmp; } 
//
//    bool operator==(const IteratorList& other) const { return ptr == other.ptr; }
//    bool operator!=(const IteratorList& other) const { return ptr != other.ptr; }
//
//private:
//    typename List<T>::Node* ptr; 
//};

