#ifndef _STACK_H
#define _STACK_H

#include "avltree.h"
typedef struct AvlNode* elemtype;

struct Node;
typedef struct Node* PtrToNode;
typedef PtrToNode Stack;

int IsEmpty(Stack S);
Stack CreateStack(void);

void Push(elemtype X, Stack S);
void Pop(Stack S);
elemtype Top(Stack S);

void DisposeStack(Stack S);

#endif