#ifndef UNDIRECTGRAPH_H
#define UNDIRECTGRAPH_H

#include <stdio.h>
#include <stdlib.h>

/*based on adjacency matrix*/

typedef char VertexType;
typedef int EdgeType;

#define MAXVEX 100

struct MGraph;
typedef struct MGraph* Graph;


Graph Intialize(void);
void CreateGraph(Graph G);
void CreateGraphFromTxt(Graph G, char* filename);

void DFSTraverse(Graph G);
void DFS(Graph G, int V);

#endif