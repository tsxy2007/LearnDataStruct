#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <sstream>

/*
*	字符串匹配之BF算法
*/ 

bool IsFind(std::string& src, std::string& desc)
{
	if (src.empty())
	{
		return false;
	}
	if (desc.empty())
	{
		return false;
	}

	int size = src.size();
	int descSize = desc.size();
	for (size_t i = 0; i < size - descSize + 1;)
	{
		if (src[i] == desc[0])
		{
			size_t k = i;
			bool bFind = true;
			for (size_t j = 0; j < descSize && k < size; j++, k++)
			{
				if (src[k] != desc[j])
				{
					bFind = false;
					break;
				}
			}
			if (bFind)
			{
				return true;
			}
			else
			{
				i = k + 1;
			}
		}
		else
		{
			i++;
		}
	}

	return false;
}


// BM 算法

int FindIndex(std::string& src, char c)
{
	for (size_t i = 0; i < src.size(); i++)
	{
		if (src[i] == c)
		{
			return i;
		}
	}
	return -1;
}

int FindSecond(std::string& src)
{
	int size = src.size();
	char c = src[size - 1];
	for (size_t i = 0; i < src.size() - 1; i++)
	{
		if (src[i] == c)
		{
			return i;
		}
	}
	return -1;
}

bool IsFind_01(std::string& src, std::string& desc)
{
	size_t index = desc.size() - 1;
	size_t lastIndex = desc.size() - 1;
	while (index < src.size())
	{
		bool bFind = true;
		char c = src[index];
		if (c != desc[lastIndex])
		{
			int fIndex = FindIndex(desc, c);
			index += (lastIndex - fIndex);
		}
		else
		{
			for (size_t i = lastIndex; i > 0; i--)
			{
				if (c != desc[i])
				{
					bFind = false;
					break;
				}
				c = src[--index];
			}
			if (bFind)
			{
				return true;
			}
			else
			{
				int secondIndex = FindSecond(desc);
				index += (lastIndex - secondIndex);
			}
		}

	}

	return false;
}

// KMP 算法

std::vector<int> GetNext(std::string str)
{
	std::vector<int> next;
	if (str.size() == 0)
	{
		return next;
	}

	// i的定义在for语句中
	int j = 0;

	next.resize(str.size());
	next[0] = j;

	for (int i = 1; i < str.size(); i++)
	{
		while (j > 0 && str[i] != str[j])
		{
			// 回溯
			j = next[j - 1];
		}
		if (str[i] == str[j])
		{
			j++;
		}
		next[i] = j;
	}
	return next;
}

bool IsFind_02(std::string haystack, std::string needle)
{
	if (needle.empty())
	{
		return false;
	}

	std::vector<int> next = GetNext(needle);
	int j = 0;
	for (int i = 0; i < haystack.size(); i++)
	{
		while (j > 0 && haystack[i] != needle[j])
		{
			// 发生了不匹配，j回溯
			j = next[j - 1];
		}
		if (haystack[i] == needle[j])
		{
			// 前后缀匹配，j往后移
			j++;
		}
		if (j == needle.size())
		{
			// 模式串全部匹配上了
			return true;
		}
	}

	return false;
}

int main()
{
	std::string src = "abcdfsdfsdfsdfsdfsdcdefsdfs";
	std::string desc = "cdef";
	std::string desc1 = "abcdfsdfsdfsdfsdfsdcdefsdfs1";

	std::string src1 = "HERE IS A SIMPLE EXAMPLE";
	std::string desc2 = "EXAMPLE";

	std::cout << IsFind(src, desc) << std::endl;
	std::cout << IsFind(src, desc1) << std::endl;
	std::cout << IsFind(src1, desc2) << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << IsFind_01(src1, desc2) << std::endl;
	std::cout << IsFind_01(src1, desc) << std::endl;
	std::cout << "--------------------------------------" << std::endl;
	std::cout << IsFind_02(src1, desc2) << std::endl;
	std::cout << IsFind_02(src1, desc) << std::endl;
	return 0;
}