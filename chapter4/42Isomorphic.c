#include "binarytree.h"
#include <stdio.h>

int main()
{
    BinaryTree root1;
    root1 = CreateNode('A');
	root1->Left = CreateNode('B');
    root1->Left->Left = CreateNode('D');
    root1->Left->Right = CreateNode('E');
    root1->Left->Right->Left = CreateNode('F');
    root1->Right = CreateNode('C');
    root1->Right->Left = CreateNode('G');
    root1->Right->Left->Left = CreateNode('H');

    BinaryTree root2 = CreateNode('A');
    root2->Left = CreateNode('C');
    root2->Left->Left = CreateNode('G');
    root2->Left->Left->Right = CreateNode('H');
    root2->Right = CreateNode('B');
    root2->Right->Left = CreateNode('E');
    root2->Right->Right = CreateNode('D');
    root2->Right->Left->Left = CreateNode('F');

    BinaryTree root3 = CreateNode('A');
    root3->Left = CreateNode('B');
    root3->Left->Left = CreateNode('G');
    root3->Left->Left->Right = CreateNode('H');
    root3->Right = CreateNode('C');
    root3->Right->Right = CreateNode('E');
    root3->Right->Left = CreateNode('D');
    root3->Right->Left->Left = CreateNode('F');

    PreOrderTraversal(root1);
    return 0;
}