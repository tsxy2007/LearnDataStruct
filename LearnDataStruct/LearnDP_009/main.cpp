﻿#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <stack>
#include <sstream>

/*
*	给定一个数组arr,arr[i]代表第i号咖啡机泡一杯咖啡时间
*	给定一个正数N,表示N个人等着咖啡机泡咖啡，每台咖啡机只能轮流泡咖啡
*	只有一台咖啡机，一次只能洗一个杯子，时间耗费a，洗完才能洗下一杯
*	每个咖啡杯也可以自己挥发干净,时间耗费b,咖啡杯可以并行挥发
*	假设所有人拿到咖啡之后立即喝干净，
*	返回从开始等到所有咖啡机变干净的最短时间
*	三个参数int[] arr,int N ,int a,int b
*/ 

struct Node
{
	int Index;
	int Value;

public:
};

int main()
{
	std::stack<int> a;
	return 0;
}