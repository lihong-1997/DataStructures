#include "hashquad.h"

int main()
{
    HashTable H;
    int TableSize = 10;
    /******����̽�ⷨ******/
    CNum = 0;
    H = InitializeTable(TableSize, 1);
    for (int i = 1; i < 7; i++)
        InsertLinear(i*i, H);
    
    printf("collision count:%d\n", CNum);
    Position p;
    for (int i = 1; i < 7; i++)
    {
        p = FindLinear(i*i, H);
        printf("find value:%d\n", Retrieve(p, H));
    }
    PrintHashTable(H);

    printf("--------------------------\n");

    /******ƽ��̽�ⷨ******/
    TableSize = 13;
    H = InitializeTable(TableSize, 1);
    for (int i = 1; i < 11; i++)
        H = InsertSquare(i*i, H);
    
    for (int i = 1; i < 11; i++)
    {
        p = FindSquare(i*i, H);
        printf("find value:%d\n", Retrieve(p, H));
    }
    PrintHashTable(H);

    printf("--------------------------\n");
    
    /******˫ɢ��,����ʧ�ܰ���******/
    TableSize = 10;
    int testArr[] = { 4371,1323,6173,4199,4344,9679,1989 };
    int len = sizeof(testArr)/sizeof(*testArr);

    H = InitializeTable(TableSize, 0); // ���С��������
    for (int i = 0; i < len; i++)
        InsertDoubleHash(testArr[i], H);
    
    for (int i = 0; i < len; i++)
    {
        p = FindDoubleHash(testArr[i], H);
        if (p != TableSize)
            printf("find value:%d\n", Retrieve(p, H));
        else
            printf("can not find value:%d\n", testArr[i]);
    }
    PrintHashTable(H);
    return 0;
}


//gcc OpenAddHashingTest.c src/hashquad.c src/hash.c src/prime.c -Iinclude -o main