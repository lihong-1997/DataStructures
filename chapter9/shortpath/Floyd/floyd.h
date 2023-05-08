#ifndef FLOYD_H
#define FLOYD_H

#include <stdio.h>
#include <string.h>

#define MAXVEX 20
#define INFINITY 65535

struct GNode;
typedef struct GNode* PtrToGNode;
typedef PtrToGNode MGraph;

typedef int Patharc[MAXVEX][MAXVEX];
typedef int ShortPathTable[MAXVEX][MAXVEX];

MGraph Intialize(void);

void CreateGraphFromTxt(MGraph G, char txt[]);

void ShortestPath_Floyd(MGraph G, Patharc *P, ShortPathTable *D);

void PrintShortestPath(MGraph G, Patharc P, ShortPathTable D);

#endif