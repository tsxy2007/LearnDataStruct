#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/*
*	给你一个整数 n ，对于 0 <= i <= n 中的每个 i ，
*	计算其二进制表示中 1 的个数 ，返回一个长度为 n + 1 
*	的数组 ans 作为答案。
*/ 

std::vector<int> countBits(int n)
{
	std::vector<int> result(n+1,0);
	for (size_t i = 1; i <= n; i++)
	{
		result[i] = result[i & (i - 1)] + 1;
		//result[i] = __builtin_popcount(i);
	}
	return result;
}

void print(const std::vector<int>& result01)
{
	for (int i = 0; i < result01.size(); i++)
	{
		std::cout << result01[i] << ' ';
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> nums = countBits(5);
	print(nums);
	return 0;
}