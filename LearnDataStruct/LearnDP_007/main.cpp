#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <sstream>

/*
*	给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。
*	子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。
*/ 

// 暴力求解

int process_01(std::string& s, int L, int R)
{
	if (L == R)
	{
		return 1;
	}
	else if (R - L == 1)
	{
		return s[L] == s[R] ? 2 : 1;
	}
	else
	{
		int p1 = process_01(s, L, R - 1);
		int p2 = process_01(s, L + 1, R);
		int p3 = (s[L] == s[R] ? 2 : 0) + process_01(s, L + 1, R - 1) ;

		return std::max(std::max(p1, p2), p3);
	}
}

int longestPalindromeSubseq_01(std::string s)
{
	if (s.empty())
	{
		return 0;
	}
	return process_01(s, 0, s.size() - 1);
}

// 优化1:  动态规划版本1

int process_02(std::string& s, int L, int R, std::vector<std::vector<int>>& dp)
{
	if (dp[L][R] != -1)
	{
		return dp[L][R];
	}
	int ans = 0;
	if (L == R)
	{
		ans = 1;
	}
	else if ( L == R - 1)
	{
		ans = s[L] == s[R] ? 2 : 1;
	}
	else
	{
		int p1 = process_02(s, L, R - 1,dp);
		int p2 = process_02(s, L + 1, R, dp);
		int p3 = (s[L] == s[R] ? 2 : 0) + process_02(s, L + 1, R - 1, dp);

		ans = std::max(std::max(p1, p2), p3);
	}
	dp[L][R] = ans;
	return ans;
}

int longestPalindromeSubseq_02(std::string s)
{
	if (s.empty())
	{
		return 0;
	}
	int N = s.size(), M = s.size();
	std::vector<std::vector<int>> dp(N, std::vector(M, -1));
	process_02(s, 0, M - 1, dp);
	return dp[0][M-1];
}

// 动态规划优化2: 提炼二维数组
int longestPalindromeSubseq_03(std::string s)
{
	if (s.empty())
	{
		return 0;
	}
	int N = s.size();
	std::vector<std::vector<int>> dp(N, std::vector(N, -1));
	
	dp[N - 1][N - 1] = 1;
	for (int i = 0; i < N-1; i++)
	{
		dp[i][i] = 1;
		dp[i][i+1] = s[i] == s[i + 1] ? 2 : 1;
	}

	for (int L = N - 3; L >= 0; L--)
	{
		for (int R = L + 2; R < N; R++)
		{
			int p1 = dp[L][R - 1];
			int p2 = dp[L + 1][R];
			int p3 = (s[L] == s[R] ? 2 : 0) + dp[L + 1][R - 1];
			dp[L][R] = std::max(std::max(p1, p2), p3);
		}
	}

	return dp[0][N - 1];
}

int main()
{
	std::string s = "bbbab";
	std::cout << longestPalindromeSubseq_01(s) << std::endl;
	std::cout << longestPalindromeSubseq_02(s) << std::endl;
	std::cout << longestPalindromeSubseq_03(s) << std::endl;
	return 0;
}