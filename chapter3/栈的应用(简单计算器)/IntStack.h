#ifndef _INTSTACK_H
#define _INTSTACK_H

struct StackRecord;
typedef struct StackRecord* Stack;


int IsEmptyInt(Stack S);
int IsFullInt(Stack S);
Stack CreateIntStack(int MaxElements);

void PushInt(int X, Stack S);
void PopInt(Stack S);
int TopInt(Stack S);

void DisposeIntStack(Stack S);

#endif
