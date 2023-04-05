#include "searchtree.h"
#include <stdio.h>

//gcc 35levelorder.c src/queue.c src/searchtree.c -Iinclude -o exe/main35

int main(int argc, char* argv){

    int a[] = {2,10,3,8,5,6,11,4,9,1,12};
    int len = sizeof(a)/sizeof(*a);
    SearchTree T;
    T = MakeEmpty(NULL);
    for (int i = 0; i < len; i++)
    {
        T = IterInsert(a[i], T);
    }
    int Dn = 0;
    LevelOrderTraversal(T, &Dn);
    printf("Dn:%d\n", Dn);
}