#include "Sort.h"
#include <time.h>
#include <stdlib.h>

int main()
{
    // int arr[] = { 3,8,5,1,2,9,10,7,12,4,5 };
    // int len = sizeof(arr)/sizeof(*arr);

    // Merge_Sort_iter2(arr, len);
    // Print(arr, len);
    srand(time(NULL));
    int size = 1000000;
    int* arr = malloc(sizeof(int) * size);
    int* arr2 = malloc(sizeof(int) * size);
    int* arr3 = malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++)
    {
        int num = rand() % 2000000;
        arr[i] = arr2[i] = arr3[i] = num;
    }
    

    clock_t start, end;
    start = clock();
    Heap_Sort(arr, size);
    end = clock();
    double seconds = (double)(end - start)/CLOCKS_PER_SEC;
    printf("use time is:%.8f\n", seconds);


    start = clock();
    Merge_Sort_iter(arr2, size);
    end = clock();
    seconds = (double)(end - start)/CLOCKS_PER_SEC;
    printf("use time is:%.8f\n", seconds);

    start = clock();
    Quick_Sort(arr3, size);
    end = clock();
    seconds = (double)(end - start)/CLOCKS_PER_SEC;
    printf("use time is:%.8f\n", seconds);

    free(arr);
    free(arr2);
    free(arr3);

    return 0;
}