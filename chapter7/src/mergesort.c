#include "Sort.h"

void Merge(ElementType A[], ElementType TmpArray[],
                    int Lpos, int Rpos,int RightEnd)
{
    int LeftEnd, NumElements, TmpPos;
    LeftEnd = Rpos - 1;
    TmpPos = Lpos;
    NumElements = RightEnd - Lpos + 1;

    while (Lpos <= LeftEnd && Rpos <= RightEnd)
        if (A[Lpos] <= A[Rpos])
            TmpArray[TmpPos++] = A[Lpos++];
        else
            TmpArray[TmpPos++] = A[Rpos++];

    while (Lpos <= LeftEnd)
        TmpArray[TmpPos++] = A[Lpos++];
    while (Rpos <= RightEnd)
        TmpArray[TmpPos++] = A[Rpos++];

    for (int i = 0; i < NumElements;i++, RightEnd--)
        A[RightEnd] = TmpArray[RightEnd];
}

void MSort(ElementType A[], ElementType TmpArray[], int Left, int Right)
{
    int Center;

    if (Left < Right)
    {
        Center = (Left + Right) / 2;
        MSort(A, TmpArray, Left, Center);
        MSort(A, TmpArray, Center + 1, Right);
        Merge(A, TmpArray, Left, Center + 1, Right);
    }
}

void Merge_Sort(ElementType A[], int N)
{
    ElementType* TmpArray;
    TmpArray = malloc(sizeof(ElementType) * N);
    if (TmpArray == NULL)
        FatalError("out of space");
    
    MSort(A, TmpArray, 0, N - 1);
    free(TmpArray);
}

void Merge1(ElementType A[], ElementType TmpArray[],
                    int Lpos, int Rpos,int RightEnd)
{
    int LeftEnd, NumElements, TmpPos;
    LeftEnd = Rpos - 1;
    TmpPos = Lpos;
    NumElements = RightEnd - Lpos + 1;

    while (Lpos <= LeftEnd && Rpos <= RightEnd)
        if (A[Lpos] <= A[Rpos])
            TmpArray[TmpPos++] = A[Lpos++];
        else
            TmpArray[TmpPos++] = A[Rpos++];

    while (Lpos <= LeftEnd)
        TmpArray[TmpPos++] = A[Lpos++];
    while (Rpos <= RightEnd)
        TmpArray[TmpPos++] = A[Rpos++];
}

void Merge_Pass(ElementType A[], ElementType TmpArray[], int N, int length)
{
    int i, j;
    //�Ͻ���Rend����С�ڵ����������һλ������ȷ��
    for (i = 0; i <= N - 2 * length; i += 2 * length)
        Merge1(A, TmpArray, i, i + length, i + 2 * length - 1);
    if (i + length < N) //LendС��N-1,˵�������Ұ�����
        Merge1(A, TmpArray, i, i + length, N - 1);
    else //Lend=N-1,˵��ֻ��������У�j=Lbegin; Lend>N-1,˵�������ж�û�У���ִ��ѭ��
        for (j = i; j < N; j++) TmpArray[j] = A[j];
}

void Merge_Sort_iter(ElementType A[], int N)
{
    int length = 1;
    ElementType* TmpArray;
    TmpArray = malloc(sizeof(ElementType) * N);
    if (TmpArray == NULL)
        FatalError("out of space");
    while (length < N) {
        Merge_Pass(A, TmpArray, N, length);
        length *= 2;
        Merge_Pass(TmpArray, A, N, length); //��֤�ź��������һ����A��
        length *= 2;
    }
    free(TmpArray);
}