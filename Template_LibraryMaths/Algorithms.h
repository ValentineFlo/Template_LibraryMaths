#ifndef MY_ALGO_H
#define MY_ALGO_H

#include "Vector.h"

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


template<typename Type>
void print(std::ostream& os, const Type& val);

namespace details
{
    template<typename Type>
    struct Print
    {
        static void doIt(std::ostream& os, const Type& val)
        {
            os << val;
        }
    };

    template<>
    struct Print<std::string>
    {
        static void doIt(std::ostream& os, const std::string& val)
        {
            os << "\"" << val << "\"";
        }
    };


    template<typename TypeInsideVector>
    struct Print<Vector<TypeInsideVector>>
    {
        static void doIt(std::ostream& os, const Vector<TypeInsideVector>& val)
        {
            os << "(";
            for (size_t i = 0; i < val.size(); ++i)
            {
                print(os, val[i]);
                if (i != val.size() - 1)
                    os << ", ";
            }
            os << ")";
        }
    };
}

template<typename Type>
void print(std::ostream& os, const Type& val)
{
    details::Print<Type>::doIt(os, val);
}



#endif

#include "SortImpl.h"