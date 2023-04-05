#include "hashsep.h"

struct ListNode
{
    ElementType Element;
    Position Next;
};

typedef Position List;
//typedef struct ListNode TableUnit;

struct HashTbl
{
    int TableSize;
    List* TheLists;
};

static Index Hash(ElementType Key, int TableSize)
{
    return Key % TableSize;
}

static int isPrime(int n)
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
        while (++TableSize)
            if (isPrime(TableSize)) break;
        return TableSize;
    }
}

HashTable InitializeTable(int TableSize)
{
    HashTable H;

    if (TableSize < MinTableSize)
    {
        Error("Table size is too small");
        return NULL;
    }

    H = malloc(sizeof(struct HashTbl));
    if (H == NULL)
        FatalError("out of space");
    
    H->TableSize = NextPrime(TableSize);
    H->TheLists = malloc(sizeof(List) * H->TableSize);
    if (H->TheLists == NULL)
        FatalError("out of space");

    for (int i = 0;i < H->TableSize;i++)
    {
        H->TheLists[i] = malloc(sizeof(struct ListNode));
        if (H->TheLists[i] == NULL)
            FatalError("out of space");
        H->TheLists[i]->Next = NULL;
    }
        
    return H;
}

Position Find(ElementType Key, HashTable H)
{
    List L; //pointer to header
    Position P; //pointer to first node

    L = H->TheLists[Hash(Key, H->TableSize)];
    P = L->Next;

    while (P != NULL && P->Element != Key) // probably need strcmp
        P = P->Next;
    
    return P;
}

void Insert(ElementType Key, HashTable H)
{
    Position Pos, NewCell;
    List L;

    Pos = Find(Key, H); //if find key do nothing
    if (Pos == NULL)
    {
        NewCell = malloc(sizeof(struct ListNode));
        if (NewCell == NULL)
            FatalError("out of space");

        L = H->TheLists[Hash(Key, H->TableSize)];
        NewCell->Next = L->Next;
        NewCell->Element = Key;
        L->Next = NewCell;
    }
}

ElementType Retrieve(Position P)
{
    return P->Element;
}
