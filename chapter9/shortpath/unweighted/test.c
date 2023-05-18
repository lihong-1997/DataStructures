#include "unweighted.h"

int main()
{
    LGraph G;
    G = Intialize();
    char* file = "data.txt";
    CreateLGraphFromTxt(G, file);
    
    Table T;
    T = malloc(sizeof(struct TableEntry) * G->numNodes);
    Vertex start, end;
    start = 0; // 设定源节点
    InitTable(start, G, T);

    // UnweightedShortestPath_1(T, G->numNodes);
    UnweightedShortestPath_2(T, G->numNodes);

    // 打印每个节点的最短距离及其路径
    for (end = start + 1; end < G->numNodes; end++) {
        printf("min dist: %d, ", T[end].Dist);
        PrintPath(end, T);
        printf("\n");
    }
    return 0;
}