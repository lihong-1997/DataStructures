#include "selfadjusting.h"

template class SelfAdjusting<int>;

int main()
{
	SelfAdjusting<int> l1(10);
	for (int i = 0; i < 6; ++i)
	{
		l1.Insert(i);
	}
	l1.Print();
	l1.Find(4);
	l1.Print();
}

