﻿#include "List.h"
#include "Array.h"
#include "Vector.h"




int main()
{

/// test list
    List<size_t> toto;
    toto.push_back(12);
    toto.push_back(42);
    toto.push_back(35);
    

    //iterateur array
    //for (auto it = begin(arr); it != end(arr); ++it) 
    //{ 
    //    std::cout << *it << " "; 
    //}
    //std::cout << std::endl;

    //toto.sort();

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

 //test array
    //Array<int, 5> arr = { 1, 2, 3, 4, 5 };

    //
    //arr.clear();
    //
    //for (const auto ptr : arr)
    //{
    //    std::cout << ptr << " "; 
    //}
    //std::cout << std::endl;

    // Test vector
        //Vector<int> vec;
        //vec.push_back(3);
        //vec.push_back(5);
        //vec.push_back(1);

        //std::cout << "Vecteur avant modif : " << vec << std::endl; // (1 2 3)
        //std::cout << "apres modif : " << vec << "\n" << " first : " << vec.front()<< "\n" << " last : " << vec.back() << "\n" << " element : " << vec.at(0) << "\n" << std::endl; // (1 2)

        //Vector<int> v;
        //v.reserve(3);
        //v.push_back(8.02f);
        //v.push_back(1.08f);
        //v.push_back(4.05f);

    // Test iterateur
      
      //Iterateur List
        /*for (auto it = toto.begin(); it != toto.end(); ++it)
        { 
            std::cout << *it << " ";
        }*/
        std::cout << std::endl;
        for (auto it = toto.end(); it != toto.begin(); --it) 
        {
            std::cout << *it << " "; 
        }
        
            
      //Iterateur array
        //    for (auto it = arr.begin(); it != arr.end(); ++it)
        //{ 
        //    std::cout << *it << " "; 
        //}
        //std::cout << std::endl;
      //Iterateur et vecteur 
        /*for (auto it = v.begin(); it != v.end(); ++it) 
        {
            std::cout << *it << " ";
        }*/


    /// test tri**********


        
        //std::cout  << "Avant : " << v << std::endl;
        //v.sort();
        //std::cout << "Apres : " << v << std::endl;

    return 0;

}
