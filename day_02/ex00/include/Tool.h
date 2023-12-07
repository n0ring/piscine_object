#pragma once 
#include "Worker.h"

struct Worker;

struct Tool {
	public:
		Tool();
		Tool(int level, int exp);
		virtual ~Tool();
		Tool(const Tool& src);
		Tool& operator=(const Tool& src);
		void giveToWorker(Worker* worker);
		void takeFromWorker();
		virtual void use() = 0;
	protected:
		int numberOfUses; // TODO check that is implimented 
		Worker* currentWorker;


	
};