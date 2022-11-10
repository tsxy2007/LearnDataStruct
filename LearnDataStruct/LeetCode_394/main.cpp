#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <sstream>

/*
*	给定一个经过编码的字符串，返回它解码后的字符串。
*	编码规则为: k[encoded_string]，表示其中方括号内部的 encoded_string 正好重复 k 次。注意 k 保证为正整数。
*	你可以认为输入字符串总是有效的；输入字符串中没有额外的空格，且输入的方括号总是符合格式要求的。
*	此外，你可以认为原始数据不包含数字，所有的数字只表示重复的次数 k ，例如不会出现像 3a 或 2[4] 的输入。
*/ 

bool isNumeric(std::string const& str)
{
	auto it = str.begin();
	while (it != str.end() && std::isdigit(*it)) {
		it++;
	}
	return !str.empty() && it == str.end();
}


int to_digit_2(std::string& var) {
	int ans{};
	std::stringstream ss{};
	ss << var;
	ss >> ans;
	return ans;
}

std::string decodeString(std::string s)
{
	std::stack<std::string> numStack;
	std::stack<std::string> nodeStack;
	for (int i = 0; i < s.length(); i++)
	{
		std::string it;
		it += s[i];
		nodeStack.push(it);
		if (s[i] == ']')
		{
			// 移除"]"
			nodeStack.pop();
			std::string tmp = "";
			while (nodeStack.top() != "[")
			{
				std::string top = nodeStack.top();
				tmp = top + tmp;
				nodeStack.pop();
			}
			// 移除"["
			nodeStack.pop();
			while (!nodeStack.empty()&&isNumeric(nodeStack.top()))
			{
				numStack.push(nodeStack.top());
				nodeStack.pop();
			}
			std::string num;
			while (!numStack.empty())
			{
				num += numStack.top();
				numStack.pop();
			}
			int cout = to_digit_2(num);
			std::string result = "";
			for (int i = 0; i < cout; i++)
			{
				result += tmp;
			}
			nodeStack.push(result);
		}
	}

	std::string str;
	while (!nodeStack.empty())
	{
		str = nodeStack.top() + str;
		nodeStack.pop();
	}
	return str;
}

int main()
{
	std::string srcStr = "abc3[cd]xyz";
	std::cout << decodeString(srcStr) << std::endl;;
	return 0;
}