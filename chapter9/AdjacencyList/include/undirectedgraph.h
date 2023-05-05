#ifndef UNDIRECTGRAPH_H
#define UNDIRECTGRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

/*based on adjacency list*/

typedef char VertexType;
typedef int EdgeType;

#define MAXVEX 10

struct VertexNode; // ������ڵ�
struct EdgeNode; // �߱��ڵ�


typedef struct VertexNode* AdjList;
struct LGraph;
typedef struct LGraph* LGraph;


LGraph Intialize(void);
void CreateLGraph(LGraph G);
void CreateLGraphFromTxt(LGraph G, char* filename);

void DFSTraverse(LGraph G);
void DFS(LGraph G, int V);
void BFSTraverse(LGraph G);
void BFS(LGraph G, int V);

#endif