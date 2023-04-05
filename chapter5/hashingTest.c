#include "hashsep.h"

int main()
{
    HashTable H;
    int tableSize = 100;
    H = InitializeTable(tableSize);
    for (int i = 1; i < 120; i++)
        Insert(i, H);
    
    Position p;
    p = Find(115, H);
    printf("%d\n",Retrieve(p));
}