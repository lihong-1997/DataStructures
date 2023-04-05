#include<stdio.h>
int findA(int arr[], int N)
{
    int i = 0;
    while (i < N)
    {
        if (arr[i] == i+1)
        {
            return i;
        }
        i++;
    }
    return -1;
}

int main(){
    int arr[8] = {0,1,2,4,7,8,9,10};
    int index;
    index = findA(arr, 8);
    printf("%d",index);
}