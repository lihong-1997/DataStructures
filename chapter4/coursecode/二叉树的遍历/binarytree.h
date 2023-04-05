#ifndef BINARYTREE_H
#define BINARYTREE_H

#include <stack>
#include <queue>
#include <iostream>

template <class T>
struct TreeNode
{
	T val;
	TreeNode<T>* left;
	TreeNode<T>* right;
	TreeNode<T>(T x) : val(x), left(nullptr), right(nullptr) {}
};

template <class T>
TreeNode<T>* CreateNode(T val_)
{
    TreeNode<T>* treeNode = new TreeNode<T>(val_);
    if (treeNode == nullptr)
    {
        std::cout << "out of space" << std::endl;
        return nullptr;
    }
    treeNode->val = val_;

    return treeNode;
}


//先序遍历递归版
template <class T>
void PreOrderTraversal_Recursion(TreeNode<T>* root)
{
    if (root)
    {
		std::cout << root->val << " ";
        PreOrderTraversal_Recursion(root->left);
        PreOrderTraversal_Recursion(root->right);
    }
}

//先序遍历非递归版
template <class T>
void PreOrderTraversal(TreeNode<T>* root)
{
    if (!root) return;

    TreeNode<T>* treeNode = root;
    std::stack<TreeNode<T>*> s;

    while (treeNode || !s.empty())
    {
	    while (treeNode)
	    {
            s.emplace(treeNode);
            std::cout << treeNode->val << " ";
            treeNode = treeNode->left;
	    }
	    if (!s.empty())
	    {
            treeNode = s.top();
            s.pop();
            treeNode = treeNode->right;
	    }
    }
    std::cout << std::endl;
}

//中序遍历递归版
template <class T>
void InOrderTraversal_Recursion(TreeNode<T>* root)
{
    if (root)
    {
        InOrderTraversal_Recursion(root->left);
		std::cout << root->val << " ";
        InOrderTraversal_Recursion(root->right);
    }
}

//中序遍历非递归版
template <class T>
void InOrderTraversal(TreeNode<T>* root)
{
    if (!root) return;

    TreeNode<T>* treeNode = root;
    std::stack<TreeNode<T>*> s;

    while (treeNode || !s.empty())
    {
	    while (treeNode)
	    {
            s.emplace(treeNode);
            treeNode = treeNode->left;
	    }//左子树遍历结束
	    if (!s.empty())
	    {
            //从栈顶弹出节点，打印该节点，然后遍历右子树
            treeNode = s.top();
            s.pop();
            std::cout << treeNode->val << " ";
            treeNode = treeNode->right;
	    }
    }
    std::cout << std::endl;
}



//后序遍历递归版
template <class T>
void PostOrderTraversal_Recursion(TreeNode<T>* root)
{
	if (root)
	{
        PostOrderTraversal_Recursion(root->left);
        PostOrderTraversal_Recursion(root->right);
        std::cout << root->val << " ";
	}
}

//后序遍历非递归版
template <class T>
void PostOrderTraversal(TreeNode<T>* root) {
    if (!root) return;

    std::stack<TreeNode<T>* > s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        TreeNode<T>* node = s1.top();
        s1.pop();
        s2.push(node);
        if (node->left) s1.push(node->left);
        if (node->right) s1.push(node->right);
    }
    while (!s2.empty()) {
        TreeNode<T>* node = s2.top();
        s2.pop();
        std::cout << node->val << " ";
    }
    std::cout << std::endl;
}

//层序遍历
template <class T>
void LevelOrderTraversal(TreeNode<T>* root)
{
    if (!root) return;

    std::queue<TreeNode<T>* > Q;
    TreeNode<T>* tNode = root;
    Q.push(tNode);

    while (!Q.empty())
    {
        tNode = Q.front();
        std::cout << tNode->val << " ";
        Q.pop();
        if (tNode->left) Q.push(tNode->left);
        if (tNode->right) Q.push(tNode->right);
    }
}

//输出二叉树的叶子节点
template <class T>
void PreOrderPrintLeaves(TreeNode<T>* root)
{
    if (root)
    {
        if (!root->left && !root->right)
			std::cout << root->val << " ";
        PreOrderPrintLeaves(root->left);
        PreOrderPrintLeaves(root->right);
    }
}

//输出二叉树高度
template <class T>
int Height(TreeNode<T>* root)
{
    int HL, HR, MaxH;
    if (root)
    {
        HL = Height(root->left);
        HR = Height(root->right);
        MaxH = (HL > HR) ? HL : HR;
        return 1 + MaxH;
    }
    else
        return 0;
}

//先序和中序遍历序列确定二叉树
template <class T>
TreeNode<T>* BuildTree(std::vector<T>& pre, std::vector<T>& in)
{
    //确保遍历序列非空，且作为递归基准情形
    if (pre.empty() || in.empty()) return nullptr;

    //先序序列第一个值为根节点值，创建根节点
    T rootVal = pre[0];
    TreeNode<T>* root = new TreeNode<T>(rootVal);

    //由根节点值，在中序序列中获得左子树右子树节点个数
	int index = 0; 
    for (;index < in.size();index++)
        if (in[index] == rootVal) break;
    //构造前序序列中的左右子树
    std::vector<T> leftChildTree_pre(pre.begin() + 1, pre.begin() + 1 + index);
    std::vector<T> rightChildTree_pre(pre.begin() + 1 + index, pre.end());
    //构造中序序列中的左右子树
    std::vector<T> leftChildTree_in(in.begin(), in.begin() + index);
    std::vector<T> rightChildTree_in(in.begin() + index + 1, in.end());

	//前序的左子树序列与中序的左子树序列
    root->left = BuildTree(leftChildTree_pre, leftChildTree_in);
    //前序的右子树序列与中序的右子树序列
    root->right = BuildTree(rightChildTree_pre, rightChildTree_in);

    return root;
}

//先序遍历递归版求节点左右儿子
template <class T>
void PreOrderGetChild(TreeNode<T>* root)
{
    if (root)
    {
        T lChild = (root->left) ? (root->left->val) : '-';
        T rChild = (root->right) ? (root->right->val) : '-';
        std::cout << root->val << ":" << lChild << rChild << '\n';

        PreOrderGetChild(root->left);
        PreOrderGetChild(root->right);
    }
}

//判断两棵树是否同构
template <class T>
bool isIsomorphic(TreeNode<T>* root1, TreeNode<T>* root2) {
    if (!root1 && !root2) return true; //两节点都没子树
    if (!root1 || !root2) return false; //两节点其中一个没子树
    if (root1->val != root2->val) return false; //两节点都有子树，判断子树根节点值
    return (isIsomorphic(root1->left, root2->left) && isIsomorphic(root1->right, root2->right)) ||
        (isIsomorphic(root1->left, root2->right) && isIsomorphic(root1->right, root2->left));
}

#endif
