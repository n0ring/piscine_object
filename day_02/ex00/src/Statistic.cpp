#include "Statistic.h"

Statistic::Statistic() : level(0), exp(0) {
	std::cout << "Statistic default constructor called" << std::endl;
}

Statistic::Statistic(int level, int exp) : level(level), exp(exp) {
	std::cout << "Statistic constructor called" << std::endl;
}

Statistic::~Statistic() {
	std::cout << STD_RED << "Statistic destructor called" << STD_BLACK << std::endl;
}

Statistic::Statistic(const Statistic& src) {
	std::cout << "Statistic copy constructor called" << std::endl;
	*this = src;
}

Statistic& Statistic::operator=(const Statistic& src) {
	std::cout << "Statistic assignation operator called" << std::endl;
	if (this != &src) {
		this->level = src.level;
		this->exp = src.exp;
	}
	return *this;
}