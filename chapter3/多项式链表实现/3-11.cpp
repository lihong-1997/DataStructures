#include "linkedlist.h"
#include <iostream>

using namespace linkedlist;
template class List<int>; //

int main5()
{
	List<int> list1;

	for (int i = 0; i < 20; ++i)
	{
		list1.Insert(i);
	}
	list1.Traverse();
	std::cout << (list1.Find(10) == list1.Find_recursive(10)) << std::endl;

	//²âÊÔµİ¹éºÎÊ±Òç³ö
	for (int i = 0; i < 5000; ++i)
	{
		list1.Insert(i);
	}
	list1.Insert(47);
	std::cout << list1.Find(4900) << std::endl;
	std::cout << list1.Find_recursive(4900) << std::endl;

	return 0;
}