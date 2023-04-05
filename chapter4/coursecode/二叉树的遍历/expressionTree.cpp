#include "binarytree.h"
#include <iostream>

/*
 * 后缀转表达式树：
 * 与通过栈计算后缀表达式类似。
 * 从左至右读后缀表达式
 * 是操作数，创建单节点树（树叶类型），将指向它的指针压入栈
 * 是操作符，创建单节点树，right为栈pop的第一个元素，left为pop的第二个元素
 * 循环结束弹出栈中唯一指针，即为root指针
 */
TreeNode<char>* expressionTree(const char* A, int N)
{
	std::stack<TreeNode<char>* > s;

	for (int i = 0; i < N; ++i)
	{
		if (A[i] != '+' && A[i] != '*')
		{
			TreeNode<char>* numNode = CreateNode(A[i]);
			s.emplace(numNode);
		}
		else
		{
			TreeNode<char>* rightNode = s.top();
			s.pop();
			TreeNode<char>* leftNode = s.top();
			s.pop();

			TreeNode<char>* opNode = CreateNode(A[i]);
			opNode->left = leftNode;
			opNode->right = rightNode;
			s.emplace(opNode);
		}
	}

	TreeNode<char>* root = s.top();
	s.pop();

	return root;
}

/*
 * 通过中序遍历树，并添加括号，使得后缀表达式转中缀表达式
 */
void TreeToInfix(TreeNode<char>* root, std::string& res )
{
	if (root)
	{
		if (root->left) res.push_back('(');
		TreeToInfix(root->left, res);
		res.push_back(root->val);
		TreeToInfix(root->right, res);
		if (root->right) res.push_back(')');
	}

}


//将后缀表达式转为表达式树，借助表达式树的中序遍历，即可得到中缀表达式
std::string PostToInfix(TreeNode<char>* root, const std::string& post)
{
	std::string res;

	TreeToInfix(root, res);

	return res;
}


//递归计算表达式树的值
int calculate_expressionTree(const TreeNode<char>* root)
{
	//若为树叶，则将其转化为整数类型，并返回
	if (root->left == nullptr && root->right == nullptr) {
		return (int)(root->val) - 48;
	}

	int leftValue = calculate_expressionTree(root->left);
	int rightValue = calculate_expressionTree(root->right);

	switch (root->val) {
	case '+':
		return leftValue + rightValue;
	case '-':
		return leftValue - rightValue;
	case '*':
		return leftValue * rightValue;
	//case '/':
		//return leftValue / rightValue;
	default:
		return 0;
	}
}

int main2()
{
	std::string postEx("123*+45*3+2*+"); //53
	TreeNode<char>* root = expressionTree(postEx.data(), (int)postEx.size());

	std::string infixEx = PostToInfix(root, postEx);
	std::cout << "infix expression:";
	for (const char i : infixEx)
		std::cout << i;

	int value = calculate_expressionTree(root);
	std::cout << "\n" << "expression value:" << value;

	return 0;
}