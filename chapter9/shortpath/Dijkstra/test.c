#include "dijkstra.h"

int main()
{
    LGraph G;
    G = Intialize();
    char* file = "data.txt";
    CreateLGraphFromTxt(G, file);
    
    Table T;
    T = malloc(sizeof(struct TableEntry) * G->numNodes);
    Vertex start, end;
    start = 0;
    InitTable(start, G, T);
    Dijkstra(T, G->numNodes);
    for (end = start + 1; end < G->numNodes; end++) {
        printf("min dist: %d, ", T[end].Dist);
        PrintPath(end, T);
        printf("\n");
    }

    return 0;
}