#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
/*
*	给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。
*	有效字符串需满足：
*	左括号必须用相同类型的右括号闭合。
*	左括号必须以正确的顺序闭合。
*	每个右括号都有一个对应的相同类型的左括号。
 */ 

bool isValid(std::string s)
{
	int n = s.size();
	if (n % 2 == 1)
	{
		return false;
	}
	std::stack<char> cdeq;
	int index = 0;
	while (index < n)
	{
		char c = s[index];
		if (c == '(')
		{
			cdeq.push(')');
		}
		else if (c == '[')
		{
			cdeq.push(']');
		}
		else if (c == '{')
		{
			cdeq.push('}');
		}
		else if (cdeq.top() != c)
		{
			return false;
		}
		else
		{
			cdeq.pop();
		}
		index++;
	}
	return cdeq.empty();
}
int main()
{
	std::string s = "()[(){([])}]{}";
	std::cout << isValid(s) << std::endl;
	return 0;
}