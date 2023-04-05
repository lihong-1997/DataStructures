#include "linkedlist.h"
#include <iostream>

using namespace linkedlist;
template class List<int>; //

int main88()
{
	List<int> list1;
	list1.Insert(2);
	list1.Insert(4);
	list1.Insert(7);
	list1.Insert(9);
	list1.Insert(11);
	list1.Traverse();

	std::cout << "size:" << list1.size() << std::endl;
	list1.Remove(9);
	std::cout << "size:" << list1.size() << std::endl;
	list1.Traverse();

	Node<int>* p1 = list1.Find(4);
	std::cout << list1.Retrieve(p1) << std::endl;
	list1.Insert(5, p1);
	list1.Traverse();

	Node<int>* p2 = list1.Find_pre(5);
	std::cout << list1.Retrieve(p2) << std::endl;

	int i = 5;
	Node<int>* p3 = list1.Find_Kth(i);
	std::cout << i << "th:" << list1.Retrieve(p3) << std::endl;

	list1.DeleteList();

	return 0;
}