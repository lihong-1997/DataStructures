#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

#include "Sort.h"
#include "list.h"

void DeleteSame(int A[], int index, int*LastPositon)
{
	for (int i = index; i < *LastPositon; ++i)
		A[i] = A[i + 1];
	--(*LastPositon);
}

//O(N^3)
int DeleteSameValue_Array(int A[], int N)
{
	int LastPositon = N - 1;
	for (int i = 0;i < LastPositon;i++)
	{
		int j = i + 1;
		while (j <= LastPositon)
		{
			if (A[i] == A[j])
				DeleteSame(A, j, &LastPositon);
			else
				j++;
		}
	}
	return ++LastPositon;
}

//O(N^2)
void DeleteSameValue_List(int A[], int N)
{
	//int LastPositon = N - 1;

	List l1 = LinkedListCreateFromArray(A, N);

	Position CompareNode = First(l1);
	Position PreNode;

	while (!IsLast(CompareNode, l1))
	{
		Position Next = Advance(CompareNode);
		PreNode = CompareNode;
		while (Next != NULL)
		{
			if (Retrieve(CompareNode) == Retrieve(Next))
			{
				Delete_pPre(Retrieve(Next), l1, PreNode);
				Next = Advance(PreNode);
			}
			else
			{
				PreNode = Next;
				Next = Advance(Next);
			}
		}
		CompareNode = Advance(CompareNode);
	}
	PrintList(l1);

}

//O(N*logN)
void DeleteSameValue_Sort(int A[], int N)
{
	int* res = malloc(sizeof(int) * N);
	int num = 0;
	quickSort(A, 0, N - 1);
	for (int i = 1; i < N; ++i)
	{
		if (A[i] != A[i - 1])
			res[num++] = A[i - 1];
	}
	res[num++] = A[N - 1];

	for (int i = 0; i < num; ++i)
	{
		printf("%d ", res[i]);
	}
}

int main()
{
	int arr[] = {3,3,4,6,5,7,7,7};
	
	int n = sizeof(arr) / sizeof(arr[0]);
	DeleteSameValue_Sort(arr, 8);

	//DeleteSameValue_List(arr, 8);
	/*int len = DeleteSameValue_Array(arr, 8);
	for (int i = 0; i < len; ++i)
	{
		printf("%d ", arr[i]);
	}*/

}