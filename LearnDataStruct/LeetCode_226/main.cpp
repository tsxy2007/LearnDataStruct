#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <sstream>

/*
*	反转树给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
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

TreeNode* invertTree(TreeNode* root)
{
	if (!root)
		return root;
	invertTree(root->right);
	invertTree(root->left);
	TreeNode* tmp = root->right;
	root->right = root->left;
	root->left = tmp;
	return root;
}

int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* node1 = new TreeNode(2);
	TreeNode* node2 = new TreeNode(-2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(-3);
	root->right = node1;
	root->left = node2;
	node1->right = node3;
	node2->left = node4;
	//node4->left = node5;

	invertTree(root);

	return 0;
}