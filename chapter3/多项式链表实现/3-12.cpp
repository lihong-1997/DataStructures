#include "linkedlist.h"
#include <iostream>

using namespace linkedlist;
template class List<int>; //

int main()
{
	List<int> list1;

	for (int i = 0; i < 10; ++i)
	{
		list1.Insert(i);
	}
	list1.Traverse();

	list1.Reverse();
	list1.Traverse();

	return 0;
}