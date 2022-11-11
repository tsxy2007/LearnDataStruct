#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <sstream>

/*
*	给定一个二叉树，找出其最大深度。
*	二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
*	说明: 叶子节点是指没有子节点的节点。
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


int maxDepth(TreeNode* root)
{
	if (!root)
	{
		return 0;
	}
	return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
}

// 普通循环方法
int maxDepth_01(TreeNode* root)
{
	if (!root)
	{
		return 0;
	}

	int result = 1;
	std::deque<TreeNode*> nodes;
	nodes.push_back(root->left);
	nodes.push_back(root->right);
	while (!nodes.empty())
	{
		result += 1;
		int elementCout = nodes.size();
		while (elementCout)
		{
			TreeNode* tNode = nodes.front();
			if (tNode->left)
			{
				nodes.push_back(tNode->left);
			}
			if (tNode->right)
			{
				nodes.push_back(tNode->right);
			}
			elementCout--; 
			nodes.pop_front();
		}
	}
	return result;
}

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
	node4->left = node5;

	int depth = maxDepth(root);
	int depth_01 = maxDepth_01(root);
	std::cout << "层高 = " << depth << std::endl;
	std::cout << "层高 = " << depth_01 << std::endl;
	return 0;
}