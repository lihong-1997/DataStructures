#ifndef LEFTHEAP_H
#define LEFTHEAP_H
#include <stdio.h>
#include <stdlib.h>

#define Error( str ) FatalError( str )
#define FatalError( str ) fprintf(stderr, "%s\n", str), exit(1)

#define ElementType int

struct TreeNode;
typedef struct TreeNode* PriorityQueue;

PriorityQueue Initialize(void);
ElementType FindMin(PriorityQueue H);
PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2);

#define Insert(X, H) (H = Insert1((X), H))
PriorityQueue Insert1(ElementType X, PriorityQueue H);
PriorityQueue DeleteMin1(PriorityQueue H);

int IsEmpty(PriorityQueue H);


#endif