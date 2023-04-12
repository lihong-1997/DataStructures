#include "searchtree.h"
#include "queue.h"
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
	ElementType Element;
	SearchTree Left;
	SearchTree Right;
	int flag; // special for SeqToSearchTree.c
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

Position CreateNode(ElementType X)
{
	Position T;
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

static SearchTree RandomSearchTree1(int lower, int upper)
{
	SearchTree T;
	T = MakeEmpty(NULL);

	srand(time(NULL));
	int randomValue;

	if (lower <= upper)
	{
		randomValue = (rand() % (upper - lower + 1)) + lower;
		T = CreateNode(randomValue);
		T->Left = RandomSearchTree1(lower, randomValue -1);
		T->Right = RandomSearchTree1(randomValue + 1, upper);
	}

	return T;

}

SearchTree RandomSearchTree(int N)
{
	return RandomSearchTree1(1, N);
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
			T->flag = 0;
		}
	}

	else if (X < T->Element)
		T->Left = Insert(X, T->Left);
	else if (X > T->Element)
		T->Right = Insert(X, T->Right);

	return T;
}

Position IterInsert(ElementType X, SearchTree T)
{
	if (T == NULL)
		T = CreateNode(X);
	
	else
	{
		SearchTree node = T; // root can not be changed
		Position parent = NULL; // parent node of X;

		while (node != NULL)
		{
			parent = node;
			if (X < node->Element)
				node = node->Left;
			else	
				node = node->Right;	
		}
		node = CreateNode(X);
		// compare with parent node elemnt ,to decide left or right to combine
		if (X < parent->Element)
			parent->Left = node;
		else
			parent->Right = node;
	}

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
		if (T->Left && T->Right)
		{
			tmp = FindMin(T->Right);
			T->Element = tmp->Element;
			T->Right = Delete(tmp->Element, T->Right);
		}
		else
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

Position DeleteTl(ElementType X, SearchTree T)
{
	Position tmp;
	if (T == NULL)
		printf("element not found");
	else if (X < T->Element)
		T->Left = DeleteTl(X, T->Left);
	else if (X > T->Element)
		T->Right = DeleteTl(X, T->Right);
	else
	{
		if (T->Left && T->Right)
		{
			tmp = FindMax(T->Left);
			T->Element = tmp->Element;
			T->Left = DeleteTl(tmp->Element, T->Left);
		}
		else
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

Position DeleteRandom(ElementType X, SearchTree T, int seed)
{
	Position tmp;

	if (T == NULL)
		printf("element not found");
	else if (X < T->Element)
		T->Left = DeleteRandom(X, T->Left, seed);
	else if (X > T->Element)
		T->Right = DeleteRandom(X, T->Right, seed);
	else
	{
		if (T->Left && T->Right)
		{
			if (seed){
				tmp = FindMax(T->Left);
			    T->Element = tmp->Element;
			    T->Left = DeleteRandom(tmp->Element, T->Left, seed);
			}
			else{
				tmp = FindMin(T->Right);
			    T->Element = tmp->Element;
			    T->Right = DeleteRandom(tmp->Element, T->Right, seed);
			}

		}
		else
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

Position DeleteAlter(ElementType X, SearchTree T, int flag)
{
	Position tmp;

	if (T == NULL)
		printf("element not found");
	else if (X < T->Element)
		T->Left = DeleteAlter(X, T->Left, flag);
	else if (X > T->Element)
		T->Right = DeleteAlter(X, T->Right, flag);
	else
	{
		if (T->Left && T->Right)
		{
			if (flag){
				tmp = FindMin(T->Right);
			    T->Element = tmp->Element;
			    T->Right = DeleteAlter(tmp->Element, T->Right, flag);
			}
			else
			{
				tmp = FindMax(T->Left);
			    T->Element = tmp->Element;
			    T->Left = DeleteAlter(tmp->Element, T->Left, flag);
			}
		}
		else
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

int Height(SearchTree T)
{
	int HL, HR, MaxH;
	if (T)
	{
		HL = Height(T->Left);
		HR = Height(T->Right);
		MaxH = (HL > HR) ? HL : HR;
		return 1 + MaxH;
	}
	else
		return 0;

}

int GetBalansability(SearchTree T, int*balance)
{
	if (T == NULL)
		return 1;

	int diff = abs(Height(T->Left) - Height(T->Right));
	if (diff > *balance) *balance = diff; //max height difference

	return (diff <= 1) 
	    && GetBalansability(T->Left, balance)
	    && GetBalansability(T->Right, balance);
}

ElementType Retrieve(Position P)
{
	return P->Element;
}

void PreOrderTraversal(SearchTree T)
{
	if (T)
	{
		printf("%d ", T->Element);
		PreOrderTraversal(T->Left);
		PreOrderTraversal(T->Right);
	}
}

int PreOrderFullNode(SearchTree T)
{
	if (T)
	{
		if (T->Left && T->Right)
			return Retrieve(T);
		PreOrderFullNode(T->Left);
		PreOrderFullNode(T->Right);
	}
}

//get the count of node
int CountNode(SearchTree T)
{
	if (T == NULL)
		return 0;
	return 1 + CountNode(T->Left) + CountNode(T->Right);
}
//get the count of full node
int CountFullNode(SearchTree T)
{
	// 1.count of leaf + 1
	// 2.recursion
	if (T == NULL) 
		return 0;
	return (T->Left!=NULL && T->Right!=NULL)
		+ CountFullNode(T->Left) + CountFullNode(T->Right);
}
//get the count of leaf
int CountLeaf(SearchTree T)
{
	if (T == NULL) 
		return 0;
	else if (T->Left==NULL && T->Right==NULL)
		return 1;
	return CountLeaf(T->Left) + CountLeaf(T->Right);
}

int CheckSearchTree(SearchTree T)
{
	if (T == NULL)
		return 1;

	Position tNode = T;	

	Queue Q;
	Q = CreateQueue(20);
	Enqueue(tNode, Q);

	while (!IsQueueEmpty(Q))
	{
		tNode = FrontElement(Q);
		Dequeue(Q);
		if (tNode->Left)
		{
			if (tNode->Element > tNode->Left->Element)
				Enqueue(tNode->Left, Q);
			else
				return 0;
		}
		if (tNode->Right)
		{
			if (tNode->Element < tNode->Right->Element)
				Enqueue(tNode->Right, Q);
			else
				return 0;
		}
	}
	DisposeQueue(Q);
	return 1;
}

int rCheckSearchTree(SearchTree T)
{
	if (T == NULL)
		return 1;

	if (T->Left && T->Element <= T->Left->Element)
		return 0;

	if (T->Right && T->Element >= T->Right->Element)
		return 0;

	return CheckSearchTree(T->Left) && CheckSearchTree(T->Right);
}

void PrintRange(SearchTree T, int k1, int k2)
{
    if (T != NULL)
    {
        if (k1 <= T->Element)
			PrintRange(T->Left, k1, k2);
		if (T->Element >= k1 && T->Element <= k2)
			printf("%d\n", T->Element);
		if (k2 >= T->Element)
			PrintRange(T->Right, k1, k2);
    }
}

void LevelOrderTraversal(SearchTree T, int* Dn)
{
	if (T == NULL)
		return;

	Position tNode = T;	

	Queue Q;
	Q = CreateQueue(20);

	Enqueue(tNode, Q);

	int depth = 0;
	*Dn = 0; // internal path length
	while (!IsQueueEmpty(Q))
	{
		int size = QueueSize(Q);
		
		for (int i = 0;i < size;i++)
		{
			tNode = FrontElement(Q);
			*Dn += depth;
			printf("depth %d: node %d\n", depth, tNode->Element);
			Dequeue(Q);
			if (tNode->Left)
				Enqueue(tNode->Left, Q);
			if (tNode->Right)
				Enqueue(tNode->Right, Q);
		}
		depth++;
	}

	DisposeQueue(Q);

}

int isSimilar(SearchTree T1, SearchTree T2)
{
	/* 
	 * if (T1 == NULL && T2 == NULL) return 1; //both is null
	 * if (!(T1&&T2)) return 0; // one of is null
	*/

	//after simplify
	if (T1 == NULL || T2 == NULL)
		return T1 == NULL && T2 == NULL;
	return isSimilar(T1->Left, T2->Left) && isSimilar(T1->Right, T2->Right);
}

int isSame(SearchTree T1, SearchTree T2)
{
	//both is null
	if (T1 == NULL && T2 == NULL) return 1;
	// one of is null or neither is null but element does not equal
	if (!(T1 && T2) || T1->Element != T2->Element) return 0;
	
	return isSame(T1->Left, T2->Left) && isSame(T1->Right, T2->Right);
}

// int isIsomorphic(SearchTree T1, SearchTree T2)
// {
// 	if (T1 == NULL && T2 == NULL) return 1;
// 	// Exclusion of heterogeneous situations
// 	if (T1 == NULL || T2 == NULL) return 0;
// 	if (T1->Element != T2->Element) return 0;

// 	return (isIsomorphic(T1->Left, T2->Left) && isIsomorphic(T1->Right, T2->Right))
//            || (isIsomorphic(T1->Left, T2->Right) && isIsomorphic(T1->Right, T2->Left));
// }


//special for SeqToSearchTree.c
int check(SearchTree T, int value)
{
    if (T->flag == 1) {
		if (value < T->Element)
			return check(T->Left, value);
		else if (value > T->Element)
			return check(T->Right, value);
		else return 0; //value repeated
	}
	else {
		if (value == T->Element) {
			T->flag = 1;
			return 1;
		}
		return 0;
	}
}