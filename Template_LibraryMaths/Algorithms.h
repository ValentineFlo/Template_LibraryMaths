#ifndef MY_ALGO_H
#define MY_ALGO_H

#include "Vector.h"

template<typename T, size_t N>
class Algorithms
{
public:
	Algorithms() {};
	void sort(T Tab[N]);
	/*void print(std::ostream& os, const Type& val); */

private:

	void insertionSort(T* Tab); 
	void sortdiviseMerge(T Tab[N], size_t DebutIdx, size_t FinIdx);
	void merge(T Tab[N], size_t DebutG, size_t FinG, size_t DebutD, size_t FinD);
	bool sortSucess(T Tab[N]) const;
};



#endif

#include "SortImpl.h"
#include "PrintImpl.h"