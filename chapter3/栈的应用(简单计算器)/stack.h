#ifndef _STACK_H
#define _STACK_H

struct StackRecord;
typedef struct StackRecord* Stack;


int IsEmpty(Stack S);
int IsFull(Stack S);
Stack CreateStack(int MaxElements);

void Push(char X, Stack S);
void Pop(Stack S);
char Top(Stack S);

void DisposeStack(Stack S);

#endif
