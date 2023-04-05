#include "include/stack.h"
#include "include/avltree.h"
#include <stdio.h>

//gcc 19IterInsert.c src/stack.c src/avltree.c -Iinclude -o exe/main19

int main(int argc, char* argv){

    int a[11] = {2,10,3,8,5,6,11,4,9,1,12};
    AvlTree T;
    T = MakeEmpty(NULL);
    for (int i = 0; i < 11; i++)
    {
        T = IterInsert(a[i], T);
    }
    Delete(5, T);
    PreOrderTraversal(T);
    Delete(4, T);
    PreOrderTraversal(T);

}