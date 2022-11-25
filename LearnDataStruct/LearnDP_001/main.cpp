#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <sstream>

/*
*	假设有排成一行的N个位置，记为1~N，N一定大于或等于2
*	开始的时候机器人停在其中的M位置上（M一定是1~N中的一个）
*	如果机器人来到1位置，那么下一步只能往右来到2位置
*	如果机器人来到N位置，那么下一步只能往左来到N-1位置
*	规定机器人必须走K步，最终能来到P位置（P也是1~N中的一个）的方法有多少种
*	给定四个参数N,M,K,P,返回方法数
*/ 

// 暴力求解

int process_01(int cur,int rest,int P,int N)
{
	if (rest == 0)
	{
		return cur == P ? 1 : 0;
	}

	// rest > 0 还有步数
	if (cur == 1)
	{
		return process_01(cur + 1, rest - 1, P, N);
	}
	else if(cur == N)
	{
		return process_01(cur - 1, rest - 1, P, N);
	}
	else
	{
		return process_01(cur - 1, rest - 1, P, N) + process_01(cur + 1, rest - 1, P, N);
	}
}


int way_01(int N, int M, int K, int P)
{
	return process_01(M, K, P, N);
}

// 优化一:存储之前位置需要跑几步

int process_02(int cur, int rest, int P, int N,std::vector<std::vector<int>>& dp)
{
	if (dp[cur][rest] != -1)
	{
		return dp[cur][rest];
	}

	int cout = 0;
	if (rest == 0)
	{
		cout = (cur == P ? 1 : 0);
	}
	else if (cur == 1)
	{
		cout = process_02(cur + 1, rest - 1, P, N,dp);
	}
	else if (cur == N)
	{
		cout = process_02(cur - 1, rest - 1, P, N, dp);
	}
	else
	{
		cout = process_02(cur - 1, rest - 1, P,  N, dp) + process_02(cur + 1, rest - 1, P, N, dp);
	}

	dp[cur][rest] = cout;
	return cout;
}


int way_02(int N, int M, int K, int P)
{
	std::vector<std::vector<int>> dp(N + 1, std::vector<int>(K + 1, -1));
	return process_02(M, K, P, N, dp);
}

// 优化二: 直接计算出二维表

int way_03(int N, int M, int K, int P)
{
	std::vector<std::vector<int>> dp(N + 1, std::vector<int>(K + 1, 0));
	dp[P][0] = 1;
	for (size_t rest = 1; rest < K + 1; rest++)
	{
		dp[1][rest] = dp[2][rest - 1];
		for (size_t cur = 2; cur < N; cur++)
		{
			dp[cur][rest] = dp[cur - 1][rest - 1] + dp[cur + 1][rest - 1];
		}
		dp[N][rest] = dp[N - 1][rest - 1];
	}

	return dp[M][K];
}


int main()
{
	std::cout << way_01(5,2,6,4) << std::endl;
	std::cout << way_02(5,2,6,4) << std::endl;
	std::cout << way_03(5,2,6,4) << std::endl;
	return 0;
}