#include "undirectedgraph.h"

int main()
{
    char* file = "data.txt";
    Graph G;
    G = Intialize();
    CreateGraphFromTxt(G, file);

    DFSTraverse(G);
    return 0;
}