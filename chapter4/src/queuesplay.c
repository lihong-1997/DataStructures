#include "queuesplay.h"
#include <stdio.h>
#include <stdlib.h>

#define MinQueueSize (5)
struct QueueRecord
{
	int Capacity;
	int Size;
	int Front;
	int Rear;
	elemType* Array;
};

int IsQueueEmpty(Queue Q)
{
	return Q->Size == 0;
}

int IsQueueFull(Queue Q)
{
	return Q->Size == Q->Capacity;
}

int QueueSize(Queue Q)
{
    return Q->Size;
}

void MakeEmptyQueue(Queue Q)
{
	Q->Size = 0;
	Q->Front = 1;
	Q->Rear = 0;
}

Queue CreateQueue(int MaxElements)
{
	if (MaxElements < MinQueueSize)
	{
		printf("Queue size is too small");
		return NULL;
	}
	Queue Q;
	Q = malloc(sizeof(struct QueueRecord));
	if (Q == NULL)
	{
		printf("fail to create queue");
		return NULL;
	}
	Q->Array = malloc(sizeof(elemType) * MaxElements);
	if (Q->Array == NULL)
	{
		printf("fail to create queue");
		return NULL;
	}
	Q->Capacity = MaxElements;
	MakeEmptyQueue(Q);

	return Q;
}

static int Succ(int value, Queue Q)
{
	if (++value == Q->Capacity)
		value = 0;
	return value;
}

void Enqueue(elemType X, Queue Q)
{
	if (IsQueueFull(Q))
		printf("Full Queue");
	else
	{
		Q->Size++;
		Q->Rear = Succ(Q->Rear, Q);
		Q->Array[Q->Rear] = X;
	}
}

void Dequeue(Queue Q)
{
	if (IsQueueEmpty(Q))
		printf("Empty Queue");
	else
	{
		Q->Size--;
		Q->Front = Succ(Q->Front, Q);
	}
}

elemType FrontElement(Queue Q)
{
	if (!IsQueueEmpty(Q))
		return Q->Array[Q->Front];
	printf("empty");
	return 0;
}

void DisposeQueue(Queue Q)
{
	if (Q != NULL)
	{
		free(Q->Array);
		free(Q);
	}
}