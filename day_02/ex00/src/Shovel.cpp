#include "Shovel.h"

Shovel::Shovel() : numberOfUses(0), currentWorker(NULL) {
	std::cout << "Shovel default constructor called" << std::endl;
}


Shovel::~Shovel() {
	std::cout << STD_RED << "Shovel destructor called" << STD_BLACK << std::endl;
}

Shovel::Shovel(const Shovel& src) {
	std::cout << "Shovel copy constructor called" << std::endl;
	*this = src;
}

Shovel& Shovel::operator=(const Shovel& src) {
	std::cout << "Shovel assignation operator called" << std::endl;
	if (this != &src) {
		this->numberOfUses = src.numberOfUses;
		this->currentWorker = src.currentWorker;
	}
	return *this;
}

void Shovel::giveToWorker(Worker* worker) {
	if (currentWorker) {
		currentWorker->removeShovel();
	}
	this->currentWorker = worker;
}

void Shovel::takeFromWorker() {
	std::cout << "Shovel taken from worker " << std::endl;
	this->currentWorker = NULL;
}
