#pragma once 

#include "Position.h"
#include "Statistic.h"
#include "Shovel.h"
#define STD_RED "\033[0;31m"
#define STD_BLACK "\033[0;30m"

struct Shovel;
/// @brief Worker class
/// @details Worker class with composition of Position and Statistic bc Worker has a Position and a Statistic and manage their lifetime
/// @details Worker class with aggregation of Shovel bc Worker has a Shovel but doesn't manage its lifetime
struct Worker {
	public:
		Worker();
		Worker(std::string _name);
		~Worker();
		Worker(const Worker& src);
		Worker& operator=(const Worker& src);

		void setShovel(Shovel* shovel);
		void removeShovel();
	private:
		Position coordonnee; // composition
		Statistic stat; // composition
		Shovel* shovel; // aggregation
		std::string name;
};