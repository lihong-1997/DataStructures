#include "avltree.h"
#include <stdio.h>
#include <stdlib.h>
//gcc 30minavltree.c src/avltree.c src/stack.c -Iinclude -o ./exe/30main

int main()
{
    int H = 4;
    AvlTree T;
    T = MinAvlTree(H);

    PreOrderTraversal(T);

    int nodecount = CountNode(T);

    int num = MinNodeCount(H);

    printf("node match?:%d\n", nodecount == num);

    int diff = 0;
    int IsBalance = CheckBalansability(T, &diff);
    printf("is balanced? %d\n", IsBalance);

    return 0;
}