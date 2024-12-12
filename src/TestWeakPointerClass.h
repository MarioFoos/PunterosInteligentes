#ifndef TESTWEAKPOINTERCLASS_H_
#define TESTWEAKPOINTERCLASS_H_

#include <iostream>
#include <memory>

using namespace std;

// Declaraciones previas
class Manager;
class Worker;

class Manager
{
	public:
		std::string name;
		std::shared_ptr<Worker> worker; // Posee un Worker

		Manager(const std::string &name);
		~Manager();
};

class Worker
{
	public:
		std::string name;
		std::weak_ptr<Manager> manager; // Observa el Manager

		Worker(const std::string &name);
		~Worker();

		void showManager();
};

#endif /* TESTWEAKPOINTERCLASS_H_ */
