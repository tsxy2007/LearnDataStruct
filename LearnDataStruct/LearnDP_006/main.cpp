#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <sstream>

/*
*	给定两个字符串 text1 和 text2，
*	返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。
*	一个字符串的 子序列 是指这样一个新的字符串：
*	它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
*	例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
*	两个字符串的 公共子序列 是这两个字符串所共同拥有的子序列。
*/ 

// 暴力求解

int process_01(std::string& s1, std::string& s2, int i, int j)
{
	if (i == 0 && j ==0)
	{
		return s1[i] == s2[j] ? 1 : 0;
	}
	else if (i == 0)
	{
		if (s1[i] == s2[j])
		{
			return 1;
		}
		return process_01(s1, s2, i, j - 1);
	}
	else if (j == 0)
	{
		if (s1[i] == s2[j])
		{
			return 1;
		}
		return process_01(s1, s2, i - 1, j);
	}
	else
	{
		int p1 = process_01(s1, s2, i, j - 1);
		int p2 = process_01(s1, s2, i - 1, j);
		int p3 = s1[i] == s2[j] ? 1 + process_01(s1, s2, i - 1, j - 1) : 0;

		return std::max(p1, std::max(p2, p3));
	}
}

int longestCommonSubsequence(std::string& text1, std::string& text2)
{
	if (text1.empty() || text2.empty())
	{
		return 0;
	}
	int N = text1.size();
	int M = text2.size();
	return process_01(text1, text2, N - 1, M - 1);
}


// 二维矩阵

int longestCommonSubsequence_01(std::string& s1, std::string& s2)
{
	if (s1.empty() || s2.empty())
	{
		return 0;
	}
	int N = s1.size();
	int M = s2.size();
	std::vector<std::vector<int>> dp(N, std::vector<int>(M));

	dp[0][0] = s1[0] == s2[0] ? 1 : 0;
	
	for (int j = 1; j < M; j++)
	{
		dp[0][j] = s1[0] == s2[j] ? 1 : dp[0][j - 1];
	}

	for (int i = 1; i < N; i++)
	{
		dp[i][0] = s1[i] == s2[0] ? 1 : dp[i - 1][0];
	}

	for (int i = 1; i < N; i++)
	{
		for (int j = 1; j < M; j++)
		{
			int p1 = dp[i][j - 1];
			int p2 = dp[i - 1][j];
			int p3 = s1[i] == s2[j] ? 1 + dp[i - 1][j - 1]: 0;
			dp[i][j] = std::max(p1, std::max(p2, p3));
		}
	}

	return dp[N - 1][M - 1];
}


int main()
{
	std::string text1 = "abcde", text2 = "ace";
	std::cout << longestCommonSubsequence(text1, text2) << std::endl;
	std::cout << longestCommonSubsequence_01(text1, text2) << std::endl;
	return 0;
}