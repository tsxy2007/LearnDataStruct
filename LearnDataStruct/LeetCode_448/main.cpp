#include <iostream>
#include <vector>
#include <algorithm>
/*
*	给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。
*	请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
*/ 


std::vector<int> findDisappearedNumbers(std::vector<int>& nums)
{
	std::vector<int> result;
	int size = nums.size();
	if (size == 0)
	{
		return result;
	}

	for (int i = 0; i < size; i++)
	{
		int x = (nums[i] - 1) % size;
		nums[x] += size;
	}

	for (int i = 0; i < size; i++)
	{
		if (nums[i] <= size)
		{
			result.push_back(i + 1);
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
	std::vector<int> nums{ 4,3,2,7,8,2,3,1 };
	std::vector<int> result =  findDisappearedNumbers(nums);
	print(result);

	return 0;
}