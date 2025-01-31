#include <iostream>

struct IntNode
{
    IntNode(const int& value_)
        : value(value_)
    {
    }

    virtual ~IntNode()
    {

    }

    IntNode* prev;
    IntNode* next;
    int value;
};

struct IntrusiveList
{
    IntrusiveList()
        : m_anchor(0)
    {
        m_anchor.prev = m_anchor.next = &m_anchor;
    }

    void push_back(IntNode& node)
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

    static void remove(IntNode& node)
    {
        IntNode* prevNode = node.prev;
        IntNode* nextNode = node.next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
        node.prev = node.next = nullptr;
    }

private:
    IntNode m_anchor;
};

struct Int : IntNode
{
    Int(const int& value_)
        : IntNode(value_)
    {
    }

    ~Int()
    {
        IntrusiveList::remove(*this);
    }
};