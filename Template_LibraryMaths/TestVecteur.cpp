//#include "Vector.h"
//
//
//int main()
//{   
//           Vector<int> vec;
//           vec.push_back(3);
//           vec.push_back(5);
//           vec.push_back(1);
//
//           std::cout << "Vecteur avant modif : " << vec << "\n" << " first : " << vec.front() << "\n" << " last : " << vec.back() << "\n" << " element : " << vec.at(1) << "\n" << std::endl; // (1 2 3)
//           std::cout << "apres modif : " << vec << "\n" << " first : " << vec.front()<< "\n" << " last : " << vec.back() << "\n" << " element : " << vec.at(1) << "\n" << std::endl; // (1 2)
//
//           Vector<float> v;
//           v.reserve(3);
//           v.push_back(8.02f);
//           v.push_back(1.08f);
//           v.push_back(2.05f);
//           v.push_back(5.08f);
//           v.push_back(4.05f);
//           v.push_back(3.08f);
//           v.push_back(7.05f);
//           v.push_back(9.02f);
//           v.push_back(12.08f);
//           v.push_back(43.05f);
//
//           std::cout << v.at(2) << std::endl;
//
//       // Test iterateur
// 
//           //Iterateur et vecteur 
//             /*for (auto it = v.begin(); it != v.end(); ++it)
//             {
//                 std::cout << *it << " ";
//             }*/
//
//            /// test tri**********
//           /// insertion sort
//            std::cout  << "Avant trie : " << vec << std::endl;
//            vec.sort();
//            std::cout << "Apres trie : " << vec << std::endl;
//            /// fusion sort
//            std::cout << "Avant trie : " << v << std::endl;
//            v.sort();
//            std::cout << "Apres trie : " << v << std::endl;
//
//    return 0;
//
//}
