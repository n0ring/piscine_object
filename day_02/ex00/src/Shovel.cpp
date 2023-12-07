#include "Shovel.h"

Shovel::Shovel() {
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
	}
	return *this;
}

void Shovel::use() {
	numberOfUses++;
	std::cout << "Shovel used. current number of use is " << numberOfUses << std::endl;
}
