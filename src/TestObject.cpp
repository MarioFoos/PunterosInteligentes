#include "TestObject.h"
#include <cstdlib>
#include <iostream>

using namespace std;

TestObject::TestObject(const char *name)
{
	this->name = name;
	num = rand()%20;
	fnum = 15*((double)rand())/RAND_MAX;
	for(int i = 0; i < 10; ++i)
	{
		str[i] = rand()%('z' - 'a' + 1) + 'a';
	}
}
void TestObject::print()
{
	cout << name << ": " << num << " - " << fnum << " - " << str << endl;
}
