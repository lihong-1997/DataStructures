#include "binheap.h"
#define MaxElements (15)

int main()
{
	int i;
    PriorityQueue H, H2;
    H = Initialize(MaxElements);
	H2 = Initialize(MaxElements);
    int arr[] = { 13,21,16,24,31,19,68,65,26,32 };
    int len = sizeof(arr)/sizeof(*arr);
	//构建堆算法1
    for (i = 0; i < len; i++)
    {
        Insert(arr[i], H);
    }
	//构建堆算法2
	BuildHeap(H2, arr, len);

    for (i = 1; i <= Size(H); i++)
        printf("%d ", Retrieve(i, H));
    printf("\n");

	for (i = 1; i <= Size(H); i++)
        printf("%d ", Retrieve(i, H2));
    printf("\n");

	//堆中插入元素
	Insert(14, H);
	for (i = 1; i <= Size(H); i++)
        printf("%d ", Retrieve(i, H));
    printf("\n");

	//堆中删除最小值
	int min = DeleteMin(H);
	printf("min %d\n", min);
	for (i = 1; i <= Size(H); i++)
        printf("%d ", Retrieve(i, H));
    printf("\n");

    //增加堆中第一个元素关键字的值
    unsigned int delta = 3;
    IncreaseKey(1, delta, H);
    for (i = 1; i <= Size(H); i++)
        printf("%d ", Retrieve(i, H));
    printf("\n");

    //减少堆中最后一个元素关键字的值
    delta = 20;
    DecreaseKey(Size(H), delta, H);
    for (i = 1; i <= Size(H); i++)
        printf("%d ", Retrieve(i, H));
    printf("\n");

    //删除最后一个元素
    Delete(Size(H), H);
    for (i = 1; i <= Size(H); i++)
        printf("%d ", Retrieve(i, H));
    printf("\n");

    return 0;
}

