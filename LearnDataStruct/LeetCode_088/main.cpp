#include <iostream>
#include <vector>
#include <algorithm>
/*
*	给你两个按 非递减顺序 排列的整数数组 nums1 和 nums2，另有两个整数 m 和 n ，分别表示 nums1 和 nums2 中的元素数目。
*	请你 合并 nums2 到 nums1 中，使合并后的数组同样按 非递减顺序 排列。
*	注意：最终，合并后数组不应由函数返回，而是存储在数组 nums1 中。为了应对这种情况，nums1 的初始长度为 m + n，其中前 m 个元素表示应合并的元素，后 n 个元素为 0 ，应忽略。nums2 的长度为 n 。
*/ 

// 方法一: stl标准库 时间复杂度nlog(n)

void merge_01(std::vector<int>& array01,int m, std::vector<int>& array02,int n)
{
	for (size_t i = 0; i < n; i++)
	{
		array01[m + i] = array02[i];
	}
	std::sort(array01.begin(), array01.end());
}
// 方法二: 双指针 时间复杂度O(n) 空间复杂度O(n)

void merge_02(std::vector<int>& array01, int m, std::vector<int>& array02, int n)
{
	std::vector<int> tmp;
	int k = m + n;
	tmp.resize(k);
	int index01 = 0;
	int index02 = 0;
	for (size_t i = 0; i < k; i++)
	{
		if (index01 >= m)
		{
			tmp[i] = array02[index02++];
		}
		else if (index02 >= n)
		{
			tmp[i] = array01[index01++];
		}
		else if (array01[index01] <= array02[index02])
		{
			tmp[i] = array01[index01++];
		}
		else
		{
			tmp[i] = array02[index02++];
		}
	}

	for (size_t i = 0; i < k; i++)
	{
		array01[i] = tmp[i];
	}
}



// 方法三: 逆向双指针时间复杂度O(n) 空间复杂度O(1)
void merge_03(std::vector<int>& array01, int m, std::vector<int>& array02, int n)
{
	int index01 = m - 1;
	int index02 = n - 1;
	int k = m + n;
	for (size_t i = k - 1; i > 0; i--)
	{
		if (index01 < 0)
		{
			array01[i] = array02[index02--];
		}
		else if (index02 < 0)
		{
			array01[i] = array01[index01--];
		}
		else if (array01[index01] >= array02[index02])
		{
			array01[i] = array01[index01--];
		}
		else
		{
			array01[i] = array02[index02--];
		}
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
	{

		std::vector<int> nums1{ 1, 2, 3 ,0,0,0 }, nums2{ 2, 5, 6 };
		merge_01(nums1, 3, nums2, 3);
		print(nums1);
	}
	{

		std::vector<int> nums1{ 1, 2, 3 ,0,0,0 }, nums2{ 2, 5, 6 };
		merge_02(nums1, 3, nums2, 3);
		print(nums1);
	}
	{

		std::vector<int> nums1{ 1, 2, 3 ,0,0,0 }, nums2{ 2, 5, 6 };
		merge_03(nums1, 3, nums2, 3);
		print(nums1);
	}

	return 0;
}