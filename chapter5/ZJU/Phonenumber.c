#include "Phonenumber.h"

struct HashEntry
{
    ElementType Data;
    int Count;
};

typedef struct HashEntry Cell;

struct HashTbl
{
    int TableSize;
    Cell* TheCells;
};

int NextPrime(int TableSize)
{
    int i;
    int p = (TableSize % 2) ? TableSize + 2 : TableSize + 1;

    while (p <= MAXTABLESIZE)
    {
        for (i = (int)sqrt(p); i > 2; i--)
        {
            if (p % i == 0) break;
        }
        if ( i == 2) break;
        else p += 2;
    }
    
    return p;
}

Index Hash(int Key, int TableSize)
{
    return Key % TableSize;
}

HashTable InitializeTable(int TableSize)
{
    HashTable H;
    H = malloc(sizeof(struct HashTbl));
    if (H == NULL)
        FatalError("out of sapce");

    H->TableSize = NextPrime(TableSize);
    H->TheCells = malloc(sizeof(Cell) * H->TableSize);
    if (H->TheCells == NULL)
        FatalError("out of space");
    // 初始化空单元
    for (int i = 0; i < H->TableSize; i++)
    {
        H->TheCells[i].Count = 0;
        H->TheCells[i].Data[0] = '\0';
    }
        
    return H;
}

Position Find(ElementType Key, HashTable H)
{
    Position CurrentPos;
    CurrentPos = Hash(atoi(Key+KEYLENGTH-5), H->TableSize);
    int CollisionNum;
    CollisionNum = 0;

    //when the table size is prime and half of table is empty, the loop can always break
    while (H->TheCells[CurrentPos].Count != 0 && strcmp(H->TheCells[CurrentPos].Data, Key))
    {
        CurrentPos += 2 * (++CollisionNum) - 1;
        if (CurrentPos >= H->TableSize) 
            CurrentPos %= H->TableSize;
    }
    
    return CurrentPos;
}

void Insert(ElementType Key, HashTable H)
{
    Position P;
    P = Find(Key, H);
    if (H->TheCells[P].Count == 0)
        strcpy(H->TheCells[P].Data, Key);
    H->TheCells[P].Count++;
}

void PrintHashTable(HashTable H)
{
    for (Index i = 0; i < H->TableSize; i++)
    {
        if (H->TheCells[i].Count > 0)
        printf("%s ",H->TheCells[i].Data);
    }
    printf("\n");
}

void ScanAndOutput(HashTable H)
{
    int MaxCnt = 0, PCnt = 0; //定义电话出现最多的次数，狂人数量
    ElementType MinPhone;
    MinPhone[0] = '\0';
    for (Index i = 0; i < H->TableSize; i++) //扫描哈希表
    {
        if (H->TheCells[i].Count == 0) continue;

        if (H->TheCells[i].Count > MaxCnt) //更新最大通话次数
        {
            MaxCnt = H->TheCells[i].Count;
            strcpy(MinPhone, H->TheCells[i].Data);
            PCnt = 1;
        }
        else if (H->TheCells[i].Count == MaxCnt) //更新狂人、狂人中的最小号码
        {
            PCnt++;
            if (strcmp(MinPhone, H->TheCells[i].Data) > 0)
                strcpy(MinPhone, H->TheCells[i].Data);
        }
    }
    printf("%s %d", MinPhone, MaxCnt);
    if (PCnt > 1) printf(" %d", PCnt); //若狂人数量大于1，则输出
    printf("\n");
}