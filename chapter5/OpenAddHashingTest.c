#include "hashquad.h"

int main()
{
    HashTable H;
    int TableSize = 10;
    /******线性探测法******/
    H = InitializeTable(TableSize);
    for (int i = 1; i < 7; i++)
        InsertLinear(i*i, H);
    
    Position p;
    for (int i = 1; i < 7; i++)
    {
        p = FindLinear(i*i, H);
        printf("find value:%d\n", Retrieve(p, H));
    }
    PrintHashTable(H);

    printf("--------------------------\n");

    /******平方探测法******/
    TableSize = 13;
    H = InitializeTable(TableSize);
    for (int i = 1; i < 11; i++)
        H = InsertSquare(i*i, H);
    
    for (int i = 1; i < 11; i++)
    {
        p = FindSquare(i*i, H);
        printf("find value:%d\n", Retrieve(p, H));
    }
    PrintHashTable(H);

    printf("--------------------------\n");
    
    /******双散；列******/
    TableSize = 14;
    H = InitializeTable(TableSize);
    for (int i = 1; i < 11; i++)
        InsertDoubleHash(i*i, H);
    
    for (int i = 1; i < 11; i++)
    {
        p = FindDoubleHash(i*i, H);
        printf("find value:%d\n", Retrieve(p, H));
    }
    PrintHashTable(H);
    return 0;
}


//gcc OpenAddHashingTest.c src/hashquad.c src/hash.c src/prime.c -Iinclude -o main