
/**
 * @file list.h
 * @brief list class definition
 * ***List***
 */

#ifndef MY_LIST_H
#define MY_LIST_H

#include <string>

template<typename T>
class List
{
public:
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

    

private:
    struct Node;

    Node* m_first;
    Node* m_last;
};

#endif

#include "ListImpl.h"