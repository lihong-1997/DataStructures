#include "searchtree.h"
#include <stdio.h>

int main()
{
    SearchTree T;
    T = MakeEmpty(NULL);

    int arr[] = {1,6,3,8,5,9,2,11};
    int len = sizeof(arr)/sizeof(*arr);
    for (int i = 0; i < len;i++)
    {
        T = Insert(arr[i], T);
    }

    int num = CountNode(T);
    int full = CountFullNode(T);
    int leaf = CountLeaf(T);
    
    printf("node num:%d\nfull node:%d\nleaf node:%d\n", num, full, leaf);

}