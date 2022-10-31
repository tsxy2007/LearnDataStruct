﻿// LearnDataStruct.cpp : Defines the entry point for the application.
//

#include "LearnDataStruct.h"
#include "arrayList.h"
using namespace std;

int main()
{
	arrayList<int> a(10);

	for (int i = 0; i < 25; i++)
	{
		a.insert(0,i);
	}
	for (int i = 0; i < 15; i++)
	{
		a.erase(0);
	}
	int capacity =a.capacity();
	std::cout <<"a.capatity = " << capacity << std::endl;
	std::cout << a << std::endl;


	return 0;
}
