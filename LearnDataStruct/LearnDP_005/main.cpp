#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <sstream>

/*
*	我们有 n 种不同的贴纸。每个贴纸上都有一个小写的英文单词。
*	您想要拼写出给定的字符串 target ，方法是从收集的贴纸中切割单个字母并重新排列它们。
*	如果你愿意，你可以多次使用每个贴纸，每个贴纸的数量是无限的。
*	返回你需要拼出 target 的最小贴纸数量。如果任务不可能，则返回 -1 。
*	注意：在所有的测试用例中，所有的单词都是从 1000 个最常见的美国英语单词中随机选择的，
*	并且 target 被选择为两个随机单词的连接。
*/ 

// 暴力求解

std::string minus(std::string& sticker, std::string target)
{
	// aaaabbbbc  abc
	std::vector<int> count(26, 0);
	for (int i = 0; i < target.size(); i++)
	{
		int index = target[i] - 'a';
		count[index] += 1;
	}

	for (int i = 0; i < sticker.size(); i++)
	{
		int index = sticker[i] - 'a';
		count[index] -= 1;
	}


	std::string minus = "";
	for (int i = 0; i < count.size(); i++)
	{
		for (int j = 0; j < count[i]; j++)
		{
			minus += (char)(i + 'a');
		}
	}
	return minus;
}

int process_01(std::vector<std::string>& stickers, std::string target)
{
	if (target.empty())
	{
		return 0;
	}
	int minValue = INT_MAX;
	for (size_t i = 0; i < stickers.size(); i++)
	{
		std::string sticker = stickers[i];
		std::string rest = minus(sticker, target);
		if (rest.size() != target.size())
		{
			minValue = std::min(minValue, process_01(stickers, rest));
		}
	}
	return minValue + (minValue == INT_MAX ? 0 : 1);
}

int minStickers_01(std::vector<std::string>& stickers, std::string target)
{
	int ans = process_01(stickers, target);
	return ans == INT_MAX ? -1 : ans;
}

// 使用二维数组

std::vector<int> MakeArray(std::string& str)
{
	std::vector<int> arr(26,0);
	for (size_t i = 0; i < str.size(); i++)
	{
		int Index = str[i] - 'a';
		arr[Index] +=1;
	}
	return arr;
}

std::string minus_02(std::vector<int>& sticker, std::vector<int>& target)
{
	std::string minus = "";
	for (int i = 0; i < sticker.size(); i++)
	{
		int num = target[i] - sticker[i];
		for (int j = 0; j < num; j++)
		{
			minus += (char)(i + 'a');
		}
	}
	return minus;
}

int process_02(std::vector<std::vector<int>> istickers, std::string target)
{
	if (target.empty())
	{
		return 0;
	}
	std::vector<int> itarget = MakeArray(target);
	int minValue = INT_MAX;
	for (size_t i = 0; i < istickers.size(); i++)
	{
		int index = target[0] - 'a';
		std::vector<int> sticker = istickers[i];
		// 剪枝（贪心）
		if (!sticker[index])
		{
			continue;
		}
		std::string rest = minus_02(sticker, itarget);
		if (rest.size() != target.size())
		{
			minValue = std::min(minValue, process_02(istickers, rest));
		}
	}
	return minValue + (minValue == INT_MAX ? 0 : 1);
}

int minStickers_02(std::vector<std::string>& stickers, std::string target)
{
	int size = stickers.size();
	std::vector<std::vector<int>> istickers;
	for (size_t i = 0; i < size; i++)
	{
		istickers.push_back(MakeArray(stickers[i]));
	}
	int ans = process_02(istickers, target);
	return ans == INT_MAX ? -1 : ans;
}

// 使用hashmap记录最优解


int process_03(std::vector<std::vector<int>> istickers, std::string target, std::unordered_map<std::string, int>& dp)
{
	if ( dp.find(target) != dp.end())
	{
		return dp[target];
	}
	if (target.empty())
	{
		return 0;
	}
	int ans = INT_MAX;
	std::vector<int> itarget = MakeArray(target);
	int minValue = INT_MAX;
	for (size_t i = 0; i < istickers.size(); i++)
	{
		int index = target[0] - 'a';
		std::vector<int> sticker = istickers[i];
		// 剪枝（贪心）
		if (!sticker[index])
		{
			continue;
		}
		std::string rest = minus_02(sticker, itarget);
		if (rest.size() != target.size())
		{
			minValue = std::min(minValue, process_03(istickers, rest,dp));
		}
	}
	ans = minValue + (minValue == INT_MAX ? 0 : 1);
	dp[target] = ans;
	return ans;
}

int minStickers_03(std::vector<std::string>& stickers, std::string target)
{
	int size = stickers.size();
	std::vector<std::vector<int>> istickers;
	for (size_t i = 0; i < size; i++)
	{
		istickers.push_back(MakeArray(stickers[i]));
	}

	std::unordered_map<std::string, int> dp;
	int ans = process_03(istickers, target,dp);
	return ans == INT_MAX ? -1 : ans;
}

//所有都用hashmap记录

std::unordered_map<int, int> MakeMap(std::string& src)
{
	std::unordered_map<int,int> map;
	for (int i = 0; i < src.size(); i++)
	{
		int Index = src[i] - 'a';
		if (map.find(Index) != map.end())
		{
			map[Index] += 1;
		}
		else
		{
			map.insert({ Index,1 });
		}
	}
	return map;
}

std::string minus_04(std::unordered_map<int,int>& sticker, std::unordered_map<int, int>& target)
{
	std::string minus = "";
	for (int i = 0; i < sticker.size(); i++)
	{
		int num = target[i] - sticker[i];
		for (int j = 0; j < num; j++)
		{
			minus += (char)(i + 'a');
		}
	}
	return minus;
}

int process_04(std::vector<std::unordered_map<int, int>>& istickers, std::string target, std::unordered_map<std::string, int>& dp)
{
	if (dp.find(target) != dp.end())
	{
		return dp[target];
	}
	if (target.empty())
	{
		return 0;
	}
	int ans = INT_MAX;
	std::unordered_map<int,int> itarget = MakeMap(target);
	int minValue = INT_MAX;
	for (size_t i = 0; i < istickers.size(); i++)
	{
		int index = target[0] - 'a';
		std::unordered_map<int,int> sticker = istickers[i];
		// 剪枝（贪心）
		if (!sticker[index])
		{
			continue;
		}
		std::string rest = minus_04(sticker, itarget);
		if (rest.size() != target.size())
		{
			minValue = std::min(minValue, process_04(istickers, rest, dp));
		}
	}
	ans = minValue + (minValue == INT_MAX ? 0 : 1);
	dp[target] = ans;
	return ans;
}

int minStickers_04(std::vector<std::string>& stickers, std::string target)
{
	int size = stickers.size();
	std::vector<std::unordered_map<int,int>> istickers;
	for (size_t i = 0; i < size; i++)
	{
		istickers.push_back(MakeMap(stickers[i]));
	}

	std::unordered_map<std::string, int> dp;
	int ans = process_04(istickers, target, dp);
	return ans == INT_MAX ? -1 : ans;
}



int main()
{
	std::vector<std::string> stickers{ "summer","sky","cent","bright","kill","forest","neighbor","capital","tall" };
	std::string target("originalchair");
	
	std::cout << minStickers_01(stickers, target) << std::endl;
	std::cout << minStickers_02(stickers, target) << std::endl;
	std::cout << minStickers_03(stickers, target) << std::endl;
	std::cout << minStickers_04(stickers, target) << std::endl;
	return 0;
}