#include "queuesplay.h"
#include "splaytree.h"
#include <stdlib.h>
#include <stdio.h>

//#include "queue.h"

struct SplayNode
{
    ElementType Element;
    Position parent; // parent node
    SplayTree Left;
    SplayTree Right;
};

SplayTree MakeEmpty(SplayTree T)
{
    if (T)
    {
        MakeEmpty(T->Left);
        MakeEmpty(T->Right);
        free(T);
    }
    return NULL;
}

static Position SingleRotateWithLeft(Position k2) //LL
{
    Position k1;
    k1 = k2->Left;
    if (k1->Right != NULL)
        k1->Right->parent = k2;

    k2->Left = k1->Right;
    k1->Right = k2;
    k1->parent = k2->parent;
    k2->parent = k1;

    return k1;
}

static Position SingleRotateWithRight(Position k2) //RR
{
    Position k1;
    k1 = k2->Right;
    if (k1->Left != NULL)
        k1->Left->parent = k2;

    k2->Right = k1->Left;
    k1->Left = k2;

    k1->parent = k2->parent;
    k2->parent = k1;

    return k1;
}

static Position ZigZigRotateWithLeft(Position k3)
{
    Position k2 = k3->Left;
    Position k1 = k2->Left;

    k3->Left = k2->Right;
    k2->Left = k1->Right;
    if (k1->Right) k1->Right->parent = k2;
    if (k2->Right) k2->Right->parent = k3;

    k1->Right = k2;
    k2->Right = k3;

    //Position linkNode = k3->parent;
    k1->parent = k3->parent;
    k2->parent = k1;
    k3->parent = k2;


    // if (linkNode)
    // {
    //     if (linkNode->Element < k3->Element)
    //         linkNode->Right = k1;
    //     else
    //         linkNode->Left = k1;
    // }


    return k1;
}

static Position ZigZigRotateWithRight(Position k3)
{
    Position k2 = k3->Right;
    Position k1 = k2->Right;

    k3->Right = k2->Left;
    k2->Right = k1->Left;
    if (k1->Left) k1->Left->parent = k2;
    if (k2->Left) k2->Left->parent = k3;

    k1->Left = k2;
    k2->Left = k3;

    //Position linkNode = k3->parent;
    k1->parent = k3->parent;
    k2->parent = k1;
    k3->parent = k2;


    // if (linkNode)
    // {
    //     if (linkNode->Element < k3->Element)
    //         linkNode->Right = k1;
    //     else
    //         linkNode->Left = k1;
    // }


    return k1;
}

static Position ZigZagRotateWithRight(Position k3)
{
    k3->Right = SingleRotateWithLeft(k3->Right);

    return SingleRotateWithRight(k3);
}

static Position ZigZagRotateWithLeft(Position k3)
{
    k3->Left = SingleRotateWithRight(k3->Left);

    return SingleRotateWithLeft(k3);
}

//Move the accessed node to the root
SplayTree Splaying(SplayTree T, Position Node)
{
    /*
     * 1.the parent of X is root,single rotate
     * 2.X has parent and grandparent
     * (1) zig-zag: double rotate like AVL
     * (2) zig-zig: zig-zig rotate
     */

    while (Node->parent != NULL)
    {
        if (Node->parent == T) //rotate x and root
        {
            if (Node->Element < Node->parent->Element)
                T = SingleRotateWithLeft(T);
            else
                T = SingleRotateWithRight(T);
        }
        else
        {
            Position parent = Node->parent;
            Position grandparent = parent->parent;
            Position linkNode = grandparent->parent;

            int flag1 = 0, flag2 = 0;
            flag1 = grandparent->Element > parent->Element;
            flag2 = parent->Element > Node->Element;

            if (flag1 && flag2)// ZigZigRotateWithLeft
            {
                if (linkNode != NULL)
                {
                    if (linkNode->Element < grandparent->Element)
                        linkNode->Right = ZigZigRotateWithLeft(grandparent);
                    else
                        linkNode->Left = ZigZigRotateWithLeft(grandparent);
                }
                else
                    T = ZigZigRotateWithLeft(grandparent);
            }
             else if (flag1 && !flag2) //ZigZag use LR DoubleRotateWithLeft
             {
                if (linkNode != NULL)
                {
                    if (linkNode->Element < grandparent->Element)
                        linkNode->Right = ZigZagRotateWithLeft(grandparent);
                    else
                        linkNode->Left = ZigZagRotateWithLeft(grandparent);
                }
                else
                 T = ZigZagRotateWithLeft(grandparent);
             }
             else if (!flag1 && flag2) //ZigZag use RL DoubleRotateWithRight
             {
                if (linkNode != NULL)
                {
                    if (linkNode->Element < grandparent->Element)
                        linkNode->Right = ZigZagRotateWithRight(grandparent);
                    else
                        linkNode->Left = ZigZagRotateWithRight(grandparent);
                }
                else
                 T = ZigZagRotateWithRight(grandparent);
             }
             else if (!flag1 && !flag2) // ZigZigRotateWithRight
             {
                if (linkNode != NULL)
                {
                    if (linkNode->Element < grandparent->Element)
                        linkNode->Right = ZigZigRotateWithRight(grandparent);
                    else
                        linkNode->Left = ZigZigRotateWithRight(grandparent);
                }
                else
                    T = ZigZigRotateWithRight(grandparent);
             }
        }
    }
    return T;
}

static Position insert(ElementType X, SplayTree T, Position* P)
{
    if (T == NULL)
    {
        T = malloc(sizeof(struct SplayNode));
        if (T == NULL)
        {
            printf("out of space");
            exit(1);
        }
        else
        {
            T->Element = X;
            T->Left = T->Right = T->parent = NULL;
        	*P = T; // get the address of inserted node
        }
    }

    else if (X < T->Element)
    {
        T->Left = insert(X, T->Left, P);
        T->Left->parent = T;
    }

    else if (X > T->Element)
    {
        T->Right = insert(X, T->Right, P);
        T->Right->parent = T;
    }

    return T;
}

Position Insert(ElementType X, SplayTree T)
{
    Position p = NULL;
    T = insert(X, T, &p);
    T = Splaying(T, p);
    return T;
}

Position Find(ElementType X, SplayTree T)
{
    Position P = T;
    if (T != NULL)
    {
        while (P!= NULL && P->Element != X)
        {
            if (P->Element < X) P = P->Right;
            else if (P->Element > X) P = P->Left;
        }
        //after splaying,the root is X
        T = Splaying(T, P);
    }
    
    return T;
}

void PreOrderTraversal(SplayTree T)
{
    if (T)
    {
        int lc = (T->Left) ? T->Left->Element : -1;
        int rc = (T->Right) ? T->Right->Element : -1;
        printf("%d:%d %d\n", T->Element, lc, rc);
        PreOrderTraversal(T->Left);
        PreOrderTraversal(T->Right);
    }
}

int InternalPathLen(SplayTree T)
{
    if (T == NULL)
        return 0;

    Position tNode = T;

    Queue Q;
    Q = CreateQueue(1200);

    Enqueue(tNode, Q);

    int depth = 0;
    int Dn = 0; // internal path length
    while (!IsQueueEmpty(Q))
    {
        int size = QueueSize(Q);

        for (int i = 0; i < size; i++)
        {
            tNode = FrontElement(Q);
            Dn += depth;
            Dequeue(Q);
            if (tNode->Left) Enqueue(tNode->Left, Q);
            if (tNode->Right) Enqueue(tNode->Right, Q);
        }
        depth++;
    }

    //DisposeQueue(Q);
    return Dn;
}