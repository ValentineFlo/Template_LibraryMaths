#ifndef MY_INTRUSIVELIST_H
#define MY_INTRUSIVELIST_H

#include <iostream>
#include "AlgoInclude.h"

template<typename Type>
struct IntNode
{
    IntNode(const Type& value_) : value(value_), prev(nullptr), next(nullptr) {}

    virtual ~IntNode()
    {

    }

    IntNode* prev;
    IntNode* next;
    Type value;
};

template<typename Type>
class IntrusiveList
{
public:
    using iterator = IteratorListIntr<Type>;
    using const_iterator = IteratorListIntr<const Type>;

    IntrusiveList()
        : m_anchor(Type()) 
    {
        m_anchor.prev = m_anchor.next = &m_anchor;
    }

    void push_back(const Type& value);
    void push_back(IntNode<Type>& node);
    bool is_empty() const;
    size_t size() const;
    void remove(const Type& value);

    const Type& back() const;
    const Type& front() const;
    iterator begin();
    iterator end();

    static void removeimpl(IntNode<Type>& node);
    void sort(); 


public:
    IntNode<Type> m_anchor;
};

template<typename Type>
struct Int : IntNode<Type>
{
    Int(const Type& value_)
        : IntNode(value_)
    {
    }

    ~Int()
    {
        IntrusiveList::remove(*this);
    }
};

template<typename T>
void IntrusiveList<T>::sort()
{
    size_t size = 0;
    auto* currentNode = m_anchor.next;
    while (currentNode != &m_anchor)
    {
        ++size;
        currentNode = currentNode->next;
    }

    T* values = new T[size];
    currentNode = m_anchor.next;

    size_t index = 0;
    while (currentNode != &m_anchor)
    {
        values[index++] = currentNode->value;
        currentNode = currentNode->next;
    }

    sortimpl(values, size);

    currentNode = m_anchor.next;
    index = 0;
    while (currentNode != &m_anchor)
    {
        currentNode->value = values[index++];
        currentNode = currentNode->next;
    }

    delete[] values;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const IntrusiveList<T>& list);

#endif

#include "IntrusivListImpl.h"