#include "binheap.h"

struct HeapStruct
{
    int Capacity;
    int Size;
    ElementType* Elements;
};

PriorityQueue Initialize(int MaxElements)
{
    if (MaxElements < MinPQSize)
        Error("Priority queue size is too samll");
    PriorityQueue H;
    H = malloc(sizeof(struct HeapStruct));
    if (H == NULL)
        FatalError("out of space");
    H->Elements = malloc(sizeof(ElementType) * (MaxElements + 1));
    if (H->Elements == NULL)
        FatalError("out of space");
    H->Size = 0;
    H->Capacity = MaxElements;
    H->Elements[0] = MinData;

    return H;
}

static void PercolateUp(int index, PriorityQueue H)
{
    ElementType temp;
    temp = H->Elements[index];
    int i;
    for ( i = index; H->Elements[i / 2] > temp; i /= 2)
        H->Elements[i] = H->Elements[i / 2];
    H->Elements[i] = temp;
}

static void PercolateDown(int index, PriorityQueue H)
{
    int Parent;
    int Child;
    ElementType temp;
    temp = H->Elements[index];

    for (Parent = index; Parent * 2 <= H->Size; Parent = Child)
    {
        Child = Parent * 2;
        if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])
            Child++;
        
        if (H->Elements[Parent] > H->Elements[Child])
            H->Elements[Parent] = H->Elements[Child];
        
        else
            break;
    }
    H->Elements[Parent] = temp;
}

void BuildHeap(PriorityQueue H, ElementType A[], int len)
{
    int i;
    for (i = 1; i <= len; i++)
    {
        if(!IsFull(H))
        {
            H->Elements[i] = A[i - 1];
            H->Size++;
        }
        else
        {
            FatalError("priority queue have elements");
            return;
        }
    }
    // 对堆实行下滤，使其满足堆序
    for (i = len / 2; i > 0; i--)
        PercolateDown(i, H);
}

void Destroy(PriorityQueue H)
{
    free(H->Elements);
    free(H);
}

void MakeEmpty(PriorityQueue H)
{
    H->Size = 0;
}

void Insert(ElementType X, PriorityQueue H)
{
    if (IsFull(H))
    {
        Error("Priority queue is full");
        return;
    }
    // int i;
    // // i初始值指向堆中最后一个元素的位置
    // for (i = ++H->Size; H->Elements[i / 2] > X; i /= 2)
    //     H->Elements[i] = H->Elements[i / 2];
    // H->Elements[i] = X;

    // 将X放于堆中最后一个位置
    H->Elements[++(H->Size)] = X;
    // 执行上滤，调整堆序
    PercolateUp(H->Size, H);
}

ElementType DeleteMin(PriorityQueue H)
{
    if (IsEmpty(H))
    {
        Error("Priority queue is empty");
        return MinData;
    }
    int Parent, Child;
    int MinElement = H->Elements[1];
    int LastElement = H->Elements[H->Size--];

    for (Parent = 1; Parent * 2 <= H->Size; Parent = Child)
    {
        Child = Parent * 2;
        if (Child != H->Size && H->Elements[Child + 1] < H->Elements[Child])
            Child++;
        if (H->Elements[Child] < LastElement)
            H->Elements[Parent] = H->Elements[Child];
        else break;
    }
    H->Elements[Parent] = LastElement;

    return MinElement;
}

ElementType FinMin(PriorityQueue H)
{
    return H->Elements[1];
}

void DecreaseKey(int P, unsigned int delta, PriorityQueue H)
{
    H->Elements[P] -= delta;
    PercolateUp(P, H);
}

void IncreaseKey(int P, unsigned int delta, PriorityQueue H)
{
    H->Elements[P] += delta;
    PercolateDown(P, H);
}

void Delete(int P, PriorityQueue H)
{
    DecreaseKey(P, INT_MAX, H);
    DeleteMin(H);
}

ElementType Retrieve(int index, PriorityQueue H)
{
    if (index > 0 && index <= H->Size)
        return H->Elements[index];
    else
    {
        FatalError("out of index");
        return MinData;
    }
}

int IsEmpty(PriorityQueue H)
{
    return H->Size == 0;
}
int IsFull(PriorityQueue H)
{
    return H->Size == H->Capacity;
}

int Size(PriorityQueue H)
{
    return H->Size;
}