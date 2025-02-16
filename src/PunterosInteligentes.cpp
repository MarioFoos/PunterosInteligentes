//============================================================================
// Autor: Diardon
// Blog : https://diardon.wordpress.com/
//============================================================================

#include <iostream>
#include <memory>
#include <cstdlib>
#include "TestObject.h"
#include "TestWeakPointerClass.h"

using namespace std;

void uniqueTest1();
void uniqueTest2();
void sharedTest1();
void sharedTest2();
void weakTest();

int main()
{
	//uniqueTest1();
	//uniqueTest2();
	//sharedTest1();
	sharedTest2();
	//weakTest();

	return 0;
}
void weakTest()
{
    // Crear Manager y Worker
    shared_ptr<Manager> manager = make_shared<Manager>("Carlos");
    shared_ptr<Worker> worker = make_shared<Worker>("Juan");

    // Establecer referencias
    manager->worker = worker;
    worker->manager = manager; // Débil para evitar ciclo

    worker->showManager();
}
void sharedTest2()
{
	shared_ptr<TestObject> p1 = make_shared<TestObject>("Obj1");
	shared_ptr<TestObject> p2 = make_shared<TestObject>("Obj2");
	shared_ptr<TestObject> p3 = p1;

	cout << "Dos punteros compartidos a diferentes objetos" << endl;
	cout << "p1->" << p1->toString() << endl;
	cout << "p2->" << p2->toString() << endl;

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
	shared_ptr<TestObject> p1 = make_shared<TestObject>("Obj1");
	shared_ptr<TestObject> p2 = p1; // Ambos comparten el mismo recurso

	// Mostrar
	cout << "Punteros compartidos" << endl;
	cout << "p1->" << p1->toString() << endl;
	cout << "p2->" << p2->toString() << endl;

    // La dirección del objeto manejado es la misma
	cout << "----- Dirección del objeto manejado -----" << endl;
	cout << p1.get() << endl;
	cout << p2.get() << endl;

    // Contador de usos
	cout << "----- Contador de usos -----" << endl;
	cout << p1.use_count() << endl;
	cout << p2.use_count() << endl;

	cout << "Se agrega otro puntero, ahora el contador es:" << endl;
	shared_ptr<TestObject> p3 = p1;
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

void uniqueTest2()
{
	cout << "----- Test unique_ptr -----" << endl;

	// Punteros a enteros
	auto pInt1 = make_unique<int>(17);
	auto pInt2 = make_unique<int>(33);

	cout << "pInt1: " << *pInt1 << " / pInt2: " << *pInt2 << endl;

	// Intercambiar con move
	cout << "----- Intercambiar con move -----" << endl;

	unique_ptr<int> pInt3(move(pInt1));
	pInt1 = move(pInt2);
	pInt2 = move(pInt3);

	cout << "pInt1: " << *pInt1 << " / pInt2: " << *pInt2 << endl;

	// Array
	cout << "----- Array -----" << endl;
    auto arr = make_unique<double[]>(5);
	for(int i = 0; i < 5; ++i)
	{
		arr[i] =  20*((double)rand())/RAND_MAX;
	}
	for(int i = 0; i < 5; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	// Objetos
	cout << "----- Intercambiar con swap -----" << endl;

    auto p1 = make_unique<TestObject>("Obj1");
    auto p2 = make_unique<TestObject>("Obj2");

	// Mostrar
	cout << "Punteros a los objetos originales:" << endl;
	cout << "p1->" << p1->toString() << endl;
	cout << "p2->" << p2->toString() << endl;

	// Intercambiar con swap
	p1.swap(p2);

	// Mostrar
	cout << "Punteros intercambiados:" << endl;
	cout << "p1->" << p1->toString() << endl;
	cout << "p2->" << p2->toString() << endl;
}

void uniqueTest1()
{
	cout << "----- Test unique_ptr -----" << endl;

	// Punteros a enteros
	unique_ptr<int> pInt1(new int(17));
	unique_ptr<int> pInt2(new int(33));

	cout << "pInt1: " << *pInt1 << " / pInt2: " << *pInt2 << endl;

	// Intercambiar con move
	cout << "----- Intercambiar con move -----" << endl;

	unique_ptr<int> pInt3(move(pInt1));
	pInt1 = move(pInt2);
	pInt2 = move(pInt3);

	cout << "pInt1: " << *pInt1 << " / pInt2: " << *pInt2 << endl;

	// Array
	cout << "----- Array -----" << endl;

	unique_ptr<double[]> arr(new double[5]());
	for(int i = 0; i < 5; ++i)
	{
		arr[i] =  20*((double)rand())/RAND_MAX;
	}
	for(int i = 0; i < 5; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	// Objetos
	cout << "----- Intercambiar con swap -----" << endl;

	unique_ptr<TestObject> p1(new TestObject("Obj1"));
	unique_ptr<TestObject> p2(new TestObject("Obj2"));

	cout << "Punteros a los objetos originales:" << endl;
	cout << "p1->" << p1->toString() << endl;
	cout << "p2->" << p2->toString() << endl;

	// Intercambiar con swap
	p1.swap(p2);

	// Mostrar
	cout << "Punteros intercambiados:" << endl;
	cout << "p1->" << p1->toString() << endl;
	cout << "p2->" << p2->toString() << endl;
}
