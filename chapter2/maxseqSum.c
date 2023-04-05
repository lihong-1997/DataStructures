#include<stdlib.h>
#include<stdio.h>

int MaxSubsequenceSum1(const int arr[], int N)
{
    int sum, MaxSum;
    MaxSum = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i; j < N; j++)
        {
            sum = 0;
            for (int k = i; k <= j; k++){
                sum += arr[k];
            }
            if (sum > MaxSum)
                MaxSum = sum;
        }
    }

    return MaxSum;
}

int MaxSubsequenceSum2(const int arr[], int N)
{
    int sum, MaxSum;
    MaxSum = 0;
    for (int i = 0; i < N; i++)
    {
        sum = 0;
        for (int j = i; j < N; j++)
        {
            sum += arr[j];
            if (sum > MaxSum)
                MaxSum = sum;
        }
    }

    return MaxSum;
}

int max3(int a, int b, int c)
{
    int max = a;
    if(b > max) max = b;
    if(c > max) max = c;
    return max;
}

int MaxSubSum(const int arr[], int left, int right)
{
    int center;
    center = (left + right)/2;
    if (left == center){
        if (arr[left] > 0)
            return arr[left];
        else
            return 0;
    }

    int MaxLeftSum = MaxSubSum(arr, left, center);
    int MaxRightSum = MaxSubSum(arr, center +1 , right);

    int MaxLeftBorderSum = 0, LeftBorderSum = 0;
    int MaxRightBorderSum = 0, RightBorderSum = 0;
    int MaxMiddleSum = 0;
    for (int i = center; i >= left; i--)
    {
        LeftBorderSum += arr[i];
        if (LeftBorderSum > MaxLeftBorderSum)
            MaxLeftBorderSum = LeftBorderSum;
    }
    for (int i = center + 1; i <= right; i++)
    {
        RightBorderSum += arr[i];
        if (RightBorderSum > MaxRightBorderSum)
            MaxRightBorderSum = RightBorderSum;
    }
    MaxMiddleSum = MaxLeftBorderSum + MaxRightBorderSum;
    
    return max3(MaxLeftSum, MaxMiddleSum, MaxRightSum);
}

int MaxSubsequenceSum3(const int arr[], int N)
{
    return MaxSubSum(arr, 0, N - 1);
}

int MaxSubsequenceSum4(const int arr[], int N)
{
    int sum = 0, temp_max = 0;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];
        if (sum < 0) sum = 0;
        if (sum > temp_max) temp_max = sum;
    }
    return temp_max;
}

int main(){
    int arr[8] = {-4,-3,5,-2,1,2,-3,-2};

    int max1 = MaxSubsequenceSum1(arr, 8);
    int max2 = MaxSubsequenceSum2(arr, 8);
    int max3 = MaxSubsequenceSum3(arr, 8);
    int max4 = MaxSubsequenceSum4(arr, 8);
    printf("%d,%d,%d,%d", max1,max2,max3,max4);
}