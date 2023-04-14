#include "Sort.h"

void Print(ElementType A[], int N)
{
	for(int i = 0; i < N; i++)
		printf("%d ", A[i]);
	printf("\n");
}

void Swap(ElementType* val1, ElementType* val2)
{
	ElementType temp;
	temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}

void Bubble_Sort(ElementType A[], int N)
{
	int P, i;
	int flag;
	for( P = N - 1; P >= 0; P--)
	{
		flag = 0;
		for ( i = 1; i<= P; i++)
		{
			if (A[i] < A[i-1])
			{
				Swap(&A[i], &A[i-1]);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}
}