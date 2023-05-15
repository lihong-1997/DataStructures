#ifndef UNDIRECTGRAPH_H
#define UNDIRECTGRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "queue.h"

/*based on adjacency list*/

typedef char VertexType;
typedef int EdgeType;

#define MAXVEX 30

struct EdgeNode
{
    int V;
    EdgeType Weight;
    struct EdgeNode* next;
};

struct VertexNode
{
    VertexType data;
    struct EdgeNode* firstedge;
};

typedef struct VertexNode* AdjList;
struct LGraph
{
    int numNodes;
    int numEdges;
    AdjList adjlist;
};
typedef struct LGraph* LGraph;


LGraph Intialize(void);
void CreateLGraph(LGraph G);
void CreateLGraphFromTxt(LGraph G, char txt[]);

void DFSTraverse(LGraph G);
void DFS(LGraph G, int V);
void BFSTraverse(LGraph G);
void BFS(LGraph G, int V);

int NumVertex(LGraph G);
AdjList GetAdjList(LGraph G);

#endif