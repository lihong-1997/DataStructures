#include "Sort.h"

int main()
{
    int arr[] = { 3,8,5,1,2,9,10,7,12,4,5 };
    int len = sizeof(arr)/sizeof(*arr);
    Merge_Sort_iter(arr, len);
    Print(arr, len);

    return 0;
}