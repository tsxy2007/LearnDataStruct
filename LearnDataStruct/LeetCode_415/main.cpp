#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
/*
*	给定两个字符串形式的非负整数 num1 和num2 ，
*	计算它们的和并同样以字符串形式返回。
*	你不能使用任何內建的用于处理大整数的库（比如 BigInteger），
*	也不能直接将输入的字符串转换为整数形式。
*/ 

int toInt(char c)
{
	return c - '0';
}

char toChar(int c)
{
	return c + '0';
}

std::string addStrings(std::string num1, std::string num2)
{
	std::string res;
	int num1size = num1.size();
	int num2size = num2.size();
	int advance = 0;
	for (int i = num1size - 1, j = num2size - 1; i >= 0 || j >= 0; i--, j--)
	{
		int tmpNum1 = (i >= 0) ? toInt(num1[i]) : 0;
		int tmpNum2 = (j >= 0) ? toInt(num2[j]) : 0;
		int tmp = (tmpNum1 + tmpNum2 + advance);
		int c = tmp % 10;
		advance = tmp / 10;
		res = toChar(c) + res;
	}
	if(advance)
		res = toChar(advance) + res;
	return res;
}

int main()
{
	std::string num1 = "1", num2 = "9";
	std::cout << addStrings(num1, num2) << std::endl;
	return 0;
}