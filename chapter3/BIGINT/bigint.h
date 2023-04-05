/*
 *解决进位时前一项指针的记录问题的方法有:
 *1.编写 FindPrevious 函数，时间复杂度较大；
 *2.改成链表从小到大记录，简单直接，但是若在题目要求之外需要从大到小打印，可能存在递归栈溢出的风险；
 *3.将单链表改成双链表(采用)。
 */

#ifndef BIGINT_H
#define BIGINT
#include <stdio.h>
#include <stdlib.h>

struct Node;

typedef struct Node* PtrToNode;
struct Node
{
	int Coefficient;
	int Exponent;
	PtrToNode Previous;
	PtrToNode Next;
};
typedef PtrToNode BigInt;
typedef PtrToNode Position;

int IsLast(Position P, BigInt BI);
void Insert(int c, int e, BigInt BI, Position P);
void PrintBigInt(BigInt BI);
void BigIntConstructor(int* C, int* E, int N, BigInt BI);
BigInt BigIntAdd(BigInt BI1, BigInt BI2);
BigInt BigIntMulti(BigInt BI1, BigInt BI2);
void FormatBigInt(BigInt BI);
void CountDigits(BigInt BI, int* counts); //计算0-9出现频率
void DeleteBigInt(BigInt BI);
unsigned Length(BigInt BI);


#endif
