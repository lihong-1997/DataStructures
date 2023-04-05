#include "hashquad.h"
#include "hash.h"
#include "prime.h"

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

HashTable InitializeTable(int TableSize)
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
    
    H->TableSize = NextPrime(TableSize);
    H->TheCells = malloc(sizeof(Cell) * H->TableSize);
    if (H == NULL)
        FatalError("out of space");

    for (int i = 0; i < H->TableSize; i++)
        H->TheCells[i].Info = Empty;

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

    // only when the table size is prime and half of table is empty, the loop can break
    while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
    {
        // Entering loop indicates a collision
        // solvement : F(i) = i
        ++CurrentPos;
        ++CollisionNum;
        if (CurrentPos >= H->TableSize) 
            CurrentPos %= H->TableSize;
    }

    return CurrentPos;
}

void InsertLinear(ElementType Key, HashTable H)
{
    Position P;
    P = FindLinear(Key, H);
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

    // only when the table size is prime and half of table is empty, the loop can break
    while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
    {
        // Entering loop indicates a collision

        // solvement 1: F(i) = i*i
        CurrentPos += 2 * (++CollisionNum) - 1; // great
        if (CurrentPos >= H->TableSize) 
            CurrentPos %= H->TableSize;
    }
    // solvement 2: F(i) = ±i*i
    // int NewPos = CurrentPos;
    // while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
    // {
    //     // Entering loop indicates a collision
    //     // go right
    //     if (++CollisionNum % 2)
    //     {
    //         NewPos = CurrentPos + (CollisionNum + 1)/2 * (CollisionNum + 1)/2;
    //         while (CurrentPos >= H->TableSize) NewPos -= H->TableSize;
    //     }
    //     else // go left
    //     {
    //         NewPos = CurrentPos - CollisionNum / 2 * CollisionNum / 2;
    //         while (CurrentPos < 0) NewPos += H->TableSize;
    //     }
    // }
    // return NewPos;

    return CurrentPos;
}

void InsertSquare(ElementType Key, HashTable H)
{
    Position P;
    P = FindSquare(Key, H);
    if (H->TheCells[P].Info != Legitimate)
    {
        H->TheCells[P].Element = Key;
        H->TheCells[P].Info = Legitimate;
    }
}

Position FindDoubleHash(ElementType Key, HashTable H)
{
    Position CurrentPos;
    CurrentPos = Hash(Key, H->TableSize);
    int CollisionNum;
    CollisionNum = 0;

    int R;
    R = LastPrime(H->TableSize);
    // only when the table size is prime and half of table is empty, the loop can break
    while (H->TheCells[CurrentPos].Info != Empty && H->TheCells[CurrentPos].Element != Key)
    {
        // Entering loop indicates a collision
        // solvement: F(i) = i*hash(X) = i*(R-(X modR)),R must be prime and less than table size
        CurrentPos += (R - (Key % R)); // great
        if (CurrentPos >= H->TableSize) 
            CurrentPos %= H->TableSize;
    }

    return CurrentPos;
}

void InsertDoubleHash(ElementType Key, HashTable H)
{
    Position P;
    P = FindDoubleHash(Key, H);
    if (H->TheCells[P].Info != Legitimate)
    {
        H->TheCells[P].Element = Key;
        H->TheCells[P].Info = Legitimate;
    }
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

    H = InitializeTable(2 * OldSize);

    for (int i = 0; i < OldSize; i++)
    {
        if (OldCells[i].Info == Legitimate)
            Insert(OldCells[i].Element, H);
    }

    free(OldCells);

    return H;
}