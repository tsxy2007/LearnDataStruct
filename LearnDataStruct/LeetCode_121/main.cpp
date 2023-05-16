#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <sstream>

/*
*	给定一个数组 prices ，
*	它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
*	你只能选择 某一天 买入这只股票，
*	并选择在 未来的某一个不同的日子 卖出该股票。
*	设计一个算法来计算你所能获取的最大利润。
*	返回你可以从这笔交易中获取的最大利润。
*	如果你不能获取任何利润，返回 0 。
*/ 

int process_01(int point, std::vector<int>& prices)
{
	if (point == prices.size() - 1)
	{
		return 0;
	}
	int nextIndex = point + 1;
	int max = prices[nextIndex] - prices[point];
	for (int i = point+1; i < prices.size(); i++)
	{
		int tmp = prices[i] - prices[point];
		max = std::max(tmp, max);
	}
	int nextMax = process_01(point + 1, prices);
	return std::max(max, nextMax);
}

int maxProfit_01(std::vector<int>& prices)
{
	if (prices.empty()||prices.size() == 1)
	{
		return 0;
	}
	return process_01(0, prices);
}


int process_02(int buy,int scale, std::vector<int>& prices)
{
	if (scale >= prices.size())
	{
		return 0;
	}
	if (buy == scale)
	{
		return 0;
	}

	int cur = prices[scale] - prices[buy];
	int cmax = std::max(cur, process_02(buy, scale + 1, prices));
	int nexMax = std::max(cmax, process_02(buy + 1, buy + 2, prices));
}

int maxProfit_02(std::vector<int>& prices)
{
	if (prices.empty() || prices.size() == 1)
	{
		return 0;
	}
	return process_02(0, 1, prices);
}


int maxProfit_03(std::vector<int>& prices)
{
	if (prices.empty() || prices.size() == 1)
	{
		return 0;
	}
	int N = prices.size();

	int max = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			int scale = prices[j] - prices[i];
			max = std::max(scale,max);
		}
	}


	return max;
}

int main()
{
	std::vector<int> prices{ 7,1,5,3,6,4 };
	std::cout << maxProfit_01(prices) << std::endl;
	std::cout << maxProfit_02(prices) << std::endl;
	std::cout << maxProfit_03(prices) << std::endl;
	return 0;
}