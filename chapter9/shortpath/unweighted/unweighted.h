#ifndef UNWEIGHTED_H
#define UNWEIGHTED_H

#include <stdio.h>
#include<string.h>
#include "/root/DataStructures/chapter9/AdjacencyList/include/undirectedgraph.h"

#define NotAVertex (-1)
#define INFINITY 65535

typedef int Vertex; // 图顶点序号
typedef int DistType; // 到源点距离

/*链表定义*/
typedef struct Node* PtrToNode;
struct Node
{
    Vertex V;
    PtrToNode Next;
};
typedef PtrToNode List;
typedef PtrToNode Position;

/*定义算法所用表*/
struct TableEntry
{
    List Header; // 邻接表
    int Known; // 最短路径是否已知
    DistType Dist;
    Vertex Path;
};
typedef struct TableEntry* Table;

void ReadGraph(LGraph G, Table T);
void InitTable(Vertex Start, LGraph G, Table T);

// 简单双重循环
void UnweightedShortestPath_1(Table T, int size);
// 队列实现
void UnweightedShortestPath_2(Table T, int size);

void PrintPath(Vertex V, Table T);

#endif