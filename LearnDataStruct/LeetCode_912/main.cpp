#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stdlib.h>
#include <time.h>

/*
*	给你一个整数数组 nums，请你将该数组升序排列。
*/ 
void print(const std::vector<int>& nums);

void swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

//方法一:冒泡排序
std::vector<int> sortArray_01(std::vector<int>& nums)
{
	size_t size = nums.size();
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = i; j < size; j++)
		{
			if (nums[i]>nums[j])
			{
				swap(nums[i], nums[j]);
			}
		}
		print(nums);
	}

	return nums;
}

// 方法二: 选择排序
std::vector<int> sortArray_02(std::vector<int>& nums)
{
	for (size_t i = 0; i < nums.size(); i++)
	{
		int maxIndex = i;
		for (size_t j = i; j < nums.size(); j++)
		{
			if (nums[maxIndex] < nums[j])
			{
				maxIndex = j;
			}
		 }
		if (maxIndex != i)
		{
			swap(nums[i], nums[maxIndex]);
		}
		print(nums);
	}
	return nums;
}

// 方法三: 插入排序
std::vector<int> sortArray_03(std::vector<int>& nums)
{
	int size = nums.size();
	for (size_t i = 0; i < size - 1; i++)
	{
		int nextIndex = i + 1;
		int insertIndex = i + 1;
		for (size_t j = 0; j < nextIndex; j++)
		{
			if (nums[nextIndex] > nums[j])
			{
				insertIndex = j;
				break;
			}
		}
		int exValue = nums[nextIndex];
		int moveIndex = nextIndex;
		for (size_t j = nextIndex; j > insertIndex; j--)
		{
			nums[j] = nums[j - 1];
		}
		nums[insertIndex] = exValue;
		print(nums);
	}
	return nums;
}

// 方法四: 快速排序
int partition(std::vector<int>& nums, int start, int end)
{
	if (end - start < 2)
	{
		return start;
	}
	int midIndex = (start + end) / 2;// start + rand() % (end - start);
	swap(nums[midIndex], nums[end - 1]);
	int partitionIndex = start;
	for (size_t i = start; i < end; i++)
	{
		if (nums[i] < nums[end - 1])
		{
			partitionIndex += 1;
		}
		if ((partitionIndex != i) || (i == end - 1))
		{
			swap(nums[partitionIndex], nums[i]);
		}
	}

	print(nums);
	return partitionIndex;
}

void sortArray_04(std::vector<int>& nums, int start, int end)
{
	if (nums.size() == 1 || start<0 || end > nums.size() || start>end)
	{
		return;
	}
	int partitionIndex = partition(nums, start, end);
	if (partitionIndex > start)
	{
		sortArray_04(nums, start, partitionIndex);
	}
	if (partitionIndex < end)
	{
		sortArray_04(nums, partitionIndex + 1, end);
	}
}
std::vector<int> sortArray_04(std::vector<int>& nums)
{
	srand(time(nullptr));
	sortArray_04(nums, 0, nums.size());
	return nums;
}

void print(const std::vector<int>& nums)
{
	for (int i = 0; i < nums.size(); i++)
	{
		std::cout << nums[i] << ' ';
	}
	std::cout << std::endl;
}

int main()
{
	std::vector<int> a{ 5,2,1,3 };
	//sortArray_01(a);
	//sortArray_02(a);
	//sortArray_03(a);
	sortArray_04(a);
	
	return 0;
}