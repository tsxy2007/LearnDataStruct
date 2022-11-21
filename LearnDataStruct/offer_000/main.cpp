#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stdlib.h>
#include <time.h>

/*
*	二进制运算
*/ 

// 2的倍数取模
int Modulo(int Value)
{
	return Value & (8 - 1);
}

// 判断奇偶性
bool IsJi(int Value)
{
	return ((Value & 1) == 0);
}

// 翻倍减半

int To2(int Value)
{
	return Value << 1;
}

int ToHalf(int Value)
{
	return Value >> 1;
}

// 交换两数

void swap(int& a, int& b)
{
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
}

int main()
{

	std::cout << Modulo(10) << std::endl;
	std::cout << IsJi(19) << ' ' << IsJi(10) << std::endl;
	std::cout << To2(19) << ' ' << ToHalf(19) << std::endl;

	int a = 10, b = 20;
	std::cout << a << " " << b << std::endl;
	swap(a, b);
	std::cout << a << " " << b << std::endl;
	return 0;
}