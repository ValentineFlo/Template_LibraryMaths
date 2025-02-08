#ifndef MY_ALGO_H
#define MY_ALGO_H

#ifndef MY_ALGO_H
#error Do not include this header directly. Please inlude Algorithms.h
#endif

#include <iostream>

template <typename T>
void insertionSort(T* begin, size_t size)
{
    for (int i = 0; i < size; ++i) 
    {
       T key = begin[i];
        int j = i - 1; 

        while (j >= 0 && key < begin[j])
        {
            begin[j + 1] = begin[j];
            --j;
        }
        begin[j + 1] = key;
    }
}


template <typename T>
void merge(T* begin, size_t DebutG, size_t FinG, size_t DebutD, size_t FinD)
{
    size_t tmpCurrentGIdx = DebutG;
    size_t tmpCurrentDIdx = DebutD;
    size_t TabtmpSize = (FinG - DebutG + 1) + (FinD - DebutD + 1);
    size_t write = 0;
    T* tmpTab;
    tmpTab = new T[TabtmpSize];

    while ((tmpCurrentGIdx != FinG + 1) || (tmpCurrentDIdx != FinD + 1))
    {
        if (tmpCurrentGIdx == FinG + 1)
        {
            tmpTab[write] = begin[tmpCurrentDIdx];
            ++write;
            ++tmpCurrentDIdx;
        }
        else if (tmpCurrentDIdx == FinD + 1)
        {
            tmpTab[write] = begin[tmpCurrentGIdx];
            ++write;
            ++tmpCurrentGIdx;
        }

        else
            if (begin[tmpCurrentGIdx] <= begin[tmpCurrentDIdx])
            {
                tmpTab[write] = begin[tmpCurrentGIdx];
                ++tmpCurrentGIdx;
                ++write;
            }

            else
            {
                tmpTab[write] = begin[tmpCurrentDIdx];
                ++tmpCurrentDIdx;
                ++write;
            }
    }

    for (int i = 0; i < TabtmpSize; ++i)
    {
        begin[i + DebutG] = tmpTab[i];
    }


    delete[] tmpTab;
    tmpTab = nullptr;
}

template <typename T>
void sortdiviseMerge(T* begin, size_t DebutIdx, size_t FinIdx)
{
    if (DebutIdx == FinIdx)
        return;

    int milieux;
    milieux = (DebutIdx + FinIdx) / 2;

    sortdiviseMerge(begin, DebutIdx, milieux);
    sortdiviseMerge(begin, static_cast<size_t>(milieux) + 1, FinIdx);
    merge(begin, DebutIdx, milieux, static_cast<size_t>(milieux) + 1, FinIdx);
}

template <typename T>
bool sortSucess(T* begin, size_t size)
{
    for (size_t i = 1; i < size; ++i)
    {
        if (begin[i] < begin[i - 1])
        {
            throw std::runtime_error("uncessfull sort");
        }
    }
    return true;
}


template<typename T>
void sortimpl(T* begin, size_t size)
{
    if (size <= 10)
    {
        insertionSort(begin, size);
    }
    else
        sortdiviseMerge(begin, 0, size - 1); 

    sortSucess(begin, size); 
}

#endif