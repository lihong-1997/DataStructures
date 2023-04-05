#define _CRT_SECURE_NO_WARNINGS 1
#include"list.h"
#include <stdio.h>

void PrintLots(List L, List P) //效率不高
{
    int index, value;
    Position KthNode;
    Position PNode = First(P);
    while (PNode)
    {
        index = Retrieve(PNode);
        KthNode = FindKth(index - 1, L);
        value = Retrieve(KthNode);
        printf("%d ", value);
        PNode = Advance(PNode);
    }
}

void PrintLotsBetter(List L, List P)
{
    int index = 1, value;
    Position PNode = First(P);
    Position LNode = First(L);
    while (LNode && PNode)
    {
        if (Retrieve(PNode) == index++) //循环的次数与P的元素对应，则输出当前L的节点
        {
            value = Retrieve(LNode);
            printf("%d ", value);
            PNode = Advance(PNode);
        }
        LNode = Advance(LNode);
    }
}

int main3()
{
    int pArray[4] = { 1,3,4,6 };
    int lArray[7] = { 1,2,3,4,5,6,7 };
    List P = LinkedListCreateFromArray(pArray, 4);  //1 3 4 6
    List L = LinkedListCreateFromArray(lArray, 7);  //1 2 3 4 5 6 7

    PrintLotsBetter(L, P);
    return 0;
}