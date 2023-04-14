#ifndef BASE_H
#define BASE_H

#include <stdio.h>
#include <stdlib.h>

#define Error(str) FatalError(str)
#define FatalError(str) fprintf(stderr, "%s\n", str), exit(1)

#define ElementType int


void Swap(ElementType* val1, ElementType* val2);
void Print(ElementType A[], int N);

void Bubble_Sort(ElementType A[], int N);

void Insertion_Sort(ElementType A[], int N);

void Shell_Sort(ElementType A[], int N);

void Heap_Sort(ElementType A[], int N);

void Merge_Sort(ElementType A[], int N);

void Quick_Sort(ElementType A[], int N);

#endif