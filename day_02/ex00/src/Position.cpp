#include "Position.h"

Position::Position() : x(0), y(0), z(0) {
	std::cout << "Position default constructor called" << std::endl;
}

Position::Position(int x, int y, int z) : x(x), y(y), z(z) {
	std::cout << "Position constructor called" << std::endl;
}

Position::~Position() {
	std::cout << STD_RED << "Position destructor called" << STD_BLACK << std::endl;
}	

Position::Position(const Position& src) {
	std::cout << "Position copy constructor called" << std::endl;
	*this = src;
}

Position& Position::operator=(const Position& src) {
	std::cout << "Position assignation operator called" << std::endl;
	if (this != &src) {
		this->x = src.x;
		this->y = src.y;
		this->z = src.z;
	}
	return *this;
}
