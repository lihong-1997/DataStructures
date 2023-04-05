#include<stdlib.h>
#include<stdio.h>

long int Pow(long int x, unsigned int N)
{
    if (N == 0) return 1;

    if(N % 2 == 0)
        return Pow(x*x, N/2);
    else
        return Pow(x*x, N/2)*x;
}

int main()
{
    long int result;
    result = Pow(2, 6);
    printf("%d", result);
}