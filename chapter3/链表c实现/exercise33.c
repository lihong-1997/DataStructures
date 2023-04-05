#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"
#include <stdio.h>

int main4()
{
    int pArray[4] = { 1,3,4,6 };
    int lArray[7] = { 1,2,3,4,5,6,7 };
    List L = LinkedListCreateFromArray(lArray, 7);  //1 2 3 4 5 6 7
    printf("L:");
    PrintList(L);

    Position preNode = First(L);
    LinkedListSwap(preNode);
    printf("\nL after swap:");
    PrintList(L);
    return 0;
}