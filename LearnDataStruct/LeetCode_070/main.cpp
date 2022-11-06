#include <iostream>
#include <unordered_map>
/*
* ��¥������ ÿ��ֻ����1-2��¥��
* ��N��¥���ж����ֽⷨ
* n = 1   f(n) = 1;
* n = 2   f(n) = 2;
* n = n   f(n) = f(n-1)+f(n-2)
*/

// ����һ: ���ݹ�

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

// ������: ��hashtable��¼
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

// ������: ���õݹ鳣�����

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
	// ���ݹ��÷� ʱ�临�ӷ�ΪO(nƽ��)
	std::cout << CalFibonacci_01(testF) << std::endl;
	// ���ݹ��÷� ������ľͲ����ټ����� ʱ�临�ӷ�ΪO(n)
	std::cout << CalFibonacci_02(testF) << std::endl;

	// �������ʱ�临�ӷ�ΪO(n)
	std::cout << CalFibonacci_03(testF) << std::endl;
	return 0;
}