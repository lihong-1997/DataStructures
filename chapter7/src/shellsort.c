#include "Sort.h"

void Shell_Sort(ElementType A[], int N)
{
    int i, j, increment;
    ElementType temp;

    for (increment = N / 2; increment > 0; increment /= 2)
    {
        for (i = increment; i < N; i++)
        {
            temp = A[i];
            for (j = i; j >= increment; j -= increment)
            {
                if (temp < A[j - increment])
                    A[j] = A[j - increment];
                else
                    break;
            }
            A[j] = temp;
        }
    }
}