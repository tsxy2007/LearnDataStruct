#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <sstream>

/*
*	给定一个二叉树，判断它是否是高度平衡的二叉树。
*	本题中，一棵高度平衡二叉树定义为：
*	一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。
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

int helper(TreeNode* root)
{
	if (!root)
	{
		return 0;
	}

	int rightcout = helper(root->right);
	int leftcout = helper(root->left);
	if (leftcout == -1 || rightcout == -1 || std::abs(leftcout - rightcout) > 1)
	{
		return -1;
	}
	return std::max(rightcout, leftcout) + 1;
}

bool isBalanced(TreeNode* root)
{
	if (!root)
	{
		return true;
	}
	return helper(root) != -1;
}

// 普通循环方法

int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* node1 = new TreeNode(2);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(3);
	TreeNode* node5 = new TreeNode(3);
	root->right = node1;
	root->left = node2;
	node1->right = node3;
	node2->left = node4;
	//node4->left = node5;

	std::cout << isBalanced(root) << std::endl;

	return 0;
}