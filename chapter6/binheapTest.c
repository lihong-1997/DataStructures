#include "binheap.h"

int main()
{
	int i;
    PriorityQueue H, H2;
    H = Initialize(15);
	H2 = Initialize(15);
    int arr[] = { 13,21,16,24,31,19,68,65,26,32 };
    int len = sizeof(arr)/sizeof(*arr);
	//�������㷨1
    for (i = 0; i < len; i++)
        Insert(arr[i], H);
	//�������㷨2
	BuildHeap(H2, arr, len);

    for (i = 1; i <= Size(H); i++)
        printf("%d ", Retrieve(i, H));
    printf("\n");

	for (i = 1; i <= Size(H); i++)
        printf("%d ", Retrieve(i, H2));
    printf("\n");

	//���в���Ԫ��
	Insert(14, H);
	for (i = 1; i <= Size(H); i++)
        printf("%d ", Retrieve(i, H));
    printf("\n");

	//����ɾ����Сֵ
	int min = DeleteMin(H);
	printf("min %d\n", min);
	for (i = 1; i <= Size(H); i++)
        printf("%d ", Retrieve(i, H));
    printf("\n");

    return 0;
}

