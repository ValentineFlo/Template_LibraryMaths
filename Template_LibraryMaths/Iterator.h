#pragma once

template <typename T>
class List;

template <typename T>
class IntrusiveList;

template <typename T>
struct IntNode;


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

template <typename T>
class IteratorList
{
public:
    explicit IteratorList(IntNode<T>* node) : m_node(node) {}

    T& operator*() const { return m_node->value; }
    IteratorList& operator++() { m_node = m_node->next; return *this; }
    IteratorList operator+(size_t n) const
    {
        auto curentnode = m_node;
        for (size_t i = 0; i < n; ++i)
        {
            curentnode = curentnode->next;
        }
        return IteratorList(curentnode);
    }
    IteratorList operator-(size_t n) const
    {
        auto curentnode = m_node;
        for (size_t i = 0; i < n; ++i)
        {
            curentnode = curentnode->prev;
        }
        return IteratorList(curentnode);
    }
    IteratorList& operator--() { m_node = m_node->prev; return *this; }

    bool operator==(const IteratorList& other) const { return m_node == other.m_node; }
    bool operator!=(const IteratorList& other) const { return !(*this == other); }

private:
    typename List<T>::Node* m_node;
};


template <typename T>
class IteratorListIntr
{
public:
    explicit IteratorListIntr(IntNode<T>* node) : m_node(node) {} 

    T& operator*() const { return m_node->value; }
    IteratorListIntr& operator++() { m_node = m_node->next; return *this; }
    IteratorListIntr operator+(size_t n) const
    {
        auto curentnode = m_node;
        for (size_t i = 0; i < n; ++i)
        {
            curentnode = curentnode->next;
        }
        return IteratorListIntr(curentnode);
    }
    IteratorListIntr operator-(size_t n) const
    {
        auto curentnode = m_node;
        for (size_t i = 0; i < n; ++i)
        {
            curentnode = curentnode->prev;
        }
        return IteratorListIntr(curentnode);
    }
    IteratorListIntr& operator--() { m_node = m_node->prev; return *this; }

    bool operator==(const IteratorListIntr& other) const { return m_node == other.m_node; }
    bool operator!=(const IteratorListIntr& other) const { return !(*this == other); }

private:
    IntNode<T>* m_node;
};
