#ifndef BINARYTREE_H
#define BINARYTREE_H

#define _CRT_SECURE_NO_WARNINGS 1

#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
#include <stdio.h>

struct TreeNode
{
	ElementType Element;
	Tree Left;
	Tree Right;
}T1[MaxTree], T2[MaxTree];

//Tree BuildTree(struct TreeNode T[])
//{
//	int N; //节点个数
//	int root = Null;
//	scanf("%d", &N);
//	char cl, cr;
//	int check[MaxTree]; //用于检测root
//	if (N)
//	{
//		for (int i = 0; i < N; ++i)
//			check[i] = 0;
//		for (int i = 0; i < N; ++i)
//		{
//			printf("%d:", i);
//			scanf("%c %c %c", &T[i].Element, &cl, &cr);
//			if (cl != '-')
//			{
//				T[i].Left = cl - '0';
//				check[T[i].Left] = 1;
//			}
//			else
//				T[i].Left = Null;
//
//			if (cr != '-')
//			{
//				T[i].Right = cr - '0';
//				check[T[i].Right] = 1;
//			}
//			else
//				T[i].Right = Null;
//		}
//
//		int index;
//		for (index = 0; index < N; ++index)
//			if (!check[index]) break;
//		root = index;
//	}
//	return root;
//}

Tree BuildTree(struct TreeNode T[], char* TXT)
{
	FILE* fp;
	char line[100];
	fp = fopen(TXT, "r");
	if (fp == NULL) {
		printf("Error opening file\n");
		return 1;
	}
	
	int N; //节点个数
	int root = Null;
	char cl, cr;
	int check[MaxTree]; //用于检测root

	fgets(line, 100, fp);
	N = line[0] - '0';
	if (N)
	{
		for (int i = 0; i < N; ++i)
			check[i] = 0;
		for (int i = 0; i < N; ++i)
		{
			fgets(line, 100, fp);
			T[i].Element = line[0];
			cl = line[2];
			cr = line[4];
			if (cl != '-')
			{
				T[i].Left = cl - '0';
				check[T[i].Left] = 1;
			}
			else
				T[i].Left = Null;

			if (cr != '-')
			{
				T[i].Right = cr - '0';
				check[T[i].Right] = 1;
			}
			else
				T[i].Right = Null;
		}

		int index;
		for (index = 0; index < N; ++index)
			if (!check[index]) break;
		root = index;
	}
	return root;
}

int Isomorphic(Tree r1, Tree r2)
{
	if ((r1 == Null) && (r2 == Null)) return 1; 
	if ((r1 == Null) || (r2 == Null)) return 0;
	if (T1[r1].Element != T2[r2].Element) return 0;
	return ((Isomorphic(T1[r1].Left, T2[r2].Left) && Isomorphic(T1[r1].Right, T2[r2].Right)) 
		|| (Isomorphic(T1[r1].Left, T2[r2].Right) && Isomorphic(T1[r1].Right, T2[r2].Left)));
}

void Traversal(struct TreeNode T[], int N, Tree Node)
{
	for (int i = 0; i < N; ++i)
		printf("%d:%c %d %d\n", i, T[i].Element, T[i].Left, T[i].Right);
	
}
#endif
