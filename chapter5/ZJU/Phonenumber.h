/*
读入最多2*10^5个电话号码，统计电话号码中出现最多的狂人，
若有大于1个狂人，则输出狂人个数，以及狂人中最小的电话号码
*/

#ifndef PHONENUMBER_H
#define PHONENUMBER_H
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define Error( str ) FatalError( str )
#define FatalError( str ) fprintf(stderr, "%s\n", str), exit(1)

#define KEYLENGTH 11
#define MAXTABLESIZE 1000000

typedef char ElementType[KEYLENGTH+1];
typedef unsigned int Index;
typedef Index Position;

struct HashTbl;
typedef struct HashTbl* HashTable;

int NextPrime(int TableSize);
Index Hash(int Key, int TableSize);

HashTable InitializeTable(int TableSize);
void DestroyTable(HashTable H);
Position Find(ElementType Key, HashTable H);
void Insert(ElementType Key, HashTable H);
void PrintHashTable(HashTable H);

void ScanAndOutput(HashTable H);

#endif