//#ifndef PRINTIMPL_IMPL_H
//#define PRINTIMPL_IMPL_H
//
//#include "Vector.h"
//#ifndef MY_ALGO_H
//#error "Do not include this header directly. Please inlude Algorithms.h" 
//#endif
//
//
//template<typename Type>
//void print(std::ostream& os, const Type& val);
//
//namespace details
//{
//    template<typename Type>
//    struct Print
//    {
//        static void doIt(std::ostream& os, const Type& val)
//        {
//            os << val;
//        }
//    };
//
//    template<>
//    struct Print<std::string>
//    {
//        static void doIt(std::ostream& os, const std::string& val)
//        {
//            os << "\"" << val << "\"";
//        }
//    };
//
//
//    template<typename TypeInsideVector>
//    struct Print<Vector<TypeInsideVector>>
//    {
//        static void doIt(std::ostream& os, const Vector<TypeInsideVector>& val)
//        {
//            os << "(";
//            for (size_t i = 0; i < val.size(); ++i)
//            {
//                print(os, val[i]);
//                if (i != val.size() - 1)
//                    os << ", ";
//            }
//            os << ")";
//        }
//    };
//}
//
//template<typename Type>
//void print(std::ostream& os, const Type& val)
//{
//    details::Print<Type>::doIt(os, val);
//}
//
//template<typename Type, size_t Size>
//void print(std::ostream& os, const Type& val) 
//{
//    ::print(os, val); 
//}
//
//#endif