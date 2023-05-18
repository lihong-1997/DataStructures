#include "/root/DataStructures/chapter9/shortpath/Dijkstra/dijkstra.h"

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
    }
    T[Start].Dist = 0;
}

static int SmallestUnknownDistV(Table T, int size)
{
    // 扫描表找最小距离
    int i;
    Vertex V;
    V = NotAVertex;
    DistType MinDist, Dist;
    MinDist = INFINITY;
    for (i = 0; i < size; i++) {
        Dist = T[i].Dist;
        if (!T[i].Known && Dist < MinDist) {
            MinDist = Dist;
            V = i;
        }
    }
    return V;
}

void Dijkstra(Table T, int size)
{
    Vertex V, W;
    for ( ; ; ) {
        V = SmallestUnknownDistV(T, size);
        if (V == NotAVertex)
            break;
        T[V].Known = 1;
        Position pW;
        pW = (Position)T[V].Header; // V的第一个邻接点指针
        while (pW != NULL) {
            W = pW->V;
            if(!T[W].Known) { // 如果该邻接节点最短距离还未知
                if (T[V].Dist + pW->Weight < T[W].Dist) {
                    T[W].Dist = T[V].Dist + pW->Weight;
                    T[W].Path = V;
                }
            }
            pW = pW->Next;
        }
    }
}

void PrintPath(Vertex V, Table T)
{
    if (T[V].Path != NotAVertex) {
        PrintPath(T[V].Path, T);
        printf(" to");
    }
    printf("%d", V);
}