#ifndef UNWEIGHTED_H
#define UNWEIGHTED_H

#include "AdjacencyList/include/undirectedgraph.h"

#define NotAVertex (-1)
#define INFINITY 65535

typedef int Vertex; // 图顶点序号
typedef int DistType; // 到源点距离

struct TableEntry;
typedef struct TableEntry* Table;

Table CreateTable(Vertex Start, LGraph G);

void UnweightedShortestPath(LGraph G, Table T);

#endif