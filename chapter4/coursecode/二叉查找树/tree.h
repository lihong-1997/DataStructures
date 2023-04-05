#ifndef TREE_H
#define TREE_H

#define ElementType int

struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

SearchTree MakeEmpty(SearchTree T);
Position Find(ElementType X, SearchTree T);
Position IterFind(ElementType X, SearchTree T);
Position FindMin(SearchTree T);
Position FindMax(SearchTree T);

Position Insert(ElementType X, SearchTree T);
Position Delete(ElementType X, SearchTree T);

ElementType Retrieve(Position P);

void PreOrderTraversal(SearchTree T);

#endif

