#include "hashquad.h"
#include "hash.h"
#include "prime.h"

//开放定址法只能采用懒惰删除，故表的每个单元需要3个状态
enum KindOfEntry {Legitimate, Empty, Deleted};

struct HashEntry
{
    ElementType Element;
    enum KindOfEntry Info;
};

typedef struct HashEntry Cell;

struct HashTbl
{
    int TableSize;
    Cell* TheCells;
};

HashTable InitializeTable(int TableSize, int FLAG)
{
    if (TableSize < MinTableSize)
    {
        Error("Table size too small");
        return NULL;
    }

    HashTable H;
    H = malloc(sizeof(struct HashTbl));
    if (H == NULL)
        FatalError("out of space");
    
    // 判断需不需要对表的大小采取素数方案
    H->TableSize = FLAG ? NextPrime(TableSize) : TableSize;

    H->TheCells = malloc(sizeof(Cell) * H->TableSize);
    if (H == NULL)
        FatalError("out of space");
    // 初始化空单元
    for (int i = 0; i < H->TableSize; i++)
        H->TheCells[i].Info = Empty;
    
    printf("hash table has been created, size:%d\n", H->TableSize);

    return H;
}

void DestroyTable(HashTable H)
{
    free(H->TheCells);
    free(H);
}

Position FindLinear(ElementType Key, HashTable H)
{
    Position CurrentPos;
    CurrentPos = Hash(Key, H->TableSize);
    int CollisionNum;
    CollisionNum = 0;

    // 只要表不满，循环可退出
    while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
    {
        // Entering loop indicates a collision
        // solvement : F(i) = i
        ++CurrentPos;
        ++CollisionNum;
        if (CurrentPos >= H->TableSize) 
            CurrentPos %= H->TableSize;
    }

    CNum += CollisionNum;

    return CurrentPos;
}

void InsertLinear(ElementType Key, HashTable H)
{
    Position P;
    P = FindLinear(Key, H);
    // 对已经存在的数，不进行插入
    if (H->TheCells[P].Info != Legitimate) 
    {
        H->TheCells[P].Element = Key;
        H->TheCells[P].Info = Legitimate;
    }
}

Position FindSquare(ElementType Key, HashTable H)
{
    Position CurrentPos;
    CurrentPos = Hash(Key, H->TableSize);
    int CollisionNum;
    CollisionNum = 0;

    //when the table size is prime and half of table is empty, the loop can always break
    while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
    {
        // Entering loop indicates a collision

        // solvement 1: F(i) = i*i
        CurrentPos += 2 * (++CollisionNum) - 1; // great
        if (CurrentPos >= H->TableSize) 
            CurrentPos %= H->TableSize;
    }

    CNum += CollisionNum;
    
    return CurrentPos;

    // solvement 2: F(i) = ±i*i
    // int NewPos = CurrentPos;
    // while (H->TheCells[NewPos].Info != Empty && H->TheCells[NewPos].Element != Key)
    // {
    //     // Entering loop indicates a collision
    //     // go right
    //     if (++CollisionNum % 2)
    //     {
    //         NewPos = CurrentPos + (CollisionNum + 1)/2 * (CollisionNum + 1)/2;
    //         while (NewPos >= H->TableSize) NewPos -= H->TableSize;
    //     }
    //     else // go left
    //     {
    //         NewPos = CurrentPos - CollisionNum / 2 * CollisionNum / 2;
    //         while (NewPos < 0) NewPos += H->TableSize;
    //     }
    // }

    //CNum += CollisionNum;

    //return NewPos;
}

HashTable InsertSquare(ElementType Key, HashTable H)
{
    Position P;
    double LoadFactor;
    P = FindSquare(Key, H);
    if (H->TheCells[P].Info != Legitimate)
    {
        H->TheCells[P].Element = Key;
        H->TheCells[P].Info = Legitimate;
    }
    LoadFactor = GetLoadFactor(H);
    // printf("load factor:%f\n", LoadFactor);
    if (LoadFactor > CriticalValue)
    {
        printf("rehash happened\n");
        H = Rehash(H);
    }
    return H;
}

Position FindDoubleHash(ElementType Key, HashTable H)
{
    Position CurrentPos, BeginPos;
    CurrentPos = BeginPos = Hash(Key, H->TableSize);
    int CollisionNum;
    CollisionNum = 0;

    int R;
    R = LastPrime(H->TableSize);
    // 散列表大小不是素数，可能无法退出循环
    while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
    {
        // 进入循环说明发生冲突
        ++CollisionNum;
        // 冲突解决方法: F(i) = i*hash(X) = i*(R-(X modR)), R必须为小于表的素数
        CurrentPos += (R - (Key % R));
        if (CurrentPos >= H->TableSize) 
            CurrentPos %= H->TableSize;
        
        // 判断是否回到循环开始，若是则证明没有单元可以插入或没有找到元素
        if (CurrentPos == BeginPos)
        {
            printf("this key(%d)  not be inserted or found!!\n", Key);
            return H->TableSize;
        }
    }

    CNum += CollisionNum;

    return CurrentPos;
}

void InsertDoubleHash(ElementType Key, HashTable H)
{
    Position P;
    P = FindDoubleHash(Key, H);
    if (P != H->TableSize && H->TheCells[P].Info != Legitimate)
    {
        H->TheCells[P].Element = Key;
        H->TheCells[P].Info = Legitimate;
    }
}

void PrintHashTable(HashTable H)
{
    for (unsigned int i = 0; i < H->TableSize; i++)
    {
        if (H->TheCells[i].Info == Legitimate)
        printf("%d ",H->TheCells[i].Element);
    }
    printf("\n");
}

double GetLoadFactor(HashTable H)
{
    unsigned int count = 0;
    for (unsigned int i = 0; i < H->TableSize; i++)
        if (H->TheCells[i].Info != Empty) ++count;
    
    return (double)count / H->TableSize;
}

ElementType Retrieve(Position P, HashTable H)
{
    return H->TheCells[P].Element;
}

HashTable Rehash(HashTable H)
{
    int OldSize;
    Cell* OldCells;
    OldSize = H->TableSize;
    OldCells = H->TheCells;

    H = InitializeTable(2 * OldSize, 1);

    for (int i = 0; i < OldSize; i++)
    {
        if (OldCells[i].Info == Legitimate)
            H = InsertSquare(OldCells[i].Element, H);
    }

    free(OldCells);

    return H;
}