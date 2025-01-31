#ifndef MY_SORT_H
#error Do not include this header directly. Please inlude Sort.h
#endif

//template<typename T>
//typename Algorithms<T>& Algorithms<T>::sort() 
//{
//    if 
//}


template <typename T, size_t N>
void trisInsertion(T* Tab)
{
    for (int i = 0; i < N; ++i) 
    {
       T clef = Tab[i];
        T j = i - 1; 

        while (j >= 0 && clef < Tab[j])
        {
            Tab[j + 1] = Tab[j];
            --j;
        }
        Tab[j + 1] = clef;
    }
}


template <typename T, size_t N>
void trisMerge(T Tab[N], T DebutG, T FinG, T DebutD, T FinD)
{
    T tmpCurrentGIdx = DebutG;
    T tmpCurrentDIdx = DebutD;
    T TabtmpSize = (FinG - DebutG + 1) + (FinD - DebutD + 1);
    T Ecrire = 0;
    T* tmpTab;
    tmpTab = new T[TabtmpSize];

    while ((tmpCurrentGIdx != FinG + 1) || (tmpCurrentDIdx != FinD + 1))
    {
        if (tmpCurrentGIdx == FinG + 1)
        {
            tmpTab[Ecrire] = Tab[tmpCurrentDIdx];
            ++Ecrire;
            ++tmpCurrentDIdx;
        }
        else if (tmpCurrentDIdx == FinD + 1)
        {
            tmpTab[Ecrire] = Tab[tmpCurrentGIdx];
            ++Ecrire;
            ++tmpCurrentGIdx;
        }

        else
            if (Tab[tmpCurrentGIdx] <= Tab[tmpCurrentDIdx])
            {
                tmpTab[Ecrire] = Tab[tmpCurrentGIdx];
                ++tmpCurrentGIdx;
                ++Ecrire;
            }

            else
            {
                tmpTab[Ecrire] = Tab[tmpCurrentDIdx];
                ++tmpCurrentDIdx;
                ++Ecrire;
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
void Divise(T Tab[N], T DebutIdx, T FinIdx)
{
    if (DebutIdx == FinIdx)
        return;

    T milieux;
    milieux = (DebutIdx + FinIdx) / 2;

    Divise(Tab, DebutIdx, milieux);
    Divise(Tab, milieux + 1, FinIdx);
    trisMerge(Tab, DebutIdx, milieux, milieux + 1, FinIdx);
}