#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include "stack.h"
int main()
{
	Stack S;
	S = CreateStack();
	int is_empty = IsEmpty(S);
	printf("is empty? %d\n", is_empty);

	int x1 = 2, x2 = 3, x3 = 6;
	Push(x1, S);
	Push(x2, S);
	Push(x3, S);

	int top_value = Top(S);
	printf("top value: %d\n", top_value);

	Pop(S);
	top_value = Top(S);
	printf("top value: %d\n", top_value);

	DisposeStack(S);


}