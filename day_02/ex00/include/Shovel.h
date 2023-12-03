#pragma once 

#include <iostream>
#include "Worker.h"


struct Worker;
struct Shovel
{
public:
	Shovel();
	~Shovel();
	Shovel(const Shovel& src);
	Shovel& operator=(const Shovel& src);

	void use();
	void giveToWorker(Worker* worker);
	void takeFromWorker();
private:
	int numberOfUses; // TODO check that is implimented 
	Worker* currentWorker;
};
