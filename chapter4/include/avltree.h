#ifndef AVLTREE_H
#define AVLTREE_H

#define ElementType int

struct AvlNode;
typedef struct AvlNode* Position;
typedef struct AvlNode* AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position CreateNode(ElementType X);

Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree IterInsert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);

ElementType Retrieve(Position P);
// get the count of node
int CountNode(AvlTree T);
// traverse avltree with height of each node
void PreOrderTraversal(AvlTree T);
// The minimum number of nodes with a height of H
int MinNodeCount(int H);
// build avltree with minimum node and height of H
AvlTree MinAvlTree(int H);
// build avltree with maximum node and height of H
AvlTree FullAvlTree(int H);
// check balansability
int CheckBalansability(AvlTree T, int*balance);

#endif