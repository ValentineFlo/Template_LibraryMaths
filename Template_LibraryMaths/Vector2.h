#include <iostream>

struct VectorInt
{
    VectorInt()
        : pBegin(nullptr)
        , pEnd(nullptr)
        , pCapacity(nullptr)
    {}

    int& operator[](int i)
    {
         return *(pBegin + i);
    }

    int size()
    {
        return pEnd - pBegin;
    }

    void pushBack(int value)
    {
        auto prevSize = size();
        auto newSize = prevSize + 1;

        if (pEnd < pCapacity)
        {
            *pEnd = value;
            ++pEnd;
        }
        else
        {
            auto tmp = new int[size() + 1];
            for (auto* it = pBegin, i = 0; it != pEnd; ++it, ++i)
                tmp[i] = *it;

            tmp[prevSize] = value;

            delete[] pBegin;
            pBegin = tmp;
            pEnd = tmp + newSize;
        }
    }

    size_t at(size_t elem)
    {
        if (elem >= size())
            throw std::out_of_range("Index out of range");
        return pBegin[elem];
    }

    void reserve(int capacity)
    {
        if (!pBegin && !pEnd)
        {
            pBegin = new int[capacity];
            pEnd = pBegin;
            pCapacity = pBegin + capacity;
        }
    }

    int* pBegin;
    int* pEnd;
    int* pCapacity;
};


