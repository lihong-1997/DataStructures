#ifndef _QUEUESPLAY_H
#define _QUEUESPLAY_H

#include "splaytree.h"

struct QueueRecord;
typedef struct QueueRecord* Queue;

typedef struct SplayNode* elemType;

int IsQueueEmpty(Queue Q);
int IsQueueFull(Queue Q);

Queue CreateQueue(int MaxElements);
void MakeEmptyQueue(Queue Q);
void DisposeQueue(Queue Q);

void Enqueue(elemType X, Queue Q);
void Dequeue(Queue Q);

int QueueSize(Queue Q);
elemType FrontElement(Queue Q);

#endif