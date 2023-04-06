#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define EmptyTOS ( -1 )
#define MinStackSize ( 5 )

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	int* Array;
};

Stack CreateStack(int MaxElements)
{
	if (MaxElements < MinStackSize)
	{
		printf("stack size is too small");
		return NULL;
	}
	Stack S;
	S = malloc(sizeof(struct StackRecord));
	if(S == NULL)
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

int IsEmpty(Stack S)
{
	return S->TopOfStack == EmptyTOS;
}

int IsFull(Stack S)
{
	return S->TopOfStack == S->Capacity - 1;
}

void Push(int X, Stack S)
{
	if(IsFull(S))
		printf("Full Stack");
	else
		S->Array[++S->TopOfStack] = X;
}

int Pop(Stack S)
{
	if (!IsEmpty(S))
		return S->Array[S->TopOfStack--];
	printf("Empty Stack");
	return 0;
}

int Top(Stack S)
{
	if (IsEmpty(S))
		printf("Empty Stack");
	else
		return S->Array[S->TopOfStack];
	return 0;
}

void DisposeStack(Stack S)
{
	if(S != NULL)
	{
		free(S->Array);
		free(S);
	}
}