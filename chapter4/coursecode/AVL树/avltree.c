#include "avltree.h"

#include <stdio.h>
#include <stdlib.h>

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

int getBalance(AvlTree T) {
	if (T == NULL)
		return -1;
	return Height(T->Left) - Height(T->Right);
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
	{
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
	}
	else if (X < T->element) //x在T的左子树中
	{
		T->Left = Insert(X, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2) //发现者T的高度为2，进行旋转
		{
			//通过值判断麻烦节点在发现者左子树的左子树中或是右子树中
			if (X < T->Left->element) //单旋LL
				T = SingleRotateWithLeft(T);
			else
				T = DoubleRotateWithLeft(T); //双旋LR
		}
	}
	else if (X > T->element) //x在T的右子树中
	{
		T->Right = Insert(X, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2)
		{
			//通过值判断麻烦节点在发现者右子树的左子树中或是右子树中
			if (X > T->Right->element) //单旋RR
				T = SingleRotateWithRight(T);
			else
				T = DoubleRotateWithRight(T); //双旋RL
		}
	}

	//更新树高度
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;

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

	if (X < T->element) //x在T的左子树中
	{
		T->Left = Delete(X, T->Left); //进行递归删除，递归中完成节点高度重新测算
		//更新树高度
		T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
		if (Height(T->Right) - Height(T->Left) == 2) //发现者T的高度为2，进行旋转
		{
			if (Height(T->Right->Right) > Height(T->Right->Left)) //判断单旋双旋的条件
				T = SingleRotateWithRight(T); //右单旋RR
			else
				T = DoubleRotateWithRight(T); //右双旋RL
		}
	}
		
	else if (X > T->element) //x在T的右子树中
	{
		T->Right = Delete(X, T->Right);
		//更新树高度
		T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
		if (Height(T->Left) - Height(T->Right) == 2) //发现者T的高度为2，进行旋转
		{
			//tmp = T->Left;
			if (Height(T->Left->Left) > Height(T->Left->Right))
				T = SingleRotateWithLeft(T); //左单旋LL
			else
				T = DoubleRotateWithLeft(T); //左双旋LR
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
static Position rightRotate(Position y) {
	Position x = y->Left;
	Position T2 = x->Right;

	x->Right = y;
	y->Left = T2;

	y->Height = Max(Height(y->Left), Height(y->Right)) + 1;
	x->Height = Max(Height(x->Left), Height(x->Right)) + 1;

	return x;
}

static Position leftRotate(Position x) {
	Position y = x->Right;
	Position T2 = y->Left;

	y->Left = x;
	x->Right = T2;

	x->Height = Max(Height(x->Left), Height(x->Right)) + 1;
	y->Height = Max(Height(y->Left), Height(y->Right)) + 1;

	return y;
}

AvlTree deleteNode(AvlTree root, ElementType X)
{
	if (root == NULL)
		return root;

	if (X < root->element)
		root->Left = deleteNode(root->Left, X);

	else if (X > root->element)
		root->Right = deleteNode(root->Right, X);

	else {
		if ((root->Left == NULL) || (root->Right == NULL)) {
			Position temp = root->Left ? root->Left : root->Right;

			if (temp == NULL) {
				temp = root;
				root = NULL;
			}
			else
				*root = *temp;
			free(temp);
		}
		else {
			Position temp = FindMin(root->Right);
			root->element = temp->element;
			root->Right = deleteNode(root->Right, temp->element);
		}
	}

	if (root == NULL)
		return root;

	root->Height = 1 + max(Height(root->Left),
		Height(root->Right));

	int balance = getBalance(root);

	if (balance > 1 && getBalance(root->Left) >= 0)
		return rightRotate(root);

	if (balance > 1 && getBalance(root->Left) < 0) {
		root->Left = leftRotate(root->Left);
		return rightRotate(root);
	}

	if (balance < -1 && getBalance(root->Right) <= 0)
		return leftRotate(root);

	if (balance < -1 && getBalance(root->Right) > 0) {
		root->Right = rightRotate(root->Right);
		return leftRotate(root);
	}

	return root;
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