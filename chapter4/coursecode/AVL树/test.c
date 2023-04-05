#define _CRT_SECURE_NO_WARNINGS 1
#include "avltree.h"
#include <stdio.h>


int main()
{
	AvlTree T;
	T = MakeEmpty(NULL);

	int arr[8] = { 5,3,6,8,1,2,7,4 };

	for (int i = 0; i < 8; ++i)
	{
		T = Insert(arr[i], T);
	}
	//PreOrderTraversal(T);

	//Delete(4, T); //5213768
	//Delete(1, T); //5324768
	//Delete(2, T); //5314768
	deleteNode(T, 5);
	deleteNode(T, 8);
	//PreOrderTraversal(T);
	//Delete(8, T);
	PreOrderTraversal(T);
	return 0;
}