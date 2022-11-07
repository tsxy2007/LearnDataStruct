#include <iostream>
#include <vector>
#include <algorithm>
/*
*	给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
*	请注意 ，必须在不复制数组的情况下原地对数组进行操作	。
*	
*/ 

// 方法一: 双指针 时间复杂度O(n) 空间复杂度O(1)

void moveZeroes(std::vector<int>& array01)
{
	int size = array01.size();
	if (size == 0)
	{
		return;
	}
	int j = 0;
	for (int i = 0; i < size; i++)
	{
		if (array01[i] != 0)
		{
			array01[j++] = array01[i];
		}
	}
	for (size_t i = j; i < size; i++)
	{
		array01[i] = 0;
	}
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
	std::vector<int> nums{ 0,1,0,3,12 };
	moveZeroes(nums);
	print(nums);

	return 0;
}