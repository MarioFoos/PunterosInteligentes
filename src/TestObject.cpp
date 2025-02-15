#include "TestObject.h"
#include <cstdlib>
#include <iostream>

using namespace std;

TestObject::TestObject(const char *name) : name(name)
{
	// Usar el nombre reinterpretado como raíz
	srand(reinterpret_cast<uintptr_t>(name));

	// Generar datos al azar
	num = rand()%20;
	fnum = 15*((double)rand())/RAND_MAX;
	int len = genRnd(5, 10);
	str = new char[len];
	for(int i = 0; i < len; ++i)
	{
		str[i] = (char)genRnd('a', 'z');
	}
	str[len] = 0;
}
int TestObject::genRnd(int min, int max)
{
	return rand()%(max - min + 1) + min;
}
string TestObject::toString()
{
	return string(name) + ": {" + to_string(num) + ", " + to_string(fnum) + ", " + string(str) + "}";
}
TestObject::~TestObject()
{
	delete str;
}
