#ifndef TESTOBJECT_H_
#define TESTOBJECT_H_

// Objeto de prueba con valores aleatorios
class TestObject
{
	private:
		static const int STR_LEN = 10;

		const char *name;
		int num;
		float fnum;
		char str[STR_LEN + 1];
	public:
		TestObject(const char *name);
		virtual ~TestObject(){};

		void print();
};

#endif /* TESTOBJECT_H_ */
