#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct Node
{
	char Element;
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
	{
		printf("out of space!");
		return NULL;
	}
	S->Next = NULL;
	S->Element = INT_MIN;
	return S;
}

void DisposeStack(Stack S)
{
	if (S == NULL)
		printf("have disposed");
	else
	{
		while (!IsEmpty(S)) Pop(S);
		free(S);
	}
}

void Push(char X, Stack S)
{
	PtrToNode NewNode;
	NewNode = malloc(sizeof(struct Node));
	if (NewNode == NULL)
	{
		printf("out of space!");
		return;
	}
	NewNode->Element = X;
	NewNode->Next = S->Next;
	S->Next = NewNode;
}

char Pop(Stack S)
{
	if (IsEmpty(S))
	{
		printf("empty stack");
		return;
	}
	PtrToNode FirstNode;
	FirstNode = S->Next;
	char value = FirstNode->Element;
	S->Next = FirstNode->Next;
	free(FirstNode);
	return value;
}

int Top(Stack S)
{
	if (IsEmpty(S))
	{
		printf("empty stack");
		return 0;
	}
	return S->Next->Element;
}