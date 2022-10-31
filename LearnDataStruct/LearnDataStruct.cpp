// LearnDataStruct.cpp : Defines the entry point for the application.
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
	std::cout <<"a.capatity = " << a.capacity() << std::endl;
	//a.output(std::cout);
	std::cout << a << std::endl;


	return 0;
}
