#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <sstream>

/*
*	规定1和A对应、2和B对应、3和C对应...26和Z对应，
*	那么一个数字字符串比如"111”就可以转化为:"AAA"、"KA"和"AK"。
*	给定一个只有数字字符组成的字符串str，请问有多少种转化结果？
*/ 

// 暴力求解

int process_01(int Index, std::string& s)
{
	if (Index == s.size())
	{
		return 1;
	}

	if (s[Index] == '0')
	{
		return 0;
	}

	int ways = process_01(Index + 1, s);
	if (((Index + 1) < s.size()) && (((s[Index] - '0') * 10 + s[Index + 1] - '0') < 27))
	{
		ways += process_01(Index + 2, s);
	}
	return ways;
}

int maxValue_01(std::string& s)
{
	return process_01(0, s);
}

// 优化二: 提供存储

int process_02(int Index, std::string& s, std::vector<int>& dp)
{
	if (Index>=dp.size())
	{
		return 1;
	}
	if (dp[Index] != -1)
	{
		return dp[Index];
	}
	int ans = 0;
	if (Index == s.size())
	{
		ans = 1;
	}

	if (s[Index] != '0')
	{
		ans = process_02(Index + 1, s,dp);
		if (((Index + 1) < s.size()) && (((s[Index] - '0') * 10 + s[Index + 1] - '0') < 27))
		{
			ans += process_02(Index + 2, s,dp);
		}
	}
	dp[Index] = ans;
	return ans;
}

int maxValue_02(std::string& s)
{
	int N = s.size();
	std::vector<int> dp(N,-1);
	process_02(0, s, dp);
	return dp[0];
}

// 优化三: 直接一维数组

int maxValue_03(std::string& s)
{
	int N = s.size();
	std::vector<int> dp(N+1, 0);
	dp[N] = 1;
	for (int i = N; i >= 0; i--)
	{
		if (s[i] != 0)
		{
			int ans = dp[i + 1];
			if (((i + 1) < s.size()) && (((s[i] - '0') * 10 + s[i + 1] - '0') < 27))
			{
				ans += dp[i + 2];
			}
			dp[i] = ans;
		}
	}
	return dp[0];
}

int main()
{
	std::string s("11111");
	std::cout << maxValue_01(s) << std::endl;
	std::cout << maxValue_02(s) << std::endl;
	std::cout << maxValue_03(s) << std::endl;
	
	
	return 0;
}