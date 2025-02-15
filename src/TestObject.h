#ifndef TESTOBJECT_H_
#define TESTOBJECT_H_

#include <iostream>

using namespace std;

// Objeto de prueba con valores aleatorios
class TestObject
{
	private:
		const char *name;
		int num;
		float fnum;
		char *str;

		int genRnd(int min, int max);
	public:
		TestObject(const char *name);
		virtual ~TestObject();

		string toString();
};
#endif /* TESTOBJECT_H_ */
