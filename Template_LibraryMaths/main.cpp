#include "List.h"
#include "Array.h"
#include "Algorithms.h"
#include "Vector.h"

#include <iostream>

int main()
{

/// test list
    //List<size_t> toto;
    //toto.push_back(12);
    //std::cout << toto.back() << std::endl;
    //toto.push_back(42);
    //std::cout << toto.back() << std::endl;
    //toto.pop_back();
    //std::cout << toto.size() << std::endl;
    //std::cout << toto.back() << std::endl;
    //toto.pop_back();
    //std::cout << toto.size() << std::endl;
    //
    //std::cout << "\n\n";
    //
    //toto.push_front(36);
    //toto.push_front(24);
    //std::cout << toto.size() << std::endl;
    //std::cout << toto.front() << std::endl;
    //toto.pop_front();
    //std::cout << toto.size() << std::endl;
    //std::cout << toto.front() << std::endl;
    //toto.pop_front();
    //std::cout << toto.size() << std::endl;

/// test array
    //Array<int, 5> arr = { 1, 2, 3, 4, 5 };
    //for (auto it = arr.rbegin(); it >= arr.rend(); --it) 
    //{
    //    std::cout << *it << " ";
    //}
    //std::cout << std::endl;
    //
    //arr.clear();
    //
    //for (const auto ptr : arr)
    //{
    //    std::cout << ptr << " "; 
    //}
    //std::cout << std::endl;

        Vector<int> vec;
        vec.push_back(3);
        vec.push_back(5);
        vec.push_back(3);

        std::cout << "Vecteur apres push_back : " << vec << std::endl; // (1 2 3)
        //vec.pop_back();
        std::cout << "Apres pop_back : " << vec << " first : " << vec.front() << " last : " << vec.back() << " element : " << vec.at(2) << std::endl; // (1 2)


        //std::cout << "Élément à l'index 1 : " << vec[1] << std::endl; // 2


    /// test tri**********
        /*std::cout << v[0] << std::endl;

        std::cout << v << std::endl;*/

    return 0;

}