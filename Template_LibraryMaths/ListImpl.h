#ifndef MY_LIST_H
#error Do not include this header directly. Please inlude List.h
#endif

template<typename T>
struct List<T>::Node
{
    Node(const T& value_) : value(value_), previous(nullptr), next(nullptr) {}
    T value;
    Node* previous;
    Node* next;
};

template<typename T>
List<T>::List() : m_first(nullptr), m_last(nullptr)
{
}

template<typename T>
List<T>::~List()
{
    Node* ptr = m_first;
    while (ptr != nullptr)
    {
        Node* nextPtr = ptr->next;
        delete ptr;
        ptr = nextPtr;
    }
}

template<typename T>
void List<T>::push_back(const T& elem)
{
    Node* newNode = new Node{ elem };
    newNode->next = nullptr;
    if (m_last == nullptr)
    {
        m_last = newNode;
        m_first = newNode;
        newNode->previous = nullptr;
    }
    else
    {
        m_last->next = newNode;
        newNode->previous = m_last;
        m_last = newNode;
    }
}

template<typename T>
void List<T>::push_front(const T& elem)
{
    Node* newNode = new Node{ elem };
    newNode->previous = nullptr;
    if (m_first == nullptr)
    {
        m_last = newNode;
        m_first = newNode;
        newNode->next = nullptr;
    }
    else
    {
        m_first->previous = newNode;
        newNode->next = m_first;
        m_first = newNode;
    }
}

template<typename T>
void List<T>::pop_back()
{
    if (m_first == m_last)
    {
        delete m_last;
        m_first = nullptr;
        m_last = nullptr;
    }
    else
    {
        m_last->previous->next = nullptr;
        Node* formerLast = m_last;
        m_last = m_last->previous;
        delete formerLast;

    }
}

template<typename T>
void List<T>::pop_front()
{
    if (m_first == m_last)
    {
        delete m_first;
        m_first = nullptr;
        m_last = nullptr;
    }
    else
    {
        m_first->next->previous = nullptr;
        Node* formerFirst = m_first;
        m_first = m_first->next;
        delete formerFirst;
    }
}

template<typename T>
const T& List<T>::back() const
{
    return m_last->value;
}

template<typename T>
const T& List<T>::front() const
{
    return m_first->value;
}

template<typename T>
typename List<T>::iterator List<T>::begin()
{
    return iterator(m_first);
}

template<typename T>
typename List<T>::iterator List<T>::end()
{
    return iterator(m_last);
}


template<typename T>
typename List<T>::const_iterator List<T>::cbegin() const
{
    return const_iterator(m_first);
}

template<typename T>
typename List<T>::const_iterator List<T>::cend() const
{
    return const_iterator(m_last);
}

template<typename T>
void List<T>::sort()
{
    size_t size = this->size();
    T* array = new T[size];

    Node* currentNode = m_first;
    for (size_t i = 0; i < size; ++i)
    {
        array[i] = currentNode->value;
        currentNode = currentNode->next;
    }
    sortimpl(array, size);

    currentNode = m_first;
    for (size_t i = 0; i < size; ++i)
    {
        currentNode->value = array[i];
        currentNode = currentNode->next;
    }
    delete[] array;
}


template<typename T>
size_t List<T>::size() const
{
    size_t size = 0;
    Node* ptr = m_first;
    while (ptr != nullptr)
    {
        ptr = ptr->next;
        size++;
    }

    return size;
}

template<typename T>
T& List<T>::operator[](int i) 
{
    Node* ptr = m_first;

    for (int index = 0; index < i; ++index)
    {
        ptr = ptr->next;
    }
    return ptr->value;

}


template<typename T>
const T& List<T>::operator[](int i) const
{
    Node* ptr = m_first;
    
    for (int index = 0; index < i; ++index)
    {
        ptr = ptr->next;
    }
    return ptr->value;

}

template<typename T>
bool List<T>::operator<(List& other)
{
    if (this->size() != other.size()) 
    {
        return this->size() < other.size();
    }

    while (m_first != nullptr && other.m_first != nullptr)
    {
        if (m_first->value < other.m_first->value)
        {
            return true;
        }

        if (m_first->value > other.m_first->value)
        {
            return false;
        }

        m_first = m_first->next;
        other.m_first = other.m_first->next;
    }
    return false;
}

template<typename T>
std::ostream& operator<<(std::ostream& os, const List<T>& tab)
{
    size_t size = tab.size();
    if (size == 0)
    {
        os << "";
        return os;
    }
    for (size_t i = 0; i < size - 1; ++i)
    {
        os << tab[i] << " "; 
    }
    os << tab[size - 1];
    return os;
}

