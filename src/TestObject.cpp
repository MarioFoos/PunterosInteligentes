#include "TestObject.h"
#include <cstdlib>
#include <iostream>

using namespace std;

TestObject::TestObject(const char *name)
{
	srand(reinterpret_cast<uintptr_t>(name));

	this->name = name;
	num = rand()%20;
	fnum = 15*((double)rand())/RAND_MAX;
	for(int i = 0; i < STR_LEN; ++i)
	{
		str[i] = rand()%('z' - 'a' + 1) + 'a';
	}
	str[STR_LEN] = 0;
}
void TestObject::print()
{
	cout << name << ": " << num << " - " << fnum << " - " << str << endl;
}
