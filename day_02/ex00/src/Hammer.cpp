#include "Hammer.h"

Hammer::Hammer(){
	std::cout << "Hammer constructor called" << std::endl;
}

Hammer::~Hammer() {
	std::cout << STD_RED << "Hammer destructor called" << STD_BLACK << std::endl;
}

Hammer::Hammer(const Hammer& src) {
	std::cout << "Hammer copy constructor called" << std::endl;
	*this = src;
}

Hammer& Hammer::operator=(const Hammer& src) {
	std::cout << "Hammer assignation operator called" << std::endl;
	if (this != &src) {
	}
	return *this;
}

void Hammer::use() {
	numberOfUses++;
	std::cout << "Hammer used. current number of use is " << numberOfUses << std::endl;
}

