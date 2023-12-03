#pragma once 

#include <iostream>

#define STD_RED "\033[0;31m"
#define STD_BLACK "\033[0;30m"

struct Position {
public:
	Position();
	Position(int x, int y, int z);
	~Position();
	Position(const Position& src);
	Position& operator=(const Position& src);


private:
	int x;
	int y;
	int z;
};