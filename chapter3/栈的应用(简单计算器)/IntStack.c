#include "IntStack.h"
#include <stdio.h>
#include <stdlib.h>

#define EmptyTOS ( -1 )
#define MinStackSize ( 2 )

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	int* Array;
};

Stack CreateIntStack(int MaxElements)
{
	if (MaxElements < MinStackSize)
	{
		printf("stack size is too small");
		return NULL;
	}
	Stack S;
	S = malloc(sizeof(struct StackRecord));
	if (S == NULL)
	{
		printf("out of space");
		return NULL;
	}
	S->Array = malloc(sizeof(int) * MaxElements);
	if (S == NULL)
	{
		printf("out of space");
		return NULL;
	}
	S->Capacity = MaxElements;
	S->TopOfStack = -1;
	return S;
}

int IsEmptyInt(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}

int IsFullInt(Stack S)
{
	return S->TopOfStack == S->Capacity - 1;
}

void PushInt(int X, Stack S)
{
	if (IsFullInt(S))
		printf("Full Stack");
	else
		S->Array[++S->TopOfStack] = X;
}

void PopInt(Stack S)
{
	if (!IsEmptyInt(S))
		S->TopOfStack--;
	else
		printf("Empty Stack2");
}

int TopInt(Stack S)
{
	if (IsEmptyInt(S))
		printf("Empty Stack1");
	else
		return S->Array[S->TopOfStack];
	return -1;
}

void DisposeIntStack(Stack S)
{
	if (S != NULL)
	{
		free(S->Array);
		free(S);
	}
}