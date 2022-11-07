// LearnDataStruct.cpp : Defines the entry point for the application.
//

#include "LearnDataStruct.h"
#include "arrayList.h"
#include <vector>
#include <array>
#include "array.h"
int main()
{
	arrayList<int,12> a(10);

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
	std::vector<int> n;
	std::array<int, 10> c{1,2,4,4,5,5,5,5};

	MySTL::array<int,10> mc;

	for (int i = 0; i < mc.size(); i++)
	{
		mc[i] = i;
	}
	for (auto Iter = mc.begin(); Iter != mc.end(); ++Iter)
	{
		std::cout << *Iter << " ";
	}
	return 0;
}
