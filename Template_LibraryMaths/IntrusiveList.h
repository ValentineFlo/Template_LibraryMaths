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
struct IntrusiveList
{
    IntrusiveList()
        : m_anchor(Type()) 
    {
        m_anchor.prev = m_anchor.next = &m_anchor;
    }

    void push_back(const Type& value)
    {
        auto* newNode = new IntNode<Type>(value); 
        push_back(*newNode);
    }

    void push_back(IntNode<Type>& node)
    {
        auto* prevNode = m_anchor.prev;

        node.prev = prevNode;
        node.next = &m_anchor;

        m_anchor.prev = &node;
        prevNode->next = &node;
    }

    bool is_empty() const
    {
        return m_anchor.prev == &m_anchor && m_anchor.next == &m_anchor;
    }

    size_t size() const
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

    void remove(const Type& value) 
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

    static void removeimpl(IntNode<Type>& node)
    {
        IntNode<Type>* prevNode = node.prev;
        IntNode<Type>* nextNode = node.next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        node.prev = node.next = nullptr;
        delete& node;
    }

    void sort(); 


public:
    IntNode<Type> m_anchor;
};

template<typename T>
void IntrusiveList<T>::sort()
{
    IntrusiveList<T> values;
    auto* currentNode = m_anchor.next;
    while (currentNode != &m_anchor) 
    {
        values.push_back(currentNode->value);
        currentNode = currentNode->next;
    }

    sortimpl(values.begin(), values.end());

    currentNode = m_anchor.next;
    for (const auto& value : values) 
    {
        currentNode->value = value;
        currentNode = currentNode->next;
    }
}

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