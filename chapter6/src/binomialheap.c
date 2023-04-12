#include "binomialheap.h"

struct BinNode
{
    ElementType Element;
    Position LeftChild; //子树高度最高的
    Position NextSibling;
};

struct Collection
{
    int CurrentSize; //当前二项队列包含的节点树
    BinTree TheTrees[MaxTrees]; //保存森林中每棵树的根节点指针
};

BinQueue Initialize(void)
{
    BinQueue H;
    H = malloc(sizeof(struct Collection));
    if (H == NULL)
        FatalError("out of space");
    H->CurrentSize = 0;
    for (int i = 0; i < MaxTrees; i++)
        H->TheTrees[i] = NULL;
    return H;
}

static void DestroyTree(BinTree T)
{
    if (T != NULL)
    {
        DestroyTree(T->LeftChild);
        DestroyTree(T->NextSibling);
        free(T);
    }
}

void Destroy(BinQueue H)
{
    for (int i = 0; i < MaxTrees; i++)
        DestroyTree(H->TheTrees[i]);
    
    free(H);
}

BinQueue MakeEmpty(BinQueue H)
{
    for (int i = 0; i < MaxTrees; i++)
    {
        DestroyTree(H->TheTrees[i]);
        H->TheTrees[i] = NULL;
    }
    H->CurrentSize = 0;
    return H;
}

BinTree CombineTrees(BinTree T1, BinTree T2)
{
    if (T1->Element > T2->Element)
        return CombineTrees(T2, T1);
    T2->NextSibling = T1->LeftChild;
    T1->LeftChild = T2;
    return T1;
}

//将H2合并到H1上
BinQueue Merge(BinQueue H1, BinQueue H2)
{
    if (H1->CurrentSize + H2->CurrentSize > Capacity)
        Error("merge would exceed capacity");
    
    H1->CurrentSize += H2->CurrentSize;
    BinTree T1, T2, Carry = NULL; //带结合的两颗树，以及结合后的树
    int i, j;

    for (i = 0, j = 1; j <= H1->CurrentSize; i++, j *= 2)
    {
        T1 = H1->TheTrees[i];
        T2 = H2->TheTrees[i];
        switch (!!T1 + 2 * !!T2 + 4 * !!Carry)
        {
        case 0:
        case 1:
            break;
        case 2:
            H1->TheTrees[i] = T2;
            H2->TheTrees[i] = NULL;
            break;
        case 4:
            H1->TheTrees[i] = Carry;
            Carry = NULL;
            break;
        case 3:
            Carry = CombineTrees(T1, T2);
            H1->TheTrees[i] = NULL;
            H2->TheTrees[i] = NULL;
            break;
        case 5:
            Carry = CombineTrees(T1, Carry);
            H1->TheTrees[i] = NULL;
            break;
        case 6:
            Carry = CombineTrees(T2, Carry);
            H2->TheTrees[i] = NULL;
            break;   
        case 7:
            H1->TheTrees[i] = Carry;
            Carry = CombineTrees(T1, T2);
            H2->TheTrees[i] = NULL;
            break;
        }
    }
    return H1;
}

ElementType FindMin(BinQueue H)
{
    ElementType MinItem;
    MinItem = INT_MAX;
    for (int i = 0; i < MaxTrees; i++)
        if (H->TheTrees[i] && H->TheTrees[i]->Element < MinItem)
            MinItem = H->TheTrees[i]->Element;
    
    return MinItem;
}

ElementType DeleteMin(BinQueue H)
{
    if (IsEmpty(H))
    {
        Error("empty binomial queue");
        return INT_MIN;
    }

    ElementType MinItem;
    MinItem = INT_MAX;
    int MinTree; //最小值所在树的索引
    for (int i = 0; i < MaxTrees; i++)
    {
        if (H->TheTrees[i] && H->TheTrees[i]->Element < MinItem)
        {
            MinItem = H->TheTrees[i]->Element;
            MinTree = i;
        }
    }

    BinTree DeletedTree, DeletedTreeChild;
    DeletedTree = H->TheTrees[MinTree];
    DeletedTreeChild = DeletedTree->LeftChild;
    free(DeletedTree);

    BinQueue DeletedQueue;
    DeletedQueue = Initialize();
    DeletedQueue->CurrentSize = (1 << MinTree) - 1; //去掉删除的根
    for (int j = MinTree - 1; j >= 0; j--)
    {
        DeletedQueue->TheTrees[j] = DeletedTreeChild;
        DeletedTreeChild = DeletedTreeChild->NextSibling;
        DeletedQueue->TheTrees[j]->NextSibling = NULL; //去掉多余指针
    }
    H->TheTrees[MinTree] = NULL;
    H->CurrentSize -= (DeletedQueue->CurrentSize + 1);
    Merge(H, DeletedQueue);

    return MinItem;
}

BinQueue Insert(ElementType X, BinQueue H)
{
    BinTree NewNode;
    BinQueue OneTree;
    NewNode = malloc(sizeof(struct BinNode));
    if (NewNode == NULL)
        FatalError("out of space");
    
    NewNode->Element = X;
    NewNode->LeftChild = NewNode->NextSibling = NULL;

    OneTree = Initialize();
    OneTree->CurrentSize = 1;
    OneTree->TheTrees[0] = NewNode;

    return Merge(H, OneTree);
}

int IsFull(BinQueue H)
{
    return H->CurrentSize == Capacity;
}
int IsEmpty(BinQueue H)
{
    return H->CurrentSize == 0;
}