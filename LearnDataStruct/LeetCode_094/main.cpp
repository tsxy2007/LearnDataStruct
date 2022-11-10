#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <sstream>

/*
*	给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。
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

void inorderTraversal(TreeNode* root, std::vector<int>& OutResult)
{
	if (!root)
		return;
	inorderTraversal(root->left, OutResult);
	OutResult.push_back(root->val);
	inorderTraversal(root->right, OutResult);
}

std::vector<int> inorderTraversal(TreeNode* root)
{
	std::vector<int> result;
	inorderTraversal(root, result);
	return result;
}


std::vector<int> inorderTraversal_01(TreeNode* root)
{
	std::vector<int> result;
	std::stack<TreeNode*> stack;
	while (root!= nullptr ||!stack.empty())
	{
		while (root)
		{
			stack.push(root);
			root = root->left;
		}
		root = stack.top();
		result.push_back(root->val);
		root = root->right;
		stack.pop();
	}


	return result;
}

int main()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* node1 = new TreeNode(2);
	TreeNode* node2 = new TreeNode(3);
	root->right = node1;
	node1->left = node2;

	std::vector<int> result = inorderTraversal_01(root);

	for (size_t i = 0; i < result.size(); i++)
	{
		std::cout << result[i] << " ";
	}
	std::cout << std::endl;
	return 0;
}