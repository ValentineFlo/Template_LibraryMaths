﻿
/**
 * @file list.h
 * @brief list class definition
 * ***List***
 */

#ifndef MY_LIST_H
#define MY_LIST_H

#include <string>
#include "AlgoInclude.h"

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

    /**
     * @brief Iterate to the first element
     * @return the pointer in the first element
     */
    iterator begin();
    /**
     * @brief Iterate to the last element
     * @return the pointer in the last element
     */
    iterator end();

    /**
     * @brief Iterate to the first element constant
     * @return the pointer in the first element constant
     */
    const_iterator cbegin() const;

    /**
     * @brief Iterate to the last element constant
     * @return the pointer in the last element constant
     */
    const_iterator cend() const;

    /**
     * @brief operator[] enter a integer
     */
    T& operator[](int i);
    /**
     * @brief operator[] enter a integer constant
     */
    const T& operator[](int i) const;
    /**
     * @brief operator< constante
     */
    bool operator<(List& other);

    /**
     * @brief operator< 
     */
    void sort();

public:
    struct Node;

    Node* m_first;
    Node* m_last;
};


template<typename T>
std::ostream& operator<<(std::ostream& os, const List<T>& tab);


#endif

#include "ListImpl.h"
