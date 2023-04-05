#ifndef _STACK_H
#define _STACK_H

struct StackRecord;
typedef struct StackRecord* Stack;


int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);

void Push(int X, Stack S);
int Pop(Stack S);
int Top(Stack S);

void DisposeStack(Stack S);

#endif
