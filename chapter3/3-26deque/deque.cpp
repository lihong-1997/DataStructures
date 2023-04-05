#include <iostream>
#include "double_linklist.h"
using namespace std;
template class DList<int>;

int main()
{
	DList<int> dl;
	dl.Push(1);
	dl.Push(2);
	dl.Inject(10);
	dl.Inject(11);
	//2 1 10 11
	dl.Traverse();

	int v1 = dl.Pop();
	int v2 = dl.Eject();

	cout << "v1:" << v1 << "v2:" << v2 << endl;
	dl.Traverse();
}