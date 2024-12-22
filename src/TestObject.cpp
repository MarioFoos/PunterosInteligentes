#include "TestObject.h"
#include <cstdlib>
#include <iostream>

using namespace std;

TestObject::TestObject(const char *name)
{
	int *temp = new int;
	srand(reinterpret_cast<uintptr_t>(temp));
	delete temp;

	this->name = name;
	num = rand()%20;
	fnum = 15*((double)rand())/RAND_MAX;
	for(int i = 0; i < STR_LEN; ++i)
	{
		str[i] = (char)(rand()%('z' - 'a' + 1) + 'a');
	}
	str[STR_LEN] = 0;
}
void TestObject::print()
{
	cout << name << ": " << num << " - " << fnum << " - " << str << endl;
}
