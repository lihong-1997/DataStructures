#ifndef GRAPH_H
#define GRAPH_H
#include <stdio.h>

#define MaxVertexNum 100
#define INFINITY 65535

typedef int Vertex; //从0开始的顶点下标
typedef int WeightType; //边权值

typedef struct ENode* PtrToENode;
struct ENode
{
    Vertex V1, V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct GNode* PtrToGNode;
struct GNode
{
    int Nv; //顶点数
    int Ne; //边数
    WeightType Matrix[MaxVertexNum][MaxVertexNum]; //邻接矩阵
};
typedef PtrToGNode MGraph;


MGraph CreateGraph(int VertexNum); //创建只有顶点的图
void InsertEdge(MGraph G, Edge E); //插入边
MGraph BuildGraph(); //读入图

void Floyd(MGraph G, WeightType D[][MaxVertexNum]);

WeightType FindMaxDist(WeightType D[][MaxVertexNum], Vertex V, int Nv);

void FindAnimal(MGraph G);



#endif