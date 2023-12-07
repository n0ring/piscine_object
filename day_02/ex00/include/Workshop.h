#pragma once 

#include <set> 
#include "Worker.h"

struct Worker;

class Workshop {
	public:
		Workshop();
		~Workshop();
		Workshop(const Workshop& src);
		Workshop& operator=(const Workshop& src);
		void registerWorker(Worker* worker);
		void unregisterWorker(Worker* worker);

		/// @brief method for worker to call
		void unregisterWorkerByrequest(Worker* worker);
		void executeWorkDay();
	private:
		std::set<Worker*> workers;
};