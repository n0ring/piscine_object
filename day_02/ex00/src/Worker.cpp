#include "Worker.h"

Worker::Worker() : coordonnee(Position()), stat(Statistic()), name("default name"){
	std::cout << "Worker default constructor called" << std::endl;
}

Worker::Worker(std::string _name) : coordonnee(Position()), stat(Statistic()), name(_name){
	std::cout << "Worker name constructor called" << std::endl;
}


Worker::~Worker() {
	std::cout << STD_RED << "Worker destructor called" << STD_BLACK << std::endl;
	if (shovel) {
		shovel->takeFromWorker();
	}
}	

Worker::Worker(const Worker& src) {
	std::cout << "Worker copy constructor called" << std::endl;
	*this = src;
}

Worker& Worker::operator=(const Worker& src) {
	std::cout << "Worker assignation operator called" << std::endl;
	if (this != &src) {
		this->coordonnee = src.coordonnee;
		this->stat = src.stat;
		this->shovel = src.shovel;
		name = src.name;
	}
	return *this;
}

void Worker::setShovel(Shovel* shovel) {
	this->shovel = shovel;
	shovel->giveToWorker(this);
	std::cout << "Shovel given to worker " << name  << std::endl;
}

void Worker::removeShovel() {
	this->shovel = NULL;
	std::cout << "Shovel removed from worker " << name  << std::endl;
}