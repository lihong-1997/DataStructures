#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define EmptyTOS ( -1 )
#define MinStackSize ( 2 )

struct StackRecord
{
	int Capacity;
	int TopOfStack;
	char* Array;
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
	if (S == NULL)
	{
		printf("out of space");
		return NULL;
	}
	S->Array = malloc(sizeof(char) * MaxElements);
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

void Push(char X, Stack S)
{
	if (IsFull(S))
		printf("Full Stack");
	else
		S->Array[++S->TopOfStack] = X;
}

void Pop(Stack S)
{
	if (!IsEmpty(S))
		S->TopOfStack--;
	else 
		printf("Empty Stack2");
}

char Top(Stack S)
{
	if (IsEmpty(S))
		printf("Empty Stack1");
	else
		return S->Array[S->TopOfStack];
	return '0';
}

void DisposeStack(Stack S)
{
	if (S != NULL)
	{
		free(S->Array);
		free(S);
	}
}