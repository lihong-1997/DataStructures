#include "splaytree.h"
#include <stdio.h>
#include <limits.h>
//gcc 25splaytreefind.c src/splaytree.c src/queuesplay.c -Iinclude -o exe/25main

int main()
{
    SplayTree sT;
    sT = MakeEmpty(NULL);

    for (int i =1; i <= 1024;i++)
       sT = Insert(i, sT); 
    
    int Dn = 0, minDn = INT_MAX, index = 0;
    Dn = InternalPathLen(sT);
    printf("internal path len:%d\n", Dn);


    for (int i = 1; i <= 1024; i++)
    {
        sT = Find(i, sT);
        Dn = InternalPathLen(sT);
        if (Dn < minDn)
        {
            index = i;
            minDn = Dn;
        }
        if(i<=6 || i>= 1019)
            printf("after find %d internal path len:%d\n", i, Dn);
    }

    printf("after find %d,the minimun internal path len=%d\n", index, minDn);

    return 0;
}