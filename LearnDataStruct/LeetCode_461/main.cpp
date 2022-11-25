#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

/*
*	两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。
*	给你两个整数 x 和 y，计算并返回它们之间的汉明距离。
*/ 

int hammingDistance(int x, int y)
{
	int eor = x ^ y;
	int dis = 0;
	while (eor)
	{
		eor &= (eor - 1);
		dis++;
	}
	return dis;
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
	std::cout << hammingDistance(3, 1) << std::endl;

	return 0;
}