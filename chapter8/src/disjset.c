#include "disjset.h"

void Initialize(DisjSet S)
{
    int i;
    for (i = NumSets; i > 0; i--) {
        S[i] = 0;
    }
}
void SetUnion(DisjSet S, SetType Root1, SetType Root2)
{
    S[Root1] = Root2;
}