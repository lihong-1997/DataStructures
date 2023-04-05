#ifndef SEARCHTREE_H
#define SEARCHTREE_H

#define ElementType int

struct TreeNode;
typedef struct TreeNode* Position;
typedef struct TreeNode* SearchTree;

//clear the tree of init null tree
SearchTree MakeEmpty(SearchTree T);
//malloc node
Position CreateNode(ElementType X);
//build a random tree,range from 1 to N
SearchTree RandomSearchTree(int N);
// recursion find element
Position Find(ElementType X, SearchTree T);
// iteration find element
Position IterFind(ElementType X, SearchTree T);
// recursion find min
Position FindMin(SearchTree T);
// iteration find max
Position FindMax(SearchTree T);
// recursion insert
Position Insert(ElementType X, SearchTree T);
// iteration insert
Position IterInsert(ElementType X, SearchTree T);
//recursion delete element, min in the Tr
Position Delete(ElementType X, SearchTree T);
//recursion delete element, max in the Tl
Position DeleteTl(ElementType X, SearchTree T);
Position DeleteRandom(ElementType X, SearchTree T, int seed);
Position DeleteAlter(ElementType X, SearchTree T, int flag);
//get the height of the whole tree
int Height(SearchTree T);
//check the tree is balanced, and get the max difference
int GetBalansability(SearchTree T, int*balance);
//De-reference get the element
ElementType Retrieve(Position P);
//traverse the tree
void PreOrderTraversal(SearchTree T);
void LevelOrderTraversal(SearchTree T, int* Dn);
//get the count of node
int CountNode(SearchTree T);
//print node with two child
int PreOrderFullNode(SearchTree T);
//get the count of full node
int CountFullNode(SearchTree T);
//get the count of leaf
int CountLeaf(SearchTree T);
//check the tree is search tree
int CheckSearchTree(SearchTree T);
//recursion check the tree is search tree
int rCheckSearchTree(SearchTree T);
//find the node whose value between k1 and k2
void PrintRange(SearchTree T, int k1, int k2);

int isSimilar(SearchTree T1, SearchTree T2);
int isSame(SearchTree T1, SearchTree T2);
//int isIsomorphic(SearchTree T1, SearchTree T2);

//special for SeqToSearchTree.c
int check(SearchTree T, int value);

#endif
