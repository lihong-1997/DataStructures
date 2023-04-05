/*
 * down-top splay tree
*/
#ifndef SPLAYTREE_H
#define SPLAYTREE_H

#define ElementType int

struct SplayNode;
typedef struct SplayNode* SplayTree;
typedef struct SplayNode* Position;

SplayTree MakeEmpty(SplayTree T);

Position Find(ElementType X, SplayTree T);
//Position FindMin(SplayTree T);
//Position FindMax(SplayTree T);
Position Insert(ElementType X, SplayTree T);
Position Delete(ElementType X, SplayTree T);

ElementType Retrieve(Position P);
void PreOrderTraversal(SplayTree T);
int InternalPathLen(SplayTree T);

#endif