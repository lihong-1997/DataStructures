#include "include/undirectedgraph.h"

int main()
{
    LGraph G;
    G = Intialize();

    CreateLGraph(G);
    DFSTraverse(G);
    BFSTraverse(G);
    return 0;
}