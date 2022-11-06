#include <iostream>
#include <unordered_map>
/*
* 爬楼梯问题 每次只能爬1-2阶楼梯
* 问N阶楼梯有多少种解法
* n = 1   f(n) = 1;
* n = 2   f(n) = 2;
* n = n   f(n) = f(n-1)+f(n-2)
*/

// 方法一: 纯递归

int CalFibonacci_01(int n)
{
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 2;
	}
	return CalFibonacci_01(n - 1) + CalFibonacci_01(n - 2);
}

// 方法二: 用hashtable记录
std::unordered_map<int, int> FibonacciMap;

int CalFibonacci_02(int n)
{
	if (n==1)
	{
		return 1;
	}
	if (n==2)
	{
		return 2;
	}
	if (FibonacciMap.contains(n))
	{
		return FibonacciMap[n];
	}
	return CalFibonacci_02(n - 1) + CalFibonacci_02(n - 2);
}

// 方法三: 不用递归常规计算

int CalFibonacci_03(int n)
{
	if (n == 1)
	{
		return 1;
	}
	if (n == 2)
	{
		return 2;
	}

	int pre = 2;
	int prepre = 1;
	int result = 0;
	for (int i = 3; i <= n; i++)
	{
		result = pre + prepre;
		prepre = pre;
		pre = result;
	}
	return result;
}

int main()
{
	int testF = 3;
	// 纯递归用法 时间复杂夫为O(n平方)
	std::cout << CalFibonacci_01(testF) << std::endl;
	// 纯递归用法 计算过的就不用再计算了 时间复杂夫为O(n)
	std::cout << CalFibonacci_02(testF) << std::endl;

	// 常规计算时间复杂夫为O(n)
	std::cout << CalFibonacci_03(testF) << std::endl;
	return 0;
}