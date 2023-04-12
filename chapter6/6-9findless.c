#include "binheap.h"
#define MaxElements (15)

int main()
{
    PriorityQueue H;
    H = Initialize(MaxElements);
    int arr[] = { 13,21,16,24,31,19,68,65,26,32 };
    int len = sizeof(arr)/sizeof(*arr);
    BuildHeap(H, arr, len);

    FindLess(30, H);
    printf("\n");

    int p = Find(19, H);
    printf("find %d\n", Retrieve(p, H));
    
    printf("\n");
    return 0;
}

