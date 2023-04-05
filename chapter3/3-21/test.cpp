#include "double_stack.h"
#include <iostream>

using namespace std;
template class Double_Stack<int>;

int main()
{
	Double_Stack<int> ds(8);
	cout << "double stack size:" << ds.size() << endl;

	ds.leftpush(2);
	ds.rightpush(9);
	cout << "left stack size:" << ds.lsize()
		 << " right stack size:" << ds.rsize() << endl;

	ds.leftpush(2);
	ds.leftpush(3);
	ds.leftpush(4);
	ds.leftpush(5);
	ds.rightpush(10);
	ds.rightpush(11);
	cout << "left stack size:" << ds.lsize()
		<< " right stack size:" << ds.rsize() << endl;

	ds.leftpush(5);

	ds.leftpop();
	ds.rightpop(); ds.rightpop();
	cout << "left stack size:" << ds.lsize()
		<< " right stack size:" << ds.rsize() << endl;

	return 0;
}