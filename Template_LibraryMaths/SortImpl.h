#ifndef MY_ALGO_H
#error Do not include this header directly. Please inlude Algorithms.h
#endif


template<typename T, size_t N>
void Algorithms<T, N>::sort(T Tab[N])
{
    if (N <= 10)
    {
        insertionSort(Tab);
    }
    else
        sortdiviseMerge(Tab, 0, N - 1);

    sortSucess(Tab);
}


template <typename T, size_t N>
void Algorithms<T, N>::insertionSort(T* Tab)
{
    for (int i = 0; i < N; ++i) 
    {
       T clef = Tab[i];
        int j = i - 1; 

        while (j >= 0 && clef < Tab[j])
        {
            Tab[j + 1] = Tab[j];
            --j;
        }
        Tab[j + 1] = clef;
    }
}


template <typename T, size_t N>
void Algorithms<T, N>::merge(T Tab[N], size_t DebutG, size_t FinG, size_t DebutD, size_t FinD)
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
            tmpTab[write] = Tab[tmpCurrentDIdx];
            ++write;
            ++tmpCurrentDIdx;
        }
        else if (tmpCurrentDIdx == FinD + 1)
        {
            tmpTab[write] = Tab[tmpCurrentGIdx];
            ++write;
            ++tmpCurrentGIdx;
        }

        else
            if (Tab[tmpCurrentGIdx] <= Tab[tmpCurrentDIdx])
            {
                tmpTab[write] = Tab[tmpCurrentGIdx];
                ++tmpCurrentGIdx;
                ++write;
            }

            else
            {
                tmpTab[write] = Tab[tmpCurrentDIdx];
                ++tmpCurrentDIdx;
                ++write;
            }
    }

    for (int i = 0; i < TabtmpSize; ++i)
    {
        Tab[i + DebutG] = tmpTab[i];
    }


    delete[] tmpTab;
    tmpTab = nullptr;
}

template <typename T, size_t N>
void Algorithms<T, N>::sortdiviseMerge(T Tab[N], size_t DebutIdx, size_t FinIdx)
{
    if (DebutIdx == FinIdx)
        return;

    int milieux;
    milieux = (DebutIdx + FinIdx) / 2;

    sortdiviseMerge(Tab, DebutIdx, milieux);
    sortdiviseMerge(Tab, static_cast<size_t>(milieux) + 1, FinIdx);
    merge(Tab, DebutIdx, milieux, static_cast<size_t>(milieux) + 1, FinIdx);
}

template <typename T, size_t N>
bool Algorithms<T, N>:: sortSucess(T Tab[N]) const
{
    for (size_t i = 1; i < N; ++i)
    {
        if (Tab[i] < Tab[i - 1])
        {
            throw std::runtime_error("uncessfull sort");
        }
    }
    return true;
}
