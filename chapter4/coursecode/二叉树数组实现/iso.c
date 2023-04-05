#include "binarytree.h"
#include <stdio.h>
#include <string.h>

int main()
{
	Tree r1, r2;
	r1 = BuildTree(T1, "tree1.txt");
	r2 = BuildTree(T2, "tree1.txt");
	//Traversal(T1, 8, r1);
	int Iso = Isomorphic(r1, r2);
	printf("%d", Iso);
	return 0;
}
