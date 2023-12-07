#pragma once 

#include <iostream>
#include "Tool.h"

struct Hammer : public Tool
{
public:
	Hammer();
	~Hammer();
	Hammer(const Hammer& src);
	Hammer& operator=(const Hammer& src);

	virtual void use();

private:

};
