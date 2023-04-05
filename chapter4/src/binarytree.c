#include <stdlib.h>
#include <stdio.h>
#include "binarytree.h"

BinaryTree CreateNode(ElementType X)
{
	BinaryTree T;
	T = malloc(sizeof(struct TreeNode));
	if (T == NULL)
	{
		printf("out of space");
		exit(1);
	}
	else
	{
		T->Element = X;
		T->Left = T->Right = NULL;
	}

	return T;
}

void PreOrderTraversal(BinaryTree T)
{
    if (T)
	{
		printf("%c ", T->Element);
		PreOrderTraversal(T->Left);
		PreOrderTraversal(T->Right);
	}
}

int isIsomorphic(BinaryTree T1, BinaryTree T2)
{
	if (T1 == NULL && T2 == NULL) return 1;
	// Exclusion of heterogeneous situations
	if (T1 == NULL || T2 == NULL) return 0;
	if (T1->Element != T2->Element) return 0;

	return (isIsomorphic(T1->Left, T2->Left) && isIsomorphic(T1->Right, T2->Right))
           || (isIsomorphic(T1->Left, T2->Right) && isIsomorphic(T1->Right, T2->Left));
}