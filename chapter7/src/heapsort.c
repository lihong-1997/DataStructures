#include "Sort.h"

#define LeftChild(i) (2 * (i) + 1)
// i 对哪个节点下滤 N 控制堆实际作用大小
void PercDown(ElementType A[], int i, int N)
{
    int Child;
    ElementType temp;

    for (temp = A[i]; LeftChild(i) < N; i = Child)
    {
        Child = LeftChild(i);
        if (Child != N - 1 && A[Child + 1] > A[Child])
            Child++;
        if (temp < A[Child])
            A[i] = A[Child];
        else
            break;
    }
    A[i] = temp;
}

void Heap_Sort(ElementType A[], int N)
{
    int i;
    for (i = N / 2; i >= 0; i--)
        PercDown(A, i, N);
    
    for (i = N - 1; i >= 1; i--)
    {
        Swap(&A[0], &A[i]);
        PercDown(A, 0, i);
    }
}