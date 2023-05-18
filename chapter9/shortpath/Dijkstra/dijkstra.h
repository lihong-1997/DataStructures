#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include <stdio.h>
#include "/root/DataStructures/chapter9/AdjacencyList/include/undirectedgraph.h"

#define NotAVertex (-1) // 源节点
#define INFINITY 65535

typedef int Vertex; // 顶点类型
typedef int DistType; // 权值类型

/*链表定义*/
typedef struct Node* PtrToNode;
struct Node
{
    Vertex V;
    DistType Weight;
    PtrToNode Next;
};
typedef PtrToNode List;
typedef PtrToNode Position;

/*定义算法所用表*/
struct TableEntry
{
    List Header; // 邻接表
    int Known; // 标记是否已知最短路径
    DistType Dist; // 到源点的距离
    Vertex Path; // 路径
};
typedef struct TableEntry* Table;

void ReadGraph(LGraph G, Table T);
void InitTable(Vertex Start, LGraph G, Table T);

// 图没有负值边
void Dijkstra(Table T, int size);
// 图有负值边
void WeightedNegative(Table T, int size);
void PrintPath(Vertex V, Table T);


#endif