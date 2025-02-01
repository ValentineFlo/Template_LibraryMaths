#ifndef MY_ALGO_H
#define MY_ALGO_H

template<typename T, size_t N>
class Algorithms
{
public:
	Algorithms() {};
	void sort(T Tab[N]);

private:
	void sortdiviseMerge(T Tab[N], size_t DebutIdx, size_t FinIdx);
	void merge(T Tab[N], size_t DebutG, size_t FinG, size_t DebutD, size_t FinD);
	bool sortSucess(T Tab[N]) const;
};



#endif

#include "SortImpl.h"