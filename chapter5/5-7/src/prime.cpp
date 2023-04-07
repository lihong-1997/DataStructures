#include "prime.h"

int isPrime(int n)
{
    for (int i = 2; i * i <=n; i++)
    {
        if (n % i == 0) return 0;
    }
    return 1;
}

int NextPrime(int TableSize)
{
    if (isPrime(TableSize))
        return TableSize;
    else
    {
        TableSize = (TableSize % 2) ? TableSize+2:TableSize+1;
        for (;;TableSize += 2)
            if (isPrime(TableSize)) break;
        return TableSize;
    }
}

int LastPrime(int TableSize)
{
    if (isPrime(TableSize))
        return TableSize;
    else
    {
        while (--TableSize)
            if (isPrime(TableSize)) break;
        return TableSize;
    }
}