#include <iostream>
#include "IntrusiveList.h"

int main()
{
	IntrusiveList<float> list;

	list.push_back(20.56f);
	list.push_back(10.89f);
	list.push_back(12.54f);
	list.push_back(28.26f);
	list.push_back(1.65f);

	std::cout << list << std::endl;

	std::cout << list.size() << std::endl;
	std::cout << list << std::endl;
	list.remove(1.65f);
	std::cout << list.size() << std::endl;
	std::cout << list << std::endl;
	list.sort();

	// iterateur
	//for (auto it = list.begin(); it != list.end(); ++it)
	//{
	//	std::cout <<*it << " ";
	//}
	std::cout << std::endl;

	std::cout << list << std::endl;
	std::cout << list.front() << std::endl;


};