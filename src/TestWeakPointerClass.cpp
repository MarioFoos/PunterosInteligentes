/*
 * TestWeakPointerClass.cpp
 *
 *  Created on: 12 dic 2024
 *      Author: Mario
 */

#include "TestWeakPointerClass.h"

Manager::Manager(const std::string &name) : name (name)
{
	std::cout << "Manager " << name << " creado.\n";
}
Manager::~Manager()
{
	std::cout << "Manager " << name << " destruido.\n";
}

Worker::Worker(const std::string &name) :
		name (name)
{
	std::cout << "Worker " << name << " creado.\n";
}
void Worker::showManager()
{
	// Intenta obtener un shared_ptr válido
	std::shared_ptr<Manager> mgr = manager.lock();
	if(mgr != NULL)
	{
		std::cout << "Worker " << name << " trabaja para Manager " << mgr->name << ".\n";
	}
	else
	{
		std::cout << "Worker " << name << " no tiene un Manager válido.\n";
	}
}
Worker::~Worker()
{
	std::cout << "Worker " << name << " destruido.\n";
}
