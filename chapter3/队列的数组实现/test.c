/*
 * 队列的循环数组实现，使用size判断队列是否满
 */
#include "queue.h"
#include <stdio.h>

int main()
{
	Queue Q;
	Q = CreateQueue(5);
	int isempty = IsEmpty(Q);
	printf("is empty:%d\n", isempty);
	Enqueue(1, Q);
	Enqueue(2, Q);
	Enqueue(3, Q);
	Enqueue(4, Q);
	Enqueue(5, Q);
	int isfull = IsFull(Q);
	printf("is full:%d\n", isfull);
	Dequeue(Q);
	Dequeue(Q);
	Dequeue(Q);
	Dequeue(Q);
	Enqueue(-1, Q);
	Enqueue(-2, Q);
	Enqueue(-3, Q);

	int frontValue = FrontElement(Q);
	printf("front:%d\n", frontValue);
}