#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>

/*
*	请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）：
*
*	实现 MyQueue 类：
*	
*	void push(int x) 将元素 x 推到队列的末尾
*	int pop() 从队列的开头移除并返回元素
*	int peek() 返回队列开头的元素
*	boolean empty() 如果队列为空，返回 true ；否则，返回 false
*/ 

class MyQueue
{
public:
	MyQueue()
	{

	}

	void push(int x)
	{
		inStack.push(x);
	}

	void pop()
	{
		if (outStack.empty())
		{
			in2out();
		}
		if (!outStack.empty())
		{
			outStack.pop();
		}
	}

	int peek()
	{
		if (outStack.empty())
		{
			in2out();
		}
		if (!outStack.empty())
		{
			return outStack.top();
		}
		else
		{
			return -1;
		}
	}

	bool empty()
	{
		return inStack.empty() && outStack.empty();
	}
	
	void in2out()
	{
		while (!inStack.empty())
		{
			outStack.push(inStack.top());
			inStack.pop();
		}
	}
private:
	std::stack<int> inStack;
	std::stack<int> outStack;
};

int main()
{
	MyQueue queue;
	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.push(5);

	while (!queue.empty())
	{
		std::cout << queue.peek() << " ";
		queue.pop();
	}
	std::cout << std::endl;

	return 0;
}