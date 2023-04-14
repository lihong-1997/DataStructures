#include "Sort.h"

void Insertion_Sort(ElementType A[], int N)
{
    int i, j;
    ElementType temp;
    for (i = 1; i < N; i++)
    {
        temp = A[i];
        for (j = i; j > 0 && A[j -1] > temp; j--)
            A[j] = A[j - 1];
        A[j] = temp;
    }
}