#ifndef TESTOBJECT_H_
#define TESTOBJECT_H_

// Objeto de prueba con valores aleatorios
class TestObject
{
	private:
		const char *name;
		int num;
		float fnum;
		char str[10];
	public:
		TestObject(const char *name);
		virtual ~TestObject(){};

		void print();
};

#endif /* TESTOBJECT_H_ */
