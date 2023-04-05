#include<stdlib.h>
#include<stdio.h>

long int F1(int arr[], long int X, unsigned int N)
{
    int sum = 0; long int temp;
    for (int i = 0; i <= N; i++)
    {
        temp = 1;
        for (int j = 0; j < i; j++)
        {
            temp *= X;
        }
        sum += arr[i]*temp;
    }
    return sum;
}

long int Pow(long int x, unsigned int N)
{
    if (N == 0) return 1;

    if(N % 2 == 0)
        return Pow(x*x, N/2);
    else
        return Pow(x*x, N/2)*x;
}

long int F2(int arr[], long int X, unsigned int N)
{
    int sum = 0;
    for (int i = 0; i <= N; i++)
    {
        sum += arr[i]*Pow(X, i);
    }
    return sum;
}

long int F3(int arr[], long int X, unsigned int N)
{
    int sum = 0;
    for (int i = N; i >= 0; i--)
    {
        sum = arr[i] + X*sum;
    }
    return sum;
}

int main()
{
    int arr[3] = {1,2,3};
    long int result, result2, result3;
    result = F1(arr, 3, 2);
    result2 = F2(arr, 3, 2);
    result3 = F3(arr, 3, 2);
    printf("%d,%d,%d", result, result2, result3);
}