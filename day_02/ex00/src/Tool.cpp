#include "Tool.h"

Tool::Tool() : numberOfUses(0), currentWorker(NULL) {
	std::cout << "Tool default constructor called" << std::endl;
}

Tool::~Tool() {
	std::cout << STD_RED << "Tool destructor called" << STD_BLACK << std::endl;
}

Tool::Tool(const Tool& src) {
	std::cout << "Tool copy constructor called" << std::endl;
	*this = src;
}

Tool& Tool::operator=(const Tool& src) {
	std::cout << "Tool assignation operator called" << std::endl;
	if (this != &src) {
		numberOfUses = src.numberOfUses;
		currentWorker = src.currentWorker;
	}
	return *this;
}

void Tool::giveToWorker(Worker* worker) {
	if (currentWorker) {
		currentWorker->removeShovel(this);
	}
	this->currentWorker = worker;
}

void Tool::takeFromWorker() {
	std::cout << "Tool taken from worker " << std::endl;
	this->currentWorker = NULL;
}
