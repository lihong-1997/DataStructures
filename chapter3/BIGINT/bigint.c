#include "bigint.h"

int IsLast(Position P, BigInt BI)
{
	return P->Next == NULL;
}

void Insert(int c, int e, BigInt BI, Position P) //p位置后面插入元素
{
	Position tmp;
	tmp = malloc(sizeof(struct Node));
	if (tmp == NULL)
	{
		printf("out of space");
		exit(EXIT_FAILURE);
	}
	tmp->Coefficient = c;
	tmp->Exponent = e;
	tmp->Previous = P;
	tmp->Next = P->Next;

	P->Next = tmp;
	if (!IsLast(tmp, BI))
		tmp->Next->Previous = tmp;
}

void PrintBigInt(BigInt BI)
{
	Position P;
	P = BI;
	if (IsLast(P, BI))
		return;
	int E = P->Next->Exponent; //最高次幂的值
	while (E >= 0 && !IsLast(P, BI))
	{
		if (P->Next->Exponent == E)
		{
			printf("%d", P->Next->Coefficient);
			P = P->Next;
		}
		else
			printf("0"); //需要补0
		E--;
	}
	printf("\n");
}

void BigIntConstructor(int* C, int* E, int N, BigInt BI)
{
    /*
     * 链表从左至右位数降低排列
     */
    Position P = BI;
    while (!IsLast(P, BI)) //找到最后的节点
        P = P->Next;

    for (int i = 0; i < N; i++)
    {
        Position tmp;
        tmp = (Position)malloc(sizeof(struct Node));
        if (tmp == NULL)
        {
            printf("Out of space!!!");
            exit(EXIT_FAILURE);
        }

        tmp->Coefficient = *(C + i);
        tmp->Exponent = *(E + i);
        tmp->Next = NULL;
        tmp->Previous = P;

        P->Next = tmp;
        P = P->Next; //更新链表结尾标志位
    }
}

BigInt BigIntAdd(BigInt BI1, BigInt BI2)
{
    BigInt BI = (BigInt)malloc(sizeof(struct Node));
    BI->Next = NULL;

    Position P1 = BI1->Next;
    Position P2 = BI2->Next;
    Position P = BI;

    while (P1 != NULL && P2 != NULL)
    {
        if (P1->Exponent < P2->Exponent)
        {
            Insert(P2->Coefficient, P2->Exponent, BI, P);
            P2 = P2->Next;
        }
        else if (P1->Exponent > P2->Exponent)
        {
            Insert(P1->Coefficient, P1->Exponent, BI, P);
            P1 = P1->Next;
        }
        else
        {
            Insert(P1->Coefficient + P2->Coefficient, P1->Exponent, BI, P);
            P1 = P1->Next;
            P2 = P2->Next;
        }
        P = P->Next;
    }

    while (P1 != NULL)
    {
        Insert(P1->Coefficient, P1->Exponent, BI, P);
        P1 = P1->Next;
        P = P->Next;
    }

    while (P2 != NULL)
    {
        Insert(P2->Coefficient, P2->Exponent, BI, P);
        P2 = P2->Next;
        P = P->Next;
    }

    FormatBigInt(BI);

    return BI;
}

BigInt BigIntMulti(BigInt BI1, BigInt BI2)
{
    BigInt BI = (BigInt)malloc(sizeof(struct Node));
    BI->Next = NULL;

    Position P1 = BI1->Next;
    Position P2 = BI2->Next;

    while (P1 != NULL)
    {
        BigInt TMP = (BigInt)malloc(sizeof(struct Node));
        TMP->Next = NULL;
        Position TMPP = TMP;
        BigInt BIadd = BI;

        while (P2 != NULL)
        {
            Insert(P1->Coefficient * P2->Coefficient, P1->Exponent + P2->Exponent, TMP, TMPP);
            TMPP = TMPP->Next;
            P2 = P2->Next;
        }

        BI = BigIntAdd(BIadd, TMP);
        P1 = P1->Next;
        P2 = BI2->Next;
        DeleteBigInt(TMP);
        DeleteBigInt(BIadd);
        FormatBigInt(BI);
    }

    return BI;
}

void FormatBigInt(BigInt BI)
{
    // go from the end of the list, carry the digits
    Position P = BI;
    while (!IsLast(P, BI))
        P = P->Next;

    // now P is the last node
    while (P->Previous != BI)
    {
        if (P->Coefficient >= 10 && P->Previous->Exponent > P->Exponent + 1)
            Insert(0, P->Exponent + 1, BI, P->Previous);
        P->Previous->Coefficient += P->Coefficient / 10;
        P->Coefficient %= 10;
        P = P->Previous;
    }

    // deal with the first digit
    if (P->Coefficient >= 10)
    {
        Insert(0, P->Exponent + 1, BI, P->Previous);
        P->Previous->Coefficient += P->Coefficient / 10;
        P->Coefficient %= 10;
    }
}

void CountDigits(BigInt BI, int* counts)
{
    Position P = BI->Next;
    while (P != NULL)
    {
        *(counts + P->Coefficient) += 1; //根据系数获取偏移量
        P = P->Next;
    }
}

unsigned Length(BigInt BI)
{
    Position P = BI->Next;
    unsigned int len = 1;
    while (!IsLast(P, BI))
    {
	    P = P->Next;
        ++len;
    }

    return len;
}

void DeleteBigInt(BigInt BI)
{
    Position P, tmp;
    P = BI->Next;
    BI->Next = NULL;
    while (P != NULL)
    {
        tmp = P->Next;
        free(P);
        P = tmp;
    }
} 