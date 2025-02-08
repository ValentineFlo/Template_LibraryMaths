//#include <iostream>
//#include "AlgoInclude.h"
//
//
//template<typename Type>
//struct IntNode
//{
//    IntNode(const Type& value_)
//        : value(value_)
//    {
//    }
//
//    virtual ~IntNode()
//    {
//
//    }
//
//    IntNode* prev;
//    IntNode* next;
//    Type value;
//};
//
//template<typename Type>
//struct IntrusiveList
//{
//    IntrusiveList()
//        : m_anchor(0)
//    {
//        m_anchor.prev = m_anchor.next = &m_anchor;
//    }
//
//    void push_back(Type& node)
//    {
//        auto* prevNode = m_anchor.prev;
//
//        node.prev = prevNode;
//        node.next = &m_anchor;
//
//        m_anchor.prev = &node;
//        prevNode->next = &node;
//    }
//
//    bool is_empty() const
//    {
//        return m_anchor.prev == &m_anchor && m_anchor.next == &m_anchor;
//    }
//
//    size_t size() const
//    {
//        auto* currentNode = m_anchor.next;
//        size_t i = 0;
//        while (currentNode != &m_anchor)
//        {
//            ++i;
//            currentNode = currentNode->next;
//        }
//
//        return i;
//    }
//
//    static void remove(IntNode& node) 
//    {
//        IntNode* prevNode = node.prev;
//        IntNode* nextNode = node.next;
//
//        prevNode->next = nextNode;
//        nextNode->prev = prevNode;
//        node.prev = node.next = nullptr;
//    }
//
//    void sort(); 
//
//private:
//    IntNode m_anchor;
//};
//
//template<typename T>
//void IntrusiveList<T>::sort()
//{
//    sortimpl(m_anchor.value, size()); 
//}
//
//template<typename Type>
//struct Int : IntNode<Type>
//{
//    Int(const Type& value_)
//        : IntNode(value_)
//    {
//    }
//
//    ~Int()
//    {
//        IntrusiveList::remove(*this);
//    }
//};
//template<typename T>
//std::ostream& operator<<(std::ostream& os, const IntrusiveList<T>& list) 
//{
//    if (list.is_empty()) 
//    {
//        return os;
//    }
//
//    os << "(";
//    auto* currentNode = list.m_anchor.next; 
//    while (currentNode != &list.m_anchor) 
//    {
//        os << currentNode->value; 
//        currentNode = currentNode->next; 
//        if (currentNode != &list.m_anchor) 
//        {
//            os << " ";
//        }
//    }
//    os << ")";
//    return os;
//}