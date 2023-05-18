#include "unweighted.h"

void ReadGraph(LGraph G, Table T)
{
    int NumVertex, i;
    NumVertex = G->numNodes;
    for (i = 0; i < NumVertex; i++)
        // 获取第一个邻接节点的指针
        T[i].Header = (struct Node*)G->adjlist[i].firstedge;
}

void InitTable(Vertex Start, LGraph G, Table T)
{
    int i;
    ReadGraph(G, T);
    for (i = 0; i < G->numNodes; i++) {
        T[i].Known = 0;
        T[i].Dist = INFINITY;
        T[i].Path = NotAVertex;
        //memcpy(T[i].Name, (char*)G->adjlist[i].data, strlen((char*)G->adjlist[i].data));
    }
    T[Start].Dist = 0;
}


// Table CreateTable(Vertex Start, LGraph G)
// {
//     int i, numVertex;
//     numVertex = NumVertex(G);
//     Table T;
//     T = malloc(sizeof(struct TableEntry) * numVertex);
//     for (i = 0; i< numVertex; i++) {
//         T[i].Known = 0;
//         T[i].Dist = INFINITY;
//         T[i].Path = NotAVertex;
//     }
//     T[Start].Dist = 0;
//     return T;
// }

void UnweightedShortestPath_1(Table T, int size)
{
    int CurrDist, numVertex;
    Vertex V, W;
    Position pW;

    numVertex = size;

    for (CurrDist = 0; CurrDist < numVertex; CurrDist++) {
        for (V = 0; V < numVertex; V++) { // 遍历每个顶点
            if (!T[V].Known && T[V].Dist == CurrDist) {
                T[V].Known = 1;
                pW = (Position)T[V].Header; // V的第一个邻接点指针
                while (pW != NULL) {
                    W = pW->V;
                    if (T[W].Dist == INFINITY) {
                        T[W].Dist = T[V].Dist + 1;
                        T[W].Path = V;
                    }
                    pW  = pW->Next; // V的下一个邻接节点指针
                }
            }
        }
    }
}

void UnweightedShortestPath_2(Table T, int size)
{
    Queue Q;
    Vertex V, W, S;
    Position pW;

    Q = CreateQueue(size);

    // 找出源节点
    for (S = 0; S < size; S++)
        if (T[S].Dist == 0) break;
    
    Enqueue(S, Q);

    while (!IsEmpty(Q)) {
        V = Dequeue(Q);
        pW = (Position)T[V].Header; // V的第一个邻接点指针
        while (pW != NULL) {
            W = pW->V;
            if (T[W].Dist == INFINITY) {
                T[W].Dist = T[V].Dist + 1;
                T[W].Path = V;
                Enqueue(W, Q);
            }
            pW  = pW->Next; // V的下一个邻接节点指针
        }
    }
    DisposeQueue(Q);
}

void PrintPath(Vertex V, Table T)
{
    if (T[V].Path != NotAVertex) {
        PrintPath(T[V].Path, T);
        printf(" -> ");
    }
    printf("%d", V);
}