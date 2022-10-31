// LearnDataStruct.cpp : Defines the entry point for the application.
//

#include "LearnDataStruct.h"
#include "arrayList.h"
#include <vector>
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
	std::cout << "------------------------" << std::endl;
	for (int i = 0; i < a.size(); i++)
	{
		std::cout << a[i] << ' ';
	}
	std::cout << std::endl;

	for (auto i : a)
	{
		std::cout << (i) << ' ';
	}
	std::cout << std::endl;
	return 0;
}
