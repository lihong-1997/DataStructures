#ifndef BINARYTREE_H
#define BINARYTREE_H

#define ElementType int

struct TreeNode;
typedef struct TreeNode* BinaryTree;
typedef struct TreeNode* Position;

struct TreeNode
{
    ElementType Element;
    BinaryTree Left;
    BinaryTree Right;
}*root1,*root2,*root3;

BinaryTree CreateNode(ElementType X);
void PreOrderTraversal(BinaryTree T);
int isIsomorphic(BinaryTree T1, BinaryTree T2);

#endif