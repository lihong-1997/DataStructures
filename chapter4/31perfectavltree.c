#include "avltree.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
//gcc 31perfectavltree.c src/avltree.c src/stack.c -Iinclude -lm -o ./exe/31main
int main()
{
    int H = 2;
    AvlTree T;
    T = FullAvlTree(H);

    PreOrderTraversal(T);

    int nodecount = CountNode(T);

    int num = (int)pow(2, H + 1) - 1;

    printf("node match?:%d\n", nodecount == num);

    int diff = 0;
    int IsBalance = CheckBalansability(T, &diff);
    printf("is balanced? %d\n", IsBalance);

    return 0;
}