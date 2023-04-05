/* Determine whether two sequences correspond to the same search tree
 * 1.Build trees according to the two sequences, and then judge whether the trees are the same
 * 2.only use two sequences
 * 3.First build a tree, and then judge whether other sequences correspond to the tree
 */

#include "searchtree.h"
#include <stdio.h>
//gcc -g SeqToSearchTree.c src/searchtree.c src/queue.c -Iinclude -o exe/mains

//mothod 1
int CompareByTwoTree(ElementType* Seq1, ElementType* Seq2, int len)
{
    SearchTree T1, T2;
    T1 = MakeEmpty(NULL);
    T2 = MakeEmpty(NULL);

    for (int i = 0; i < len; i++)
    {
        T1 = Insert(Seq1[i], T1);
        T2 = Insert(Seq2[i], T2);
    }
    
    int re = isSame(T1 ,T2);

    return re;
}

//method 2
int CompareBySeq(ElementType* Seq1, ElementType* Seq2, int len)
{
    if (Seq1[0] != Seq2[0]) return 0;
    int lSeq1Len = 0, rSeq1Len = 0, lSeq2Len = 0, rSeq2Len = 0;
    ElementType lSeq1[len],rSeq1[len],lSeq2[len],rSeq2[len];
    for (int i = 1;i < len;i++)
    {
        if (Seq1[i] < Seq1[0]) lSeq1[lSeq1Len++] = Seq1[i];    
        if (Seq1[i] > Seq1[0]) rSeq1[rSeq1Len++] = Seq1[i];
        if (Seq2[i] < Seq2[0]) lSeq2[lSeq2Len++] = Seq2[i];
        if (Seq2[i] > Seq2[0]) rSeq2[rSeq2Len++] = Seq2[i];
    }

    if (lSeq1Len != lSeq2Len || rSeq1Len != rSeq2Len) return 0;
    if (lSeq1Len == 0 || rSeq1Len == 0) return 1;

    return CompareBySeq(lSeq1, lSeq2, lSeq1Len) && CompareBySeq(rSeq1, rSeq2, rSeq1Len);
}

int CompareByOneTree(ElementType* BaseSeq, ElementType* Seq, int len)
{
    SearchTree T1;
    T1 = MakeEmpty(NULL);
    for (int i = 0; i < len;i++)
        T1 = Insert(BaseSeq[i], T1);
    int re = 1;
    for (int i = 0; i < len;i++) {
        re = check(T1, Seq[i]);
        if (re == 0) break;
    }
    
    return re;
}

int main()
{
    int seq1[] = {3,1,4,2};
    int seq2[] = {3,4,1,2};
    int seq3[] = {3,2,4,1};
    int len = sizeof(seq1)/sizeof(*seq1);

    int re1 = CompareBySeq(seq1, seq2, len);
    int re2 = CompareBySeq(seq1, seq3, len);
    printf("method 2:%d %d\n", re1, re2);

    re1 = CompareByTwoTree(seq1, seq2, len);
    re2 = CompareByTwoTree(seq1, seq3, len);
    printf("method 1:%d %d\n", re1, re2);

    re1 = CompareByOneTree(seq1, seq2, len);
    re2 = CompareByOneTree(seq1, seq3, len);
    printf("method 3:%d %d\n", re1, re2);

    return 0;
}