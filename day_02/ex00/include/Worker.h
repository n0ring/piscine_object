#pragma once 

#include <set> 
#include "Position.h"
#include "Statistic.h"
#include "Tool.h"
#include "Workshop.h"

#define STD_RED "\033[0;31m"
#define STD_BLACK "\033[0;30m"

struct Tool;
class Workshop;

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

		bool setTool(Tool* toolPtr);
		void removeShovel(Tool* toolPtr);
		void useTools();

		/// @brief method for workshop to call
		/// @param workshop 
		void registerToWorkshop(Workshop* workshop) {
			workshops.insert(workshop);
		}

		/// @brief method for workshop to call
		/// @param workshop 
		void unregisterFromWorkshop(Workshop* workshop);

		/// @brief method for unregistration from workshop by worker
		void unregisterFromWorkshopByrequest(Workshop* workshop);
		void work();
	private:
		Position coordonnee; // composition
		Statistic stat; // composition
		std::set<Tool*> tools; // aggregation
		std::set<Workshop*> workshops; // association/aggregation
		// Tool* tool; // aggregation
		std::string name;
};