#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stdlib.h>
#include <time.h>

/*
*	给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
*	写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
*/ 
void print(const std::vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << ' ';
	}
	std::cout << std::endl;
}

// 方法一: 常规查找
int search_01(std::vector<int>& nums, int target) 
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] == target)
			return i;
	}
	return -1;
}

// 方法二: 二分查找
int searchbyBinary(std::vector<int>& nums, int target, int start, int end)
{
	if (start >= nums.size())
	{
		return -1;
	}
	if (start == end)
	{
		if (nums[start] == target)
		{
			return start;
		}
		return -1;
	}
	int mid = (start + end) / 2;
	int midValue = nums[mid];
	if (midValue == target)
	{
		return mid;
	}
	else if (midValue> target)
	{
		return searchbyBinary(nums, target, start, mid);
	}
	else
	{
		return searchbyBinary(nums, target, mid + 1, end);
	}
}

int search_02(std::vector<int>& nums, int target)
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		if (nums[i] == target)
			return i;
	}
	return searchbyBinary(nums, target, 0, nums.size());
}


int main()
{
	std::vector<int> a{ -1,0,3,5,9,12 };

	//int index = search_01(a,9);
	int index = search_02(a,-2);
	std::cout << "index = " << index << std::endl;
	return 0;
}