#ifndef HASHSEP_H
#define HASHSEP_H
#include <stdio.h>
#include <stdlib.h>

#define Error( str ) FatalError( str )
#define FatalError( str ) fprintf(stderr, "%s\n", str), exit(1)

#define ElementType int
#define Index unsigned int ;
#define MinTableSize 5

struct ListNode;
typedef struct ListNode* Position;
struct HashTbl;
typedef struct HashTbl* HashTable;

int NextPrime(int TableSize);

HashTable InitializeTable(int TableSize);
void DestroyTbale(HashTable H);

Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);

ElementType Retrieve(Position P);

#endif