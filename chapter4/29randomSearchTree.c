#include "searchtree.h"
#include <stdlib.h>
#include <stdio.h>

//gcc 29randomSearchTree.c src/queue.c src/tree.c -Iinclude -o ./exe/29main
int main()
{
    SearchTree T;
    T = MakeEmpty(NULL);

    T = RandomSearchTree(10);

    PreOrderTraversal(T);
    printf("\n");

    int IsST = CheckSearchTree(T);
    int IsST2 = rCheckSearchTree(T);

    printf("%d\n%d\n", IsST, IsST2);

    return 0;
}