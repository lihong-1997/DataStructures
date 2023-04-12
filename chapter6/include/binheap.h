#ifndef BINHEAP_H
#define BINHEAP_

#include <stdio.h>
#include <stdlib.h>

#define INT_MAX ((int)(~0U>>1))
#define INT_MIN     (-INT_MAX - 1)

#define Error( str ) FatalError( str )
#define FatalError( str ) fprintf(stderr, "%s\n", str), exit(1)

#define ElementType int
#define MinPQSize (1)
// sentinel
#define MinData INT_MIN

struct HeapStruct;
typedef struct HeapStruct* PriorityQueue;

PriorityQueue Initialize(int MaxElements);
void BuildHeap(PriorityQueue H, ElementType A[], int len);

void Destroy(PriorityQueue H);
void MakeEmpty(PriorityQueue H);

void Insert(ElementType X, PriorityQueue H);
ElementType FinMin(PriorityQueue H);
void FindLess(ElementType X, PriorityQueue H);
int Find(ElementType X, PriorityQueue H);
ElementType DeleteMin(PriorityQueue H);

void DecreaseKey(int P, unsigned int delta, PriorityQueue H);
void IncreaseKey(int P, unsigned int delta, PriorityQueue H);
void Delete(int P, PriorityQueue H);

ElementType Retrieve(int index, PriorityQueue H);

int IsEmpty(PriorityQueue H);
int IsFull(PriorityQueue H);

int Size(PriorityQueue H);


#endif