#include<stdlib.h>
#include<stdio.h>

int BinarySearch(const int arr[], int N, int item)
{
    int low, mid, high;
    low = 0; high = N -1;
    while (low<=high)
    {
        mid = (low + high) / 2;
        if (item > arr[mid])
        {
            low = mid + 1;
        }
        else if(item < arr[mid])
        {
            high = mid - 1;
        }
        else
            return mid;
    }
    return -1;
}

int main()
{
    int arr[8] = {1,2,3,4,5,6,7,8};
    int index;
    index = BinarySearch(arr, 8, 3);
    printf("%d\n", index);
    index = BinarySearch(arr, 8, 11);
    printf("%d", index);
}