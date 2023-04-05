#ifndef _STACK_H
#define _STACK_H

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);

void Push(char X, Stack S);
char Pop(Stack S);
int Top(Stack S);

void DisposeStack(Stack S);


#endif
