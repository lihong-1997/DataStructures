#include<stdio.h>

#define ElementType int

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

int main()
{
	ElementType A[] = {4,2,9,5,11,7,8,13,10};
	int len = sizeof(A)/sizeof(*A);

	Bubble_Sort(A, len);
	for (int i = 0; i < len; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
	
	return 0;
}
