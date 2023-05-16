#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <sstream>

/*
*	一个10*9的棋盘，棋子“马”起始点在(0,0)运行k步到目标坐标(x,y)有多少种方法
*	马走日
*/ 

// 暴力求解

int process_01(int x,int y,int k,int a, int  b)
{
	if (x < 0 || x > 9 || y < 0 || y > 8)
	{
		return 0;
	}
	if (k == 0)
	{
		return x == a && y == b;
	}

	int ways = process_01(x + 2, y + 1, k - 1, a, b);
	ways += process_01(x + 1, y + 2, k - 1, a, b);
	ways += process_01(x - 1, y + 2, k - 1, a, b);
	ways += process_01(x - 2, y + 1, k - 1, a, b);
	ways += process_01(x - 2, y - 1, k - 1, a, b);
	ways += process_01(x - 1, y - 2, k - 1, a, b);
	ways += process_01(x + 1, y - 2, k - 1, a, b);
	ways += process_01(x + 2, y - 1, k - 1, a, b);
	return ways;
}

int Ways_01(int a,int b,int k)
{
	if (a < 0 || a > 9 || b < 0 || b > 8)
	{
		return 0;
	}
	return process_01(0, 0, k, a, b);
}

int pick(int x, int y, int k, std::vector<std::vector<std::vector<int>>>& dp)
{
	if (x < 0 || x > 9 || y < 0 || y > 8)
	{
		return 0;
	}
	return dp[x][y][k];
}

int Ways_02(int a, int b, int k)
{
	if (a < 0 || a > 9 || b < 0 || b > 8)
	{
		return 0;
	}

	std::vector<std::vector<std::vector<int>>> dp(10, 
		std::vector<std::vector<int>>(9, 
			std::vector<int>(k + 1, 0)));

	dp[a][b][0] = 1;
	for (int rest = 1; rest <= k; rest++)
	{
		for (int x = 0; x < 10; x++)
		{
			for (int y = 0; y < 9; y++)
			{
				int ways = pick(x + 2, y + 1, rest - 1, dp);
				ways += pick(x + 1, y + 2, rest - 1, dp);
				ways += pick(x - 1, y + 2, rest - 1, dp);
				ways += pick(x - 2, y + 1, rest - 1, dp);
				ways += pick(x - 2, y - 1, rest - 1, dp);
				ways += pick(x - 1, y - 2, rest - 1, dp);
				ways += pick(x + 1, y - 2, rest - 1, dp);
				ways += pick(x + 2, y - 1, rest - 1, dp);
				dp[x][y][rest] = ways;
			}
		}
	}

	return dp[0][0][k];
}

int main()
{
	std::cout << Ways_01(7, 7, 10) << std::endl;
	std::cout << Ways_02(7, 7, 10) << std::endl;
	return 0;
}