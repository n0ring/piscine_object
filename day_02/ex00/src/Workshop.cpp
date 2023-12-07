#include "Workshop.h"

Workshop::Workshop(const Workshop& src) {
	*this = src;
}

Workshop& Workshop::operator=(const Workshop& src) {
	if (this != &src) {
	}
	return *this;
}

Workshop::Workshop() {
	std::cout << "Workshop default constructor called" << std::endl;
}

Workshop::~Workshop() {
	std::cout << STD_RED << "Workshop destructor called" << STD_BLACK << std::endl;
	while (!workers.empty()) {
		std::set<Worker*>::iterator it = workers.begin();
		if (*it)
			(*it)->unregisterFromWorkshop(this);
		workers.erase(workers.begin());
	}
}

void Workshop::registerWorker(Worker* worker) {
	if (worker) {
		std::cout << "Worker registered to workshop" << std::endl;
		workers.insert(worker);
		worker->registerToWorkshop(this);
	}
}

void Workshop::unregisterWorker(Worker* worker) {
	if (worker && workers.count(worker)) {
		workers.erase(worker);
		worker->unregisterFromWorkshop(this);
	}
}

void Workshop::unregisterWorkerByrequest(Worker* worker) { 
	if (worker) {
		std::cout << "Worker unregistered from workshop by request from worker" << std::endl;
		workers.erase(worker);
	}
}

void Workshop::executeWorkDay() {
	std::cout << "Workshop execute work day" << std::endl;
	std::set<Worker*>::iterator it = workers.begin();
	while (it != workers.end()) {
		(*it)->work();
		it++;
	}
}