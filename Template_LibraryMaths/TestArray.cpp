//// Array Test. Please decommented for testing please
//
//#include <iostream>
//#include "Array.h"
//
//int main()
//{
//	Array<int, 5> arr = { 1, 2, 5, 4, 3 };
//	Array<int, 5> arrs = { 10, 20, 30, 40, 50};
//
//	for (const auto ptr : arr)
//	{
//		std::cout << ptr << " ";
//	}
//	std::cout << std::endl;
//
//	for (auto it = arr.begin(); it != arr.end(); ++it)
//	{
//		std::cout << *it << " ";
//	}
//	std::cout << std::endl;
//
//	// pb de depassement de memoire de la fonction et de reallocation
//	//std::cout << arr.at(2) << std::endl;
//
//
//	// pb ne commence pas a un
//	//for (auto it = arr.end(); it != arr.begin(); --it)
//	//{
//	//	std::cout << *it << " "; 
//	//}
//
//	// Insertion Sort
//
//	std::cout << arr.at(2) << std::endl;
//
//	arrs.swap(arr);
//	std::cout << arrs << std::endl;
//
//	arrs.sort();
//	std::cout << arrs << std::endl;
//
//	// pb ne pas utiliser le swap de la stl
//	//arr.swap(arrs);
//	std::cout << arr << std::endl;
//
//	std::cout << arr.at(2) << std::endl;
//
//	arr.clear();
//	std::cout << arr << std::endl;
//	std::cout << std::endl;
//	std::cout << std::endl;
//
//}