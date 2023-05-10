#include "unweighted.h"

struct TableEntry
{
    int Known; // 最短路径是否已知
    DistType Dist;
    Vertex Path;
};

Table CreateTable(Vertex Start, LGraph G)
{
    int i, numVertex;
    numVertex = NumVertex(G);
    Table T;
    T = malloc(sizeof(struct TableEntry) * numVertex);
    for (i = 0; i< numVertex; i++) {
        T[i].Known = 0;
        T[i].Dist = INFINITY;
        T[i].Path = NotAVertex;
    }
    T[Start].Dist = 0;
    return T;
}

void UnweightedShortestPath(LGraph G, Table T)
{
    int CurrDist, numVertex;
    Vertex V, W;
    AdjList list;
    int n;
    numVertex = NumVertex(G);
    list = GetAdjList(G);

    for (CurrDist = 0; CurrDist < numVertex; CurrDist++) {
        for (n = 0; n < numVertex; n++) {
            
        }   
    }
}