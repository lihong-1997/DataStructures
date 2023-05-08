#include "floyd.h"

int main()
{
    MGraph G;
    G = Intialize();
    char* txt = "data.txt";
    CreateGraphFromTxt(G, txt);
    Patharc P;
    ShortPathTable D;
    ShortestPath_Floyd(G, &P, &D);
    PrintShortestPath(G, P, D);
    return 0;
}