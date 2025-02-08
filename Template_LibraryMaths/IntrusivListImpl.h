//#ifndef MY_INTUSIVELIST_H
//#error Do not include this header directly. Please inlude IntrusiveList.h 
//#endif

#ifndef MY_INTRUSIVELIST_H
#error Do not include this header directly. Please inlude List.h
#endif

#include <iostream>
#include "AlgoInclude.h"


template<typename Type>
void IntrusiveList<Type>::push_back(const Type& value)
{
    auto* newNode = new IntNode<Type>(value);
    push_back(*newNode);
}

template<typename Type>
void IntrusiveList<Type>::push_back(IntNode<Type>& node)
{
    auto* prevNode = m_anchor.prev;

    node.prev = prevNode;
    node.next = &m_anchor;

    m_anchor.prev = &node;
    prevNode->next = &node;
}

template<typename Type>
bool IntrusiveList<Type>:: is_empty() const
{
    return m_anchor.prev == &m_anchor && m_anchor.next == &m_anchor;
}

template<typename Type>
size_t IntrusiveList<Type>::size() const
{
    auto* currentNode = m_anchor.next;
    size_t i = 0;
    while (currentNode != &m_anchor)
    {
        ++i;
        currentNode = currentNode->next;
    }

    return i;
}

template<typename Type>
void IntrusiveList<Type>::remove(const Type& value)
{
    auto* currentNode = m_anchor.next;
    while (currentNode != &m_anchor)
    {
        if (currentNode->value == value)
        {
            removeimpl(*currentNode);
            return;
        }
        currentNode = currentNode->next;
    }
}
template<typename Type>
void IntrusiveList<Type>::removeimpl(IntNode<Type>& node)
{
    IntNode<Type>* prevNode = node.prev;
    IntNode<Type>* nextNode = node.next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    node.prev = node.next = nullptr;
    delete& node;
}



template<typename T>
const T& IntrusiveList<T>::back() const
{
    return m_anchor.prev->value; 
}

template<typename T>
const T& IntrusiveList<T>::front() const
{
    return m_anchor.next->value;
}

template<typename T>
typename IntrusiveList<T>::iterator IntrusiveList<T>::begin()
{
    return iterator(m_anchor.next);
}

template<typename T>
typename IntrusiveList<T>::iterator IntrusiveList<T>::end()
{
    return iterator(&m_anchor);
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const IntrusiveList<T>& list)
{
    if (list.is_empty())
    {
        return os;
    }

    os << "(";
    auto* currentNode = list.m_anchor.next;
    while (currentNode != &list.m_anchor)
    {
        os << currentNode->value;
        currentNode = currentNode->next;
        if (currentNode != &list.m_anchor)
        {
            os << " ";
        }
    }
    os << ")";
    return os;
}

