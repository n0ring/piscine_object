#pragma once 

#include <iostream>
#include "Tool.h"

struct Shovel : public Tool
{
public:
	Shovel();
	~Shovel();
	Shovel(const Shovel& src);
	Shovel& operator=(const Shovel& src);

	virtual void use();

private:

};
