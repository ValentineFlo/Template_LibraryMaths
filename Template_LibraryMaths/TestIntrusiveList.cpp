#include <iostream>
#include "IntrusiveList.h"

int main()
{
	IntrusiveList<float> list;

	list.push_back(10.89);
	list.push_back(12.54);
	list.push_back(1.65);
	list.push_back(20.56);
	std::cout << list << std::endl;

	std::cout << list.size() << std::endl;
	std::cout << list << std::endl;
	list.remove(1.65);
	std::cout << list.size() << std::endl;
	std::cout << list << std::endl;
	list.sort();
	std::cout << list << std::endl;


};