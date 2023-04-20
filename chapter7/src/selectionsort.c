#include "Sort.h"

int ScanForMin(ElementType A[], int begin, int end)
{
    int min = A[begin];
    int p = begin;
    for (int i = begin + 1; i <= end; i++) {
        if (A[i] < min) {
            min = A[i];
            p = i;
        }
    }
    return p;
}


void Selection_Sort(ElementType A[], int N)
{
    int i, MinPosition;
    for (i = 0; i < N; i++) {
        MinPosition = ScanForMin(A, i, N - 1);
        Swap(&A[i], &A[MinPosition]);
    }
}