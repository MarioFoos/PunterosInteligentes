#include <iostream>
#include <memory>
#include <cstdlib>
#include "TestObject.h"
#include "TestWeakPointerClass.h"

using namespace std;

void uniqueTest();
void sharedTest1();
void sharedTest2();
void weakTest();

int main()
{
	uniqueTest();
	sharedTest1();
	sharedTest2();
	weakTest();

	return 0;
}
void weakTest()
{
    // Crear Manager y Worker
    std::shared_ptr<Manager> manager = std::make_shared<Manager>("Carlos");
    std::shared_ptr<Worker> worker = std::make_shared<Worker>("Juan");

    // Establecer referencias
    manager->worker = worker;
    worker->manager = manager; // Débil para evitar ciclo

    worker->showManager();
}
void sharedTest2()
{
	std::shared_ptr<TestObject> p1 = std::make_shared<TestObject>("Obj1");
	std::shared_ptr<TestObject> p2 = std::make_shared<TestObject>("Obj2");
	std::shared_ptr<TestObject> p3 = p1;

	cout << "Dos punteros compartidos a diferentes objetos" << endl;
	p1->print();
	p2->print();

	cout << "Contador de usos:" << endl;
	cout << "p1: " << p1.use_count() << endl;
	cout << "p2: " << p2.use_count() << endl;
	cout << "p3: " << p3.use_count() << endl;

	cout << "Chequeo de punteros:" << endl;
	cout << "p1 y p2 comparten objeto apuntado: " << ((p1 == p2) ? "si" : "no") << endl;
	cout << "p1 y p3 comparten objeto apuntado: " << ((p1 == p3) ? "si" : "no") << endl;
	cout << "p2 y p3 comparten objeto apuntado: " << ((p2 == p3) ? "si" : "no") << endl;

	cout << "----- Intercambio de punteros p1 y p2 -----" << endl;
	p1.swap(p2);

	cout << "Contador de usos:" << endl;
	cout << "p1: " << p1.use_count() << endl;
	cout << "p2: " << p2.use_count() << endl;
	cout << "p3: " << p3.use_count() << endl;

	cout << "Chequeo de punteros:" << endl;
	cout << "p1 y p2 comparten objeto apuntado: " << ((p1 == p2) ? "si" : "no") << endl;
	cout << "p1 y p3 comparten objeto apuntado: " << ((p1 == p3) ? "si" : "no") << endl;
	cout << "p2 y p3 comparten objeto apuntado: " << ((p2 == p3) ? "si" : "no") << endl;
}
void sharedTest1()
{
	std::shared_ptr<TestObject> p1 = std::make_shared<TestObject>("Obj1");
	std::shared_ptr<TestObject> p2 = p1; // Ambos comparten el mismo recurso

	// Mostrar
	cout << "Punteros compartidos" << endl;
	p1->print();
	p2->print();

    // La dirección del objeto manejado es la misma
	cout << "----- Dirección del objeto manejado -----" << endl;
	cout << p1.get() << endl;
	cout << p2.get() << endl;

    // Contador de usos
	cout << "----- Contador de usos -----" << endl;
	cout << p1.use_count() << endl;
	cout << p2.use_count() << endl;

	cout << "Se agrega otro puntero, ahora el contador es:" << endl;
	std::shared_ptr<TestObject> p3 = p1;
	cout << p1.use_count() << endl;
	cout << p2.use_count() << endl;
	cout << p3.use_count() << endl;

    // Resetear el contador de p1, volviendo el puntero NULL
	cout << "----- Reseteo de uno de los punteros compartidos, bajando el contador de usos -----" << endl;
    p1.reset();
    cout << "Dir de p1: " << p1.get() << endl; 			// NULL o 0
    cout << p2.use_count() << endl;
    cout << p3.use_count() << endl;
}

void uniqueTest()
{
	cout << "----- Test unique_ptr -----" << endl;

	// Dos punteros unicos a entero
	std::unique_ptr<int> pInt1(new int(17));
	std::unique_ptr<int> pInt2(new int(33));

	// Mostrar
	cout << "int1: " << *pInt1 << " / int2: " << *pInt2 << endl;
	cout << "Dir int1: " << pInt1.get() << " / Dir int2: " << pInt2.get() << endl;

	// Intercambiar con move
	cout << "----- Intercambiar con move -----" << endl;

	std::unique_ptr<int> pInt3(std::move(pInt1));
	pInt1 = std::move(pInt2);
	pInt2 = std::move(pInt3);

	cout << "int1: " << *pInt1 << " / int2: " << *pInt2 << endl;

	// Array de doubles al azar
	cout << "----- Array -----" << endl;

	std::unique_ptr<double[]> arr(new double[5]());
	for(int i = 0; i < 5; ++i)
	{
		arr[i] =  20*((double)rand())/RAND_MAX;
	}
	for(int i = 0; i < 5; ++i)
	{
		cout << arr[i] << endl;
	}

	// Objetos
	cout << "----- Intercambiar con swap -----" << endl;

	std::unique_ptr<TestObject> p1(new TestObject("Obj1"));
	std::unique_ptr<TestObject> p2(new TestObject("Obj2"));

	// Mostrar
	cout << "Punteros a los objetos originales:" << endl;
	p1->print();
	p2->print();

	// Intercambiar con swap
	p1.swap(p2);

	// Mostrar
	cout << "Punteros intercambiados:" << endl;
	p1->print();
	p2->print();
}
