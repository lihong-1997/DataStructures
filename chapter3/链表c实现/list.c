#define _CRT_SECURE_NO_WARNINGS 1

#include"list.h"
#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int Element;
    Position Next;
};

int IsEmpty(List L)
{
    return L->Next == NULL;
}

int IsLast(Position p, List L)
{
    return p->Next == NULL;
}

List MakeEmpty()
{
	List TmpList = malloc(sizeof(struct Node));
    if (TmpList == NULL)
    {
    	printf("Out of Space!");
        return NULL;
    }

    TmpList->Element = INT_MIN;
    TmpList->Next = NULL;
    return TmpList;
}

List LinkedListCreate()
{
    List list = MakeEmpty();
    Position EndCell = list;

    int x;
    while (scanf("%d", &x) == 1)
    {
        Position Cell;
        Cell = malloc(sizeof(struct Node));
        Cell->Element = x;
    	EndCell->Next = Cell;
        EndCell = Cell;
    }
    EndCell->Next = NULL;
    return list;
}

List LinkedListCreateFromArray(int* array, int len)
{
    List list = MakeEmpty();
    Position EndCell = list;

    for (int i = 0;i < len;i++)
    {
        Position Cell;
        Cell = malloc(sizeof(struct Node));
        Cell->Element = array[i];
        EndCell->Next = Cell;
        EndCell = Cell;
    }
    EndCell->Next = NULL;
    return list;
}

Position Find(int X, List L)
{

	Position TmpCell = L->Next;
    while (TmpCell != NULL && TmpCell->Element != X)
        TmpCell = TmpCell->Next;

    return TmpCell;
}

Position FindKth(int K, List L)
{
    int i = 0;
    Position TmpCell;
    TmpCell = L->Next;
    while (TmpCell != NULL && i < K)
    {
        TmpCell = TmpCell->Next;
        i++;
    }
    return TmpCell;
}

Position FindPrevious(int X, List L)
{
    Position TmpCell;
    TmpCell = L;
    while (TmpCell->Next != NULL && TmpCell->Next->Element != X)
        TmpCell = TmpCell->Next;

    return TmpCell;
}

void Insert(int X, List L, Position p)
{
    Position TmpCell;
    TmpCell = malloc(sizeof(struct Node));
    if (TmpCell == NULL)
    {
	    printf("Out of Space!");
        return;
    }

    TmpCell->Element = X;
    TmpCell->Next = p->Next;
    p->Next = TmpCell;
}

void Delete(int X, List L)
{
    Position PreCell, TmpCell;
    PreCell = FindPrevious(X, L);
    if (!IsLast(PreCell, L))
    {
        TmpCell = PreCell->Next;
        PreCell->Next = TmpCell->Next;
        free(TmpCell);
    }
}

void DeleteList(List L)
{
    Position TmpCell, FirstCell;
    FirstCell = L->Next;
    L->Next = NULL;
    while (FirstCell != NULL)
    {
        TmpCell = FirstCell->Next;
        free(FirstCell);
        FirstCell = TmpCell;
    }
}

int Length(List L)
{
    int i = 0;
    Position FirstCell = L->Next;
    while (FirstCell != NULL)
    {
        FirstCell = FirstCell->Next;
        ++i;
    }
    return i;
}

void PrintList(List L)
{
	Position TmpCell = L->Next;
    while (TmpCell)
    {
        printf("%d ", TmpCell->Element);
        TmpCell = TmpCell->Next;
    }
}

void PrintList_recursion(List L)
{
    if (L)
    {
        printf("%d ", L->Element);
        PrintList_recursion(L->Next);
    }
}

int Retrieve(Position p)
{
    return p->Element;
}

int getIndex(Position p, List L)
{
    if (p == NULL)
        return -1;

    int i = 0;
    Position TmpCell = L->Next;
    while (TmpCell != p)
    {
        TmpCell = TmpCell->Next;
        i++;
    }
    return i;
}

Position First(List L)
{
    return L->Next;
}

Position Advance(Position p)
{
    return p->Next;
}

void LinkedListSwap(Position previousNode)
{
    Position pFirst, pSecond;
    pFirst = previousNode->Next;
    pSecond = pFirst->Next;
    previousNode->Next = pSecond;
    pFirst->Next = pSecond->Next;
    pSecond->Next = pFirst;
}