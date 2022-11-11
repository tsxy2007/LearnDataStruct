#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <sstream>

/*
*	给你一个二叉树的根节点 root ， 检查它是否轴对称。
*/ 

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};
// 方法一: 递归
bool isSymmetric(TreeNode* leftNode, TreeNode* rightNode)
{
	if (leftNode == nullptr&&rightNode==nullptr)
	{
		return true;
	}
	if (leftNode != nullptr && rightNode == nullptr)
	{
		return false;
	}
	if (leftNode == nullptr && rightNode != nullptr)
	{
		return false;
	}
	return leftNode->val == rightNode->val && 
		isSymmetric(leftNode->left, rightNode->right) && 
		isSymmetric(leftNode->right, rightNode->left);
}

bool isSymmetric(TreeNode* root)
{
	if (!root)
	{
		return true;
	}
	return isSymmetric(root->left, root->right);
}

// 普通循环方法

bool isSymmetric_01(TreeNode* root)
{
	TreeNode* l = root->left;
	TreeNode* r = root->right;
	if (!root||(!l&&!r))
	{
		return true;
	}
	std::deque<TreeNode*> tmp;
	tmp.push_back(l);
	tmp.push_back(r);
	while (!tmp.empty())
	{
		l = tmp.front();
		tmp.pop_front();
		r = tmp.front();
		tmp.pop_front();
		if (!l&&r)
		{
			return false;
		}
		if (l&&!r)
		{
			return false;
		}
		if (!l&&!r)
		{
			continue;
		}
		if (l->val != r->val)
		{
			return false;
		}
		tmp.push_back(l->left);
		tmp.push_back(r->right);

		tmp.push_back(l->right);
		tmp.push_back(r->left);
	}
	return true;
}

int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* node1 = new TreeNode(2);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(3);
	root->right = node1;
	root->left = node2;
	node1->right = node3;
	node2->left = node4;

	bool bSymmetric = isSymmetric(root);
	bool bSymmetric_01 = isSymmetric_01(root);
	std::cout << "是否是对称树 = " << bSymmetric << std::endl;
	std::cout << "是否是对称树 = " << bSymmetric_01 << std::endl;
	return 0;
}