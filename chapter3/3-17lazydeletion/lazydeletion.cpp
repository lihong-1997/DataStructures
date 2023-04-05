#include "linkedlist.h"
#include <iostream>

using namespace linkedlist;
template class List<int>;

int main()
{
	List<int> l1;
	for (int i = 0; i < 8; ++i)
	{
		l1.Insert(i);
	}
	l1.Traverse();

	l1.LazyDelete(5);
	l1.Traverse();
	std::cout << l1.size() << std::endl;

	l1.LazyDelete(4);
	l1.LazyDelete(6);
	l1.LazyDelete(2);
	l1.Traverse();
	std::cout << l1.size() << std::endl;

}