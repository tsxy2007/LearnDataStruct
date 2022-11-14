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
	for (int i = 0; i < size - 1; i++)
	{
		int nextIndex = i + 1;
		int exValue = nums[nextIndex];
		int j = nextIndex-1;
		for (; j >= 0 && exValue > nums[j]; )
		{
			nums[j+1] = nums[j]; 
			j--;
		}
		nums[j+1] = exValue;
		print(nums);
	}
	return nums;
}

// 方法四: 快速排序

int random(int start, int end)
{
	return start + rand() % (end - start);;
}

int partition(std::vector<int>& nums, int start, int end)
{
	//std::cout << "------------------------------------------" << "start = " << start << " end = " << end << std::endl;
	int midIndex = random(start,end);
	//std::cout << "midIndex = " << midIndex << " value = " << nums[midIndex] << std::endl;
	swap(nums[midIndex], nums[end - 1]);
	int partitionIndex = start - 1;
	for (size_t i = start; i < end -1; i++)
	{ 
		if (nums[i] < nums[end - 1])
		{
			partitionIndex += 1;
			if (partitionIndex != i)
			{
				swap(nums[partitionIndex], nums[i]);
				//std::cout << "swap(destIndex = " << partitionIndex << " srcIndex = " << i << ")" << std::endl;
				//print(nums);
			}
		}
	}
	swap(nums[partitionIndex + 1], nums[end - 1]);
	//print(nums);
	//std::cout << "------------------------------------------"<< partitionIndex + 1 << std::endl;
	return partitionIndex + 1;
}

void sortArray_04(std::vector<int>& nums, int start, int end)
{
	if (nums.size() == 1 || start<0 || end > nums.size() || start>=end)
	{
		return;
	}
	int partitionIndex = partition(nums, start, end);
	if (partitionIndex > start)
	{
		sortArray_04(nums, start, partitionIndex);
	}
	if (partitionIndex+1 < end)
	{
		sortArray_04(nums, partitionIndex+1, end);
	}
}
std::vector<int> sortArray_04(std::vector<int>& nums)
{
	srand(time(nullptr));
	sortArray_04(nums, 0, nums.size());
	return nums;
}

// 方法五: 希尔排序
std::vector<int> sortArray_05(std::vector<int>& nums)
{
	int size = nums.size();
	int  step = size / 2;
	while (step > 0)
	{
		for (size_t i = step; i < size; i++)
		{
			int tmp = nums[i];
			int j = i - step;
			for (; j >= 0 && tmp < nums[j]; j -= step)
			{
				nums[j + step] = nums[j];
			}
			nums[j + step] = tmp;
		}
		step /= 2;
	}

	print(nums);
	return nums;
}

// 方法六: 归并排序

std::vector<int> merge(std::vector<int>& left, std::vector<int>& right)
{
	std::vector<int> mergeVector;
	int leftIndex = 0;
	int rightIndex = 0;
	while (leftIndex < left.size() || rightIndex < right.size())
	{
		if (leftIndex >= left.size())
		{
			mergeVector.push_back(right[rightIndex]);
			rightIndex++;
		}
		else if (rightIndex >= right.size())
		{
			mergeVector.push_back(left[leftIndex]);
			leftIndex++;
		}
		else if (left[leftIndex] < right[rightIndex])
		{
			mergeVector.push_back(right[rightIndex]);
			rightIndex++;
		}
		else
		{
			mergeVector.push_back(left[leftIndex]);
			leftIndex++;
		}
	}
	return mergeVector;
}

std::vector<int> sortArray_06(std::vector<int>& nums)
{
	if (nums.size() == 1)
	{
		return nums;
	}
	int mid = nums.size() / 2;
	std::vector<int> half1(nums.begin(),nums.begin()+mid), half2(nums.begin()+mid,nums.end());
	std::vector<int> newHalf1 = sortArray_06(half1);
	std::vector<int> newHalf2 = sortArray_06(half2);
	return merge(newHalf1, newHalf2);
}

// 堆排序
std::vector<int> sortArray_07(std::vector<int>& nums)
{

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
	std::vector<int> a{ 5,2,1,3,4,7,8,9,6 };
	//std::vector<int> result = sortArray_01(a);
	//std::vector<int> result = sortArray_02(a);
	//std::vector<int> result = sortArray_03(a);
	//std::vector<int> result = sortArray_04(a);
	//std::vector<int> result = sortArray_05(a);
	//std::vector<int> result = sortArray_06(a);
	std::vector<int> result = sortArray_07(a);
	print(result);
	return 0;
}