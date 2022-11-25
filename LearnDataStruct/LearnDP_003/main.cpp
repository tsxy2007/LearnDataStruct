#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <sstream>

/*
*	背包问题：现在有四件商品，
*	分别为音响3000美元重四磅，笔记本电脑2000美元重三磅，吉他1500美元一磅，iphone2000美元一磅
*	现在假设你有一个可以装下四磅的物品，在上面提供的物品中如何是装下的物品价值最大，
*	简单的算法就是尝试各种商品组合，并找出价值最高的组合。	
*/ 

// 暴力求解

int process_01(int Index, std::vector<int>& widgets, std::vector<int>& values, int bag)
{
	if (bag < 0)
	{
		return -1;
	}
	if (Index>= widgets.size())
	{
		return 0;
	}

	// 不使用当前
	int value1 = process_01(Index + 1, widgets, values, bag);
	int value2 = 0;
	int nextValue = process_01(Index + 1, widgets, values, bag - widgets[Index]);
	if (nextValue != -1)
	{
		value2 = values[Index] + nextValue;
	}

	return std::max(value1, value2);
}

int maxValue_01(std::vector<int>& widgets, std::vector<int>& values, int bag)
{
	if (widgets.empty()||values.empty()||widgets.size()!= values.size()||bag == 0)
	{
		return 0;
	}
	return process_01(0, widgets, values, bag);
}

// 优化二:缓存
int process_02(int Index, std::vector<int>& widgets, std::vector<int>& values, int bag, std::vector<std::vector<int>>& dp)
{
	if (bag < 0)
	{
		return -1;
	}
	if (dp[Index][bag]!=-2)
	{
		return dp[Index][bag];
	}

	int ras = 0;
	if (Index >= widgets.size())
	{
		ras = 0;
	}
	else
	{
		// 不使用当前
		int value1 = process_02(Index + 1, widgets, values, bag,dp);
		int value2 = 0;
		int nextValue = process_02(Index + 1, widgets, values, bag - widgets[Index],dp);
		if (nextValue != -1)
		{
			value2 = values[Index] + nextValue;
		}

		ras = std::max(value1, value2);
	}
	dp[Index][bag] = ras;
	return ras;
}

int maxValue_02(std::vector<int>& widgets, std::vector<int>& values, int bag)
{
	if (widgets.empty() || values.empty() || widgets.size() != values.size() || bag == 0)
	{
		return 0;
	}
	std::vector<std::vector<int>> dp(values.size()+1, std::vector<int>(bag+1, -2));
	process_02(0, widgets, values, bag, dp);

	//for (size_t i = 0; i < dp.size(); i++)
	//{
	//	auto& tmp = dp[i];
	//	for (size_t j = 0; j < tmp.size(); j++)
	//	{
	//		std::cout << "bag[" << i << "]" << "[" << j << "]: " << tmp[j] << '	';
	//	}
	//	std::cout << std::endl;
	//}

	return dp[0][bag];
}

// 动态规划终极

int maxValue_03(std::vector<int>& widgets, std::vector<int>& values, int bag)
{
	if (widgets.empty() || values.empty() || widgets.size() != values.size() || bag == 0)
	{
		return 0;
	}
	std::vector<std::vector<int>> dp(values.size() + 1, std::vector<int>(bag + 1, 0));
	for (int i = values.size() - 1; i >= 0; i--)
	{
		for (int rest = 0; rest < bag+1; rest++)
		{

			int value1 = dp[i + 1][rest];
			int value2 = 0;
			int nextValue = (rest - widgets[i] < 0) ? -1 : dp[i + 1][rest - widgets[i]];
			if (nextValue != -1)
			{
				value2 = values[i] + nextValue;
			}
			dp[i][rest] = std::max(value1, value2);
		}
	}

	return dp[0][bag];
}

int main()
{
	std::vector<int> widgets{ 4,3,1,1 };
	std::vector<int> values{ 3000,2000,1500,2000 };
	int bag = 4;

	std::cout << maxValue_01(widgets, values, 4) << std::endl;
	std::cout << maxValue_02(widgets, values, 4) << std::endl;
	std::cout << maxValue_03(widgets, values, 4) << std::endl;

	
	
	return 0;
}