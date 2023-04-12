#ifndef BINOMIALHEAP_H
#define BINOMIALHEAP_H

#include <stdio.h>
#include <stdlib.h>

#define INT_MAX ((int)(~0U>>1))
#define INT_MIN (-INT_MAX - 1)

#define Error( str ) FatalError( str )
#define FatalError( str ) fprintf(stderr, "%s\n", str), exit(1)

#define ElementType int

#define MaxTrees (14) /*���Դ� 1+2+4+...+2^13 = 2^14-1 = 16383���ڵ�*/
#define Capacity (16383)

struct BinNode;
typedef struct BinNode* BinTree; //ָ��ÿ�����ĸ��ڵ�ָ��
typedef struct BinNode* Position; //ָ��ÿ�����ڵ��ָ��

struct Collection;
typedef struct Collection* BinQueue;

BinQueue Initialize(void);
void Destroy(BinQueue H);
BinQueue MakeEmpty(BinQueue H);

BinTree CombineTrees(BinTree T1, BinTree T2);
BinQueue Merge(BinQueue H1, BinQueue H2);
ElementType FindMin(BinQueue H);
ElementType DeleteMin(BinQueue H);
BinQueue Insert(ElementType X, BinQueue H);

int IsFull(BinQueue H);
int IsEmpty(BinQueue H);

#endif