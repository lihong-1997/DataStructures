#define _CRT_SECURE_NO_WARNINGS 1
#include "tree.h"
#include <stdio.h>

int main()
{
	int arr[8] = { 5,3,6,8,1,2,7,4 };
	SearchTree T = MakeEmpty(NULL);
	for (int i = 0; i < 8; ++i)
	{
		T = Insert(arr[i], T);
	}
	PreOrderTraversal(T);

	Position p1 = FindMin(T);
	Position p2 = FindMax(T);
	printf("\nmin:%d", Retrieve(p1));
	printf("\nmax:%d", Retrieve(p2));

	int searchVal = 2;
	Position p3 = Find(searchVal, T);
	printf("\nsearchVal:%d", Retrieve(p3));

	printf("\n");
	Delete(3, T);
	PreOrderTraversal(T);

	printf("\n");
	Delete(8, T);
	PreOrderTraversal(T);
	Position p4 = FindMax(T);
	printf("\nnew max:%d", Retrieve(p4));
	return 0;
}