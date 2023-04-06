#include "hashquad.h"

unsigned int CNum = 0;

int main()
{
    int len = 100;
    int testArr[len];
    srand(time(NULL));
    for (int i = 0; i < len; i++)
        testArr[i] = rand()%800 + 1;

    HashTable H;
    int TableSize = 200;

    /******线性探测法******/
    CNum = 0;
    H = InitializeTable(TableSize, 1);
    for (int i = 1; i < len; i++)
        InsertLinear(testArr[i], H);
    
    printf("linear:collision count %d\n", CNum);
    printf("--------------------------\n");

    /******平方探测法******/
    CNum = 0;
    H = InitializeTable(TableSize, 1);
    for (int i = 1; i < len; i++)
        H = InsertSquare(testArr[i], H);
    printf("squre:collision count %d\n", CNum);
    printf("--------------------------\n");
    
    /*******双散列*******/
    CNum = 0;
    H = InitializeTable(TableSize, 1);
    for (int i = 0; i < len; i++)
        InsertDoubleHash(testArr[i], H);

    printf("double:collision count %d\n", CNum);

    return 0;
}


//gcc 5-3CollisionCount.c src/hashquad.c src/hash.c src/prime.c -Iinclude -o main