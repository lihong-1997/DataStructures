#ifndef _QUEUE_H
#define _QUEUE_H

struct QueueRecord;
typedef struct QueueRecord* Queue;

int IsEmpty(Queue Q);
int IsFull(Queue Q);

Queue CreateQueue(int MaxElements);
void MakeEmpty(Queue Q);
void DisposeQueue(Queue Q);

void Enqueue(int X, Queue Q);
void Dequeue(Queue Q);
int FrontElement(Queue Q);

#endif
