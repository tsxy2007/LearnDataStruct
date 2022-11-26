#include <iostream>
#include <vector>
#include <unordered_map>
/*
*	给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
*/

std::string Split(std::string& s, char tag)
{
	std::string second = "";
	bool bSecond = false;
	for (int i = 0; i < s.size(); i++)
	{
		if (bSecond)
		{
			second += s[i];
		}
		if (s[i] == tag)
		{
			bSecond = true;
		}
	}
	return second;
}

int lengthOfLongestSubstring(std::string s)
{
	int maxSize = 0;
	std::string TmpStr = "";
	for (int i = 0; i < s.size(); i++)
	{
		if (TmpStr.find(s[i]) != std::string::npos)
		{
			if (maxSize < TmpStr.size())
			{
				maxSize = TmpStr.size();
			}
			TmpStr = Split(TmpStr,s[i]);
		}
		TmpStr += s[i];
	}

	maxSize = maxSize > TmpStr.size() ? maxSize : TmpStr.size();

	return maxSize;
}

int main()
{
	std::string s = "dvdf";
	std::cout << lengthOfLongestSubstring(s) << std::endl;
	return 0;
}