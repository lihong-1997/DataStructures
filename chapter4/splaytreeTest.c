#include "splaytree.h"
#include <stdio.h>

int main()
{
    SplayTree sT;
    sT = MakeEmpty(NULL);

    sT = Insert(3, sT);
    sT = Insert(4, sT);
    sT = Insert(2, sT);
    sT = Insert(6, sT);
    sT = Insert(1, sT);
    sT = Insert(8, sT);
    sT = Insert(12, sT);
    sT = Insert(20, sT);
    sT = Insert(10, sT);
    int Dn = 0;
    //LevelOrderTraversal(sT, &Dn);
    PreOrderTraversal(sT);
    printf("\n");
    sT = Find(6, sT);
    PreOrderTraversal(sT);

    return 0;
}