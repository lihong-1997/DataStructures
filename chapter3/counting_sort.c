#include<stdio.h>
#include<stdlib.h>

 int getMax(int a[], int n)
 {
    int i, max;
    max = a[0];
    for (i = 1; i < n; i++)
        if (a[i] > max) max = a[i];       
    return max;
 }

 void counting_sort(unsigned arr[], int n, int cnt[])
 {
    for (int i = 0; i < n; i++)
    {
        cnt[arr[i]]++;
    }
    int pos = 0,i = 0;
    while (pos < n)
    {
        if(cnt[i])
            for (int j = 0; j < cnt[i]; j++)
                arr[pos++] = i;
        ++i;    
    }
    
    
 }

 int main()
 {
    int arr[10] = {1,2,3,4,5,6,7,77,24,50};
    const int len = getMax(arr, 10);
    int Cnt[len];
    for (int i = 0; i < len; i++)
    {
        Cnt[i] = 0;
    }
    counting_sort(arr, 10, Cnt);
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", arr[i]);
    }
    
    

 }
