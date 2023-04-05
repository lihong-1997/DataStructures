#include<stdlib.h>
#include<stdio.h>

unsigned int Gcd(unsigned int M, unsigned int N)
{
    unsigned int Rem;
    while (N > 0) //余数为0退出循环
    {
        Rem = M % N;
        M = N;
        N = Rem;
    }
    return M;
}

int main()
{
    int gcd = Gcd(50, 16);
    printf("%d",gcd);
}