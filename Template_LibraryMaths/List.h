﻿
/**
 * @file list.h
 * @brief list class definition
 * ***List***
 */

#ifndef MY_LIST_H
#define MY_LIST_H

#include <string>

template <typename T>
class IteratorList;

template<typename T>
class List
{
public:

    using iterator = IteratorList<T>;
    using const_iterator = IteratorList<const T>;

    List();
    ~List();
    /**
     * @brief adds an element to the end
     * @param elem its an element
     * @return change the pointer to the end
     */
    void push_back(const T& elem);

    /**
     * @brief adds an element to the begin
     * @param elem its an element
     * @return change the pointer to the begin
     */
    void push_front(const T& elem);
     
    /**
     * @brief remove an element to the end
     * @return change the pointer to the previous end remove last
     */
    void pop_back();
    
    /**
     * @brief remove an element to the begin
     * @return change the pointer to the next end remove first
     */
    void pop_front();
    
    /**
     * @brief count number of element of the list
     * @param size_t
     * @return list size
     */
    size_t size() const;

    /**
     * @brief access the last element
     * @return the value of the last pointer
     */
    const T& back() const;

    /**
     * @brief access the first element
     * @return the value of the first pointer
     */
    const T& front() const;

    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;

public:
    struct Node;

    Node* m_first;
    Node* m_last;
};

template <typename T>
class IteratorList
{
public:
    explicit IteratorList(typename List<T>::Node* node) : m_node(node) {}

    T& operator*() const { return m_node->value; }
    IteratorList& operator++() { m_node = m_node->next; return *this; }
    IteratorList operator++(int) { IteratorList tmp = *this; ++(*this); return tmp; }
    IteratorList& operator--() { m_node = m_node->previous; return *this; }
    IteratorList operator--(int) { IteratorList tmp = *this; --(*this); return tmp; }

    bool operator==(const IteratorList& other) const { return m_node == other.m_node; }
    bool operator!=(const IteratorList& other) const { return !(*this == other); }

private:
    typename List<T>::Node* m_node;
};

#endif

#include "ListImpl.h"
