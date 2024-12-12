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
	//uniqueTest();
	//sharedTest1();
	//sharedTest2();
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

	cout << "----- Contador de usos -----" << endl;
	cout << p1.use_count() << endl;
	cout << p2.use_count() << endl;
	cout << p3.use_count() << endl;

	cout << "----- Chequeo de punteros -----" << endl;
	cout << "p1 y p3 comparten objeto apuntado: " << (p1 == p3) << endl;
	cout << "p1 y p2 comparten objeto apuntado: " << (p1 == p2) << endl;
	cout << "p2 y p3 comparten objeto apuntado: " << (p2 == p3) << endl;

	cout << "----- Intercambio de punteros -----" << endl;
	p1.swap(p2);

	cout << "----- Contador de usos -----" << endl;
	cout << p1.use_count() << endl;
	cout << p2.use_count() << endl;
	cout << p3.use_count() << endl;

	cout << "----- Chequeo de punteros -----" << endl;
	cout << "p1 y p3 comparten objeto apuntado: " << (p1 == p3) << endl;
	cout << "p1 y p2 comparten objeto apuntado: " << (p1 == p2) << endl;
	cout << "p2 y p3 comparten objeto apuntado: " << (p2 == p3) << endl;
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
    cout << p1.get() << endl; 			// NULL o 0
    cout << p2.use_count() << endl;
    cout << p3.use_count() << endl;
}

void uniqueTest()
{
	cout << "----- Test unique_ptr -----" << endl;

	// Dos punteros unicos a entero
	std::unique_ptr<int> ptr1(new int(17));
	std::unique_ptr<int> ptr2(new int(33));

	// Mostrar
	cout << *ptr1 << " / " << *ptr2 << endl;

	// Intercambiar
	std::unique_ptr<int> aux(std::move(ptr1));
	ptr1 = std::move(ptr2);
	ptr2 = std::move(aux);

	// Mostrar
	cout << *ptr1 << " / " << *ptr2 << endl;

	// Array de doubles al azar
	std::unique_ptr<double[]> arr(new double[5]());

	for(int i = 0; i < 5; ++i)
	{
		arr[i] =  20*((double)rand())/RAND_MAX;
	}
	// Mostrar
	for(int i = 0; i < 5; ++i)
	{
		cout << arr[i] << endl;
	}

	// Objetos
	std::unique_ptr<TestObject> pO1(new TestObject("Obj1"));
	std::unique_ptr<TestObject> pO2(new TestObject("Obj2"));

	// Mostrar
	cout << "Punteros a los objetos originales" << endl;
	pO1->print();
	pO2->print();

	// Intercambiar
	std::unique_ptr<TestObject> pO3(std::move(pO1));
	pO1 = std::move(pO2);
	pO2 = std::move(pO3);

	// Mostrar
	cout << "Punteros intercambiados" << endl;
	pO1->print();
	pO2->print();
}
