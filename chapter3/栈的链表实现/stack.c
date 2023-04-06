#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int Element;
	PtrToNode Next;
};

int IsEmpty(Stack S)
{
	return S->Next == NULL;
}

Stack CreateStack(void)
{
	Stack S;
	S = malloc(sizeof(struct Node));
	if (S == NULL)
		fprintf(stderr, "out of space!");

	S->Next = NULL;
	S->Element = INT_MIN;
	return S;
}

void DisposeStack(Stack S)
{
	if(S == NULL)
		fprintf(stderr, "have disposed");
	else
	{
		while (!IsEmpty(S)) Pop(S);
		free(S);
	}
}

void Push(int X, Stack S)
{
	PtrToNode NewNode;
	NewNode = malloc(sizeof(struct Node));
	if (NewNode == NULL)
	{
		fprintf(stderr, "out of space!");
		return;
	}
	NewNode->Element = X;
	NewNode->Next = S->Next;
	S->Next = NewNode;
}

void Pop(Stack S)
{
	PtrToNode FirstNode;
	if(IsEmpty(S))
		fprintf(stderr, "empty stack");
	else
	{
		FirstNode = S->Next;
		S->Next = FirstNode->Next;
		free(FirstNode);
	}
}

int Top(Stack S)
{
	if (IsEmpty(S))
	{
		fprintf(stderr, "empty stack");
		return 0;
	}
	return S->Next->Element;
}