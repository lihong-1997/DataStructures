#include "searchtree.h"
#include <stdio.h>

//gcc 41-42SimilarOrIso.c src/searchtree.c src/queue.c -Iinclude -o exe/main41

int main()
{
    SearchTree T1, T2;
    T1 = MakeEmpty(NULL);
    T2 = MakeEmpty(NULL);

    int a1[] = {7,6,2,13,5,9,4,10,8};
    const int len = sizeof(a1)/sizeof(*a1);
    int a2[len];
    for (int i = 0;i < len;i++)
        a2[i] = a1[i] + 2;
    
    for (int i = 0; i < len; i++)
    {
        T1 = Insert(a1[i], T1);
        T2 = Insert(a2[i], T2);
    }

    int isSim = isSimilar(T1, T2);
    int isSam = isSame(T1, T2);
    printf("similar %d\nsame %d\n", isSim, isSam);


    return 0;
}