#include "binarytree.h"

int main()
{
    //TreeNode<char>* root = new TreeNode<char>('A');
    //root->left = new TreeNode<char>('B');
    //root->left->left = new TreeNode<char>('D');
    //root->left->right = new TreeNode<char>('F');
    //root->left->right->left = new TreeNode<char>('E');

    //root->right = new TreeNode<char>('C');
    //root->right->left = new TreeNode<char>('G');
    //root->right->right = new TreeNode<char>('I');
    //root->right->left->right = new TreeNode<char>('H');

    //std::cout << "先序遍历迭代：";
    //PreOrderTraversal(root);
    //std::cout << "先序遍历递归：";
    //PreOrderTraversal_Recursion(root);
    //std::cout << std::endl;

    //std::cout << "中序遍历迭代：";
    //InOrderTraversal(root);
    //std::cout << "中序遍历递归：";
    //InOrderTraversal_Recursion(root);
    //std::cout << std::endl;

    //std::cout << "后序遍历迭代：";
    //PostOrderTraversal(root);
    //std::cout << "后序遍历递归：";
    //PostOrderTraversal_Recursion(root);

    //std::cout << std::endl;
    //std::cout << "层序遍历迭代：";
    //LevelOrderTraversal(root);

    //std::cout << std::endl;
    //std::cout << "二叉树叶子";
    //PreOrderPrintLeaves(root);

    //std::cout << std::endl;
    //std::cout << "二叉树高度:" << Height(root);

    //std::cout << std::endl;
    //std::vector<char> PreOrder = { 'a','b','c','d','e','f','g','h','i','j' };
    //std::vector<char> InOrder = { 'c','b','e','d','a','h','g','i','j','f' };

    //TreeNode<char>* root0 = BuildTree(PreOrder, InOrder);
    //LevelOrderTraversal(root0); //a b f c d g e h i j

    //std::cout << std::endl;

    //判断树是否同构
    TreeNode<char>* root1 = CreateNode('A');
	root1->left = CreateNode('B');
    root1->left->left = CreateNode('D');
    root1->left->right = CreateNode('E');
    root1->left->right->left = CreateNode('F');
    root1->right = CreateNode('C');
    root1->right->left = CreateNode('G');
    root1->right->left->left = CreateNode('H');

    TreeNode<char>* root2 = CreateNode('A');
    root2->left = CreateNode('C');
    root2->left->left = CreateNode('G');
    root2->left->left->right = CreateNode('H');
    root2->right = CreateNode('B');
    root2->right->left = CreateNode('E');
    root2->right->right = CreateNode('D');
    root2->right->left->left = CreateNode('F');

    TreeNode<char>* root3 = CreateNode('A');
    root3->left = CreateNode('B');
    root3->left->left = CreateNode('G');
    root3->left->left->right = CreateNode('H');
    root3->right = CreateNode('C');
    root3->right->right = CreateNode('E');
    root3->right->left = CreateNode('D');
    root3->right->left->left = CreateNode('F');

    LevelOrderTraversal(root1);
    std::cout << std::endl;
    LevelOrderTraversal(root2);
    std::cout << std::endl;

    bool isIso1 = isIsomorphic(root1, root2);
    bool isIso2 = isIsomorphic(root1, root3);
    std::cout << "tree1 tree2 is isomorphic? " << isIso1 << "\n"
              << "tree1 tree3 is isomorphic? " << isIso2 << std::endl;

    PreOrderGetChild(root1);

    return 0;
}