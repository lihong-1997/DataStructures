#define _CRT_SECURE_NO_WARNINGS 1
#include "tree.h"

#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
};

SearchTree MakeEmpty(SearchTree T)
{
	if (T != NULL)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}
	return NULL;
}

Position Find(ElementType X, SearchTree T)
{
	if (T == NULL) return NULL;

	if (X < T->Element)
		return Find(X, T->Left);
	else if (X > T->Element)
		return Find(X, T->Right);
	else 
		return T;
}

Position IterFind(ElementType X, SearchTree T)
{
	while (T)
	{
		if (X < T->Element) T = T->Left;
		else if (X > T->Element) T = T->Right;
		else return T;
	}
	return NULL;
}

Position FindMin(SearchTree T)
{
	if (T == NULL) return NULL;

	else if (T->Left != NULL)
		return FindMin(T->Left);
	else
		return T;
}
Position FindMax(SearchTree T)
{
	if (T != NULL)
		while (T->Right) T = T->Right;
	return T;
}

Position Insert(ElementType X, SearchTree T)
{
	if (T == NULL)
	{
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
	}

	else if (X < T->Element)
		T->Left = Insert(X, T->Left);
	else if (X > T->Element)
		T->Right = Insert(X, T->Right);

	return T;
}

Position Delete(ElementType X, SearchTree T)
{
	Position tmp;
	if (T == NULL)
		printf("element not found");
	else if (X < T->Element)
		T->Left = Delete(X, T->Left);
	else if (X > T->Element)
		T->Right = Delete(X, T->Right);
	else
	{
		//处理两个节点的情况
		if (T->Left && T->Right)
		{
			//右子树找最小,填充要删除的节点
			tmp = FindMin(T->Right);
			T->Element = tmp->Element;
			T->Right = Delete(tmp->Element, T->Right);
		}
		else //处理一个节点或无节点
		{
			tmp = T;
			if ( T->Left == NULL)
				T = T->Right;
			else if (T->Right == NULL)
				T = T->Left;
			free(tmp);
		}
	}

	return T;
}

ElementType Retrieve(Position P)
{
	return P->Element;
}

void PreOrderTraversal(SearchTree T)
{
	if (T)
	{
		printf("%d", T->Element);
		PreOrderTraversal(T->Left);
		PreOrderTraversal(T->Right);
	}
}