#include "binomialheap.h"

int main()
{
    int MaxSize = 12000;

    BinQueue H;
    H = Initialize();

    int i, j;
    ElementType item;

    for ( i = 0, j = MaxSize / 2; i < MaxSize; i++, j = (j + 71) % MaxSize)
    {
        Insert(j, H);
    }
    printf("insert done\n");

    j = 0;
    while (!IsEmpty(H))
    {
        if ( DeleteMin(H) != j++)
            printf("Error in DeleteMin, %d\n", j);
    }
    if (j != MaxSize)
        printf("error in counting");
    
    printf("deletemin Done...\n");

    return 0;
}