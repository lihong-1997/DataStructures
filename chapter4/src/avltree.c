#include "avltree.h"
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct AvlNode
{
	ElementType element;
	AvlTree Left;
	AvlTree Right;
	int Height;
};

static int Max(int LH, int RH)
{
	return (LH > RH) ? LH : RH;
}

static int Height(Position P)
{
	if (P == NULL)
		return -1;
	else
		return P->Height;
}

Position CreateNode(ElementType X)
{
    Position T;
    T = malloc(sizeof(struct AvlNode));
	if (T == NULL)
	{
	    fprintf(stderr, "out of space");
		exit(1);
	}
	else
	{
		T->element = X;
		T->Left = T->Right = NULL;
		T->Height = 0;
	}
	return T;
}

static Position SingleRotateWithLeft(Position k2) //LL
{
	Position k1;
	k1 = k2->Left;

	k2->Left = k1->Right;
	k1->Right = k2;

	k2->Height = Max(Height(k2->Left), Height(k2->Right)) + 1;
	k1->Height = Max(Height(k1->Left), k2->Height) + 1;

	return k1;
}

static Position SingleRotateWithRight(Position k2) //RR
{
	Position k1;
	k1 = k2->Right;

	k2->Right = k1->Left;
	k1->Left = k2;

	k2->Height = Max(Height(k2->Left), Height(k2->Right)) + 1;
	k1->Height = Max(k2->Height, Height(k1->Right)) + 1;

	return k1;
}

static Position DoubleRotateWithLeft(Position k3) //LR
{
	k3->Left = SingleRotateWithRight(k3->Left);

	return SingleRotateWithLeft(k3);
}
// more effective,first deal the child node of k2, then deal k1 k2 k3
static Position eDoubleRotateWithLeft(Position k3) //LR
{
	Position k1, k2;
	k1 = k3->Left;
	k2 = k1->Right;

	k3->Left = k2->Right;
	k1->Right = k2->Left;
	k2->Right = k3;
	k2->Left = k1;

	k1->Height = Max(Height(k1->Left), Height(k1->Right)) + 1;
	k3->Height = Max(Height(k3->Left), Height(k3->Right)) + 1;
	k2->Height = Max(k1->Height, k3->Height) + 1;

	return k2;
}

static Position eDoubleRotateWithRight(Position k3) //LR
{
	Position k1, k2;
	k1 = k3->Right;
	k2 = k1->Left;

	k3->Right = k2->Left;
	k1->Left = k2->Right;
	k2->Left = k3;
	k2->Right = k1;

	k1->Height = Max(Height(k1->Left), Height(k1->Right)) + 1;
	k3->Height = Max(Height(k3->Left), Height(k3->Right)) + 1;
	k2->Height = Max(k1->Height, k3->Height) + 1;

	return k2;
}

static Position DoubleRotateWithRight(Position k3) //RL
{
	k3->Right = SingleRotateWithLeft(k3->Right);

	return SingleRotateWithRight(k3);
}

AvlTree MakeEmpty(AvlTree T)
{
	if (T)
	{
		MakeEmpty(T->Left);
		MakeEmpty(T->Right);
		free(T);
	}

	return NULL;
}

Position Find(ElementType X, AvlTree T)
{
	if (T == NULL)
		return NULL;
	if (X < T->element) 
		return Find(X, T->Left);
	else if (X > T->element) 
		return Find(X, T->Right);
	else
		return T;
}
Position FindMin(AvlTree T)
{
	if (T == NULL)
		return NULL;

	if (T->Left != NULL)
		return FindMin(T->Left);
	else
		return T;
}
Position FindMax(AvlTree T)
{
	if (T != NULL)
		while (T->Right != NULL)
			T = T->Right;

	return T;
}

AvlTree Insert(ElementType X, AvlTree T)
{
	if (T == NULL)
        T = CreateNode(X);
	
	else if (X < T->element) //X is in the left subtree of T
	{
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2)
		{
			if (X < T->Left->element) //LL
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T); //LR
		}
	}
	else if (X > T->element) //
	{
		T->Right = Insert(X, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
		{
			if (X > T->Right->element) //RR
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T); //RL
		}
	}

	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;

	return T;
}

AvlTree IterInsert(ElementType X, AvlTree T)
{
    if (T == NULL)
		T = CreateNode(X);
	
	else
	{
		// use stack to save these meet nodes in the path
		Stack S;
		S = CreateStack();

		AvlTree node = T; // root can not be changed
		Position parent = NULL; // parent node of X;

		while (node != NULL)
		{
			parent = node;
			if (X < node->element)
				node = node->Left;
			else	
				node = node->Right;
			Push(parent, S);
		}
		node = CreateNode(X);
		// compare with parent node elemnt ,to decide left or right to combine
		if (X < parent->element) parent->Left = node;
		else parent->Right = node;

		Position TOP = NULL;
		while (!IsEmpty(S))
		{
			TOP = Top(S);
			Pop(S);
			TOP->Height = Max(Height(TOP->Left), Height(TOP->Right)) + 1;
			if (abs(Height(TOP->Left) - Height(TOP->Right)) == 2)
			{
				if (TOP->element < node->element && TOP->Right->element < node->element)
					//RR
					TOP = SingleRotateWithRight(TOP);
				else if (TOP->element < node->element && TOP->Right->element > node->element)
					//RL
					TOP = eDoubleRotateWithRight(TOP);
				else if (TOP->element > node->element && TOP->Left->element > node->element)
					//LL
					TOP = SingleRotateWithLeft(TOP);
				else if (TOP->element > node->element && TOP->Left->element < node->element)
					//LR
					TOP = eDoubleRotateWithLeft(TOP);
				break;
			}
		}
		if (IsEmpty(S))
			T = TOP;
		else
		{
			Position temp;
			temp = Top(S);
			if (temp->element < TOP->element)
			{
				temp->Right = TOP;
			}
			else
				temp->Left = TOP;
		}
	}

	return T;
}

AvlTree Delete(ElementType X, AvlTree T)
{
	if (T == NULL)
	{
		printf("element not found");
		return NULL;
	}
	Position tmp;

	if (X < T->element)
	{
		T->Left = Delete(X, T->Left);

		T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
		if (Height(T->Right) - Height(T->Left) == 2)
		{
			if (Height(T->Right->Right) > Height(T->Right->Left))
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T);
		}
	}
		
	else if (X > T->element)
	{
		T->Right = Delete(X, T->Right);

		T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
		if (Height(T->Left) - Height(T->Right) == 2)
		{
			//tmp = T->Left;
			if (Height(T->Left->Left) > Height(T->Left->Right))
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T);
		}
	}
		
	else
	{
		if (T->Left && T->Right)
		{
			tmp = FindMin(T->Right);
			T->element = tmp->element;
			T->Right = Delete(tmp->element, T->Right);

			T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
		}
		else
		{
			tmp = T;
			if (T->Left == NULL)
				T = T->Right;
			else if(T->Right == NULL)
				T = T->Left;
			free(tmp);
		}
	}

	return T;
}

ElementType Retrieve(Position P)
{
	return P->element;
}

void PreOrderTraversal(AvlTree T)
{
	if (T)
	{
		printf("%d,height %d\n", T->element, T->Height);
		PreOrderTraversal(T->Left);
		PreOrderTraversal(T->Right);
	}
}

int MinNodeCount(int H)
{
    if (H <= 1)
        return H + 1;
    
    int S[H + 1];
    S[0] = 1, S[1] = 2;
    
    for (int i = 2; i <= H; i++)
        S[i] = S[i-1] + S[i-2] + 1;
  
    return S[H];
}

int CountNode(AvlTree T)
{
	if (T == NULL)
		return 0;
	return 1 + CountNode(T->Left) + CountNode(T->Right);
}

/*
 * The idea of inorder traversal is adopted, 
 * so that the value of the left subtree, root node 
 * and the right subtree increases sequentially
*/
static AvlTree GenTree(int H, int *LastNodeValue)
{
	AvlTree T;
	
	if (H >= 0)
	{
		T = malloc(sizeof(struct AvlNode));
		if (T == NULL)
		{
	    	fprintf(stderr, "out of space");
			return NULL;
		}
		T->Left = GenTree(H - 1, LastNodeValue);
		T->element = (*LastNodeValue)++;
		T->Right = GenTree(H - 2, LastNodeValue);
		//update height
		T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	}
	else
		return NULL;

	return T;
}

AvlTree MinAvlTree(int H)
{
	int LastNodeValue = 0;
	return GenTree(H, &LastNodeValue);
}

static AvlTree GenTree2(int H, int *LastNodeValue)
{
	AvlTree T;
	
	if (H >= 0)
	{
		T = malloc(sizeof(struct AvlNode));
		if (T == NULL)
		{
	    	fprintf(stderr, "out of space");
			return NULL;
		}
		T->Left = GenTree2(H - 1, LastNodeValue);
		T->element = (*LastNodeValue)++;
		T->Right = GenTree2(H - 1, LastNodeValue);
		//update height
		T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	}
	else
		return NULL;

	return T;
}

AvlTree FullAvlTree(int H)
{
	int LastNodeValue = 1;
	return GenTree2(H, &LastNodeValue);
}

int CheckBalansability(AvlTree T, int*balance)
{
	if (T == NULL)
		return 1;

	int diff = abs(Height(T->Left) - Height(T->Right));
	if (diff > *balance) *balance = diff; //max height difference

	return (diff <= 1) 
	    && CheckBalansability(T->Left, balance)
	    && CheckBalansability(T->Right, balance);
}