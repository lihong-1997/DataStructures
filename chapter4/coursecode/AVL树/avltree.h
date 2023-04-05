#ifndef AVLTREE_H
#define AVLTREE_H
#define ElementType int

struct AvlNode;
typedef struct AvlNode* Position;
typedef struct AvlNode* AvlTree;

AvlTree MakeEmpty(AvlTree T);
Position Find(ElementType X, AvlTree T);
Position FindMin(AvlTree T);
Position FindMax(AvlTree T);
AvlTree Insert(ElementType X, AvlTree T);
AvlTree Delete(ElementType X, AvlTree T);
AvlTree deleteNode(AvlTree root, ElementType X);

ElementType Retrieve(Position P);
void PreOrderTraversal(AvlTree T);

#endif
