#include <iostream>
#include <vector>
#include <unordered_map>
/*
*	给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
*	你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
*	你可以按任意顺序返回答案。
*/

// 方法一: 暴力求解

std::vector<int> TwoSum_01(const std::vector<int> data,int target)
{
	std::vector<int> result;
	int length = data.size();
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
		{
			if (data[i]+data[j] == target)
			{
				result.push_back(i);
				result.push_back(j);
				return result;
			}
		}
	}
	return result;
}

// 方法二: 用hashtable记录
std::unordered_map<int, int> TwoSumMap;

std::vector<int> TwoSum_02(const std::vector<int> data, int target)
{
	std::vector<int> result;
	int length = data.size();
	for (int i = 0; i < length; i++)
	{
		int Need = target - data[i];
		if (TwoSumMap.contains(Need))
		{
			result.push_back(TwoSumMap[Need]);
			result.push_back(i);
			return result;
		}
		else
		{
			TwoSumMap.insert({ data[i],i });
		}
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
	std::vector<int> data{ 2,7,11,15 };
	int target = 22;
	std::vector<int> result01 = TwoSum_01(data, target);
	print(result01);
	std::vector<int> result02 = TwoSum_02(data, target);
	print(result02);
	return 0;
}