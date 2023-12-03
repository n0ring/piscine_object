#pragma once 

#include <iostream>

#define STD_RED "\033[0;31m"
#define STD_BLACK "\033[0;30m"

struct Statistic {
	public: 
		Statistic();
		Statistic(int level, int exp);
		~Statistic();
		Statistic(const Statistic& src);
		Statistic& operator=(const Statistic& src);

	private:
		int level;
		int exp;
};