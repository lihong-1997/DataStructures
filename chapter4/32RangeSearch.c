#include "searchtree.h"
#include <stdio.h>

int main()
{
    SearchTree T;
    T = RandomSearchTree(12);

    PrintRange(T, 2, 8);

    return 0;
}