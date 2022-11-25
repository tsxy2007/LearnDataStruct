#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <sstream>

/*
*	给定一个整型数组 arr，代表数值不同的纸牌排成一条线。
*	玩家A 和 玩家B 依次拿走每张纸牌。
*	规定玩家 A 先拿，玩家B后拿，但是每个玩家每次只能拿走最左或最右的纸牌，玩家A和玩家B都绝顶聪明。
*	请返回最后获胜者的分数。
*/ 

// 暴力求解

int f_01(std::vector<int>& arr, int start, int end);
int g_01(std::vector<int>& arr, int start, int end);
int f_01(std::vector<int>& arr, int start, int end)
{
	if (end == start)
	{
		return arr[end];
	}
	int Left = arr[start] + g_01(arr, start + 1, end);
	int right = arr[end] + g_01(arr, start, end - 1);
	return  std::max(Left,right);
}

int g_01(std::vector<int>& arr, int start, int end)
{
	if (end == start)
	{
		return 0;
	}
	int Left = f_01(arr, start+1, end);
	int right = f_01(arr, start, end-1);
	return  std::min(Left, right);
}

int win_01(std::vector<int>& arr)
{
	int f = f_01(arr, 0, arr.size()-1);
	int g = g_01(arr, 0, arr.size()-1);
	return std::max(f,g);
}

// 优化1： 添加缓存

int f_02(std::vector<int>& arr, int start, int end,std::vector<std::vector<int>>& fmap, std::vector<std::vector<int>>& gmap);
int g_02(std::vector<int>& arr, int start, int end, std::vector<std::vector<int>>& fmap, std::vector<std::vector<int>>& gmap);


int f_02(std::vector<int>& arr, int start, int end, std::vector<std::vector<int>>& fmap, std::vector<std::vector<int>>& gmap)
{
	if (fmap[start][end] != -1)
	{
		return fmap[start][end];
	}
	int ans = 0;
	
	if (start == end)
	{
		ans = arr[start];
	}
	else
	{
		int left = arr[start] + g_02(arr, start + 1, end, fmap, gmap);
		int right = arr[end] + g_02(arr, start, end - 1, fmap, gmap);
		ans = std::max(left, right);
	}
	fmap[start][end] = ans;
	return fmap[start][end];
}

int g_02(std::vector<int>& arr, int start, int end, std::vector<std::vector<int>>& fmap, std::vector<std::vector<int>>& gmap)
{
	if (gmap[start][end] != -1)
	{
		return gmap[start][end];
	}
	int ans = 0;

	if (start != end)
	{
		int left = f_02(arr, start + 1, end, fmap, gmap);
		int right = f_02(arr, start, end - 1, fmap, gmap);
		ans = std::min(left, right);
	}

	gmap[start][end] = ans;
	return gmap[start][end];
}

int win_02(std::vector<int>& arr)
{
	int N = arr.size();
	std::vector<std::vector<int>> fmap(N, std::vector<int>(N, -1));
	std::vector<std::vector<int>> gmap(N, std::vector<int>(N, -1));
	int f = f_02(arr, 0, arr.size() - 1,fmap,gmap);
	int g = g_02(arr, 0, arr.size() - 1, fmap, gmap);
	return std::max(f, g);
}

// 优化2：直接套二维数组

int win_03(std::vector<int>& arr)
{
	int N = arr.size();
	std::vector<std::vector<int>> fmap(N, std::vector<int>(N, 0));
	std::vector<std::vector<int>> gmap(N, std::vector<int>(N, 0));

	for (size_t i = 0; i < N; i++)
	{
		fmap[i][i] = arr[i];
	}

	for (size_t startCol = 1; startCol < N; startCol++)
	{
		int L = 0;
		int R = startCol;
		while (R < N)
		{
			fmap[L][R] = std::max(arr[L] + gmap[L + 1][R], arr[R] + gmap[L][R - 1]);
			gmap[L][R] = std::min(fmap[L + 1][R], fmap[L][R - 1]);
			L++;
			R++;
		}
	}

	return std::max(fmap[0][N - 1], gmap[0][N - 1]);
}

int main()
{
	std::vector<int> nums{1, 100, 1};
	
	std::cout << win_01(nums) << std::endl;
	std::cout << win_02(nums) << std::endl;
	std::cout << win_03(nums) << std::endl;
	return 0;
}