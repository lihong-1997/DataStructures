#include "stack.h"
#include <stdio.h>

int main()
{
	Stack S;
	// S = CreateStack(4);
	S = CreateStack(6);
	int is_empty, is_full;
	is_empty = IsEmpty(S);
	is_full = IsFull(S);
	printf("is empty?:%d\nis full?:%d\n", is_empty, is_full);

	Push(8, S);
	Push(7, S);
	Push(6, S);
	Push(5, S);
	Push(4, S);
	Push(3, S);
	is_empty = IsEmpty(S);
	is_full = IsFull(S);
	printf("is empty?:%d\nis full?:%d\n", is_empty, is_full);

	int pop_value = Pop(S);
	printf("top value:%d\n", pop_value);
	pop_value = Pop(S);
	printf("top value:%d\n", pop_value);

	DisposeStack(S);

}