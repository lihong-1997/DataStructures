#ifndef HASHQUAD_H
#define HASHQUAD_H

#include <stdio.h>
#include <stdlib.h>

#define Error( str ) FatalError( str )
#define FatalError( str ) fprintf(stderr, "%s\n", str), exit(1)
#define MinTableSize 5
#define CriticalValue 0.5 // load factor for rehash
#define ElementType int

typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl* HashTable;

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);

Position FindLinear(ElementType Key, HashTable H);
void InsertLinear(ElementType Key, HashTable H);

Position FindSquare(ElementType Key, HashTable H);
HashTable InsertSquare(ElementType Key, HashTable H);
//rehashing to solve too large load factor to insert a new element
HashTable Rehash(HashTable H);

Position FindDoubleHash(ElementType Key, HashTable H);
void InsertDoubleHash(ElementType Key, HashTable H);

ElementType Retrieve(Position P, HashTable H);
void PrintHashTable(HashTable H);

double GetLoadFactor(HashTable H);

#endif
