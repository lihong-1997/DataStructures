#include "leftheap.h"

struct TreeNode
{
    ElementType Element;
    PriorityQueue Left;
    PriorityQueue Right;
    int Npl;
};

PriorityQueue Initialize(void)
{
    return NULL;
}

static void SwapChildren(PriorityQueue H)
{
    PriorityQueue temp;
    temp = H->Left;
    H->Left = H->Right;
    H->Right = temp;
}

static PriorityQueue Merge1(PriorityQueue H1, PriorityQueue H2)
{
    if (H1->Left == NULL) //左儿子为空，由左式堆的性质，右儿子必为空，Npl=0
        H1->Left = H2;
    else
    {
        H1->Right = Merge(H1->Right, H2);
        if (H1->Left->Npl < H1->Right->Npl)
            SwapChildren(H1);
        H1->Npl = H1->Right->Npl + 1;
    }
    return H1;
}

PriorityQueue Merge(PriorityQueue H1, PriorityQueue H2)
{
    if ( H1 == NULL)
        return H2;
    if ( H2 == NULL)
        return H1;
    //保证第一个参数为较小根
    if (H1->Element < H2->Element)
        return Merge1(H1, H2);
    else
        return Merge1(H2, H1);
}

PriorityQueue Insert1(ElementType X, PriorityQueue H)
{
    PriorityQueue SingleNode;
    SingleNode = malloc(sizeof(struct TreeNode));
    if (SingleNode == NULL)
        FatalError("out of space");
    else
    {
        SingleNode->Element = X;
        SingleNode->Npl = 0;
        SingleNode->Left = SingleNode->Right = NULL;
        H = Merge(SingleNode, H);
    }
    return H;
}

PriorityQueue DeleteMin1(PriorityQueue H)
{
    if (IsEmpty(H))
    {
        Error("priority queue is empty");
        return H;
    }
    PriorityQueue LeftHeap, RightHeap;
    LeftHeap = H->Left;
    RightHeap = H->Right;
    free(H);
    
    return Merge(LeftHeap, RightHeap);
}

ElementType FindMin(PriorityQueue H)
{
    return H->Element;
}

int IsEmpty(PriorityQueue H)
{
    return H == NULL;
}