#include "Worker.h"

Worker::Worker() : coordonnee(Position()), stat(Statistic()), name("default name"){
	std::cout << "Worker default constructor called" << std::endl;
}

Worker::Worker(std::string _name) : coordonnee(Position()), stat(Statistic()), name(_name){
	std::cout << "Worker name constructor called" << std::endl;
}

Worker::~Worker() {
	std::cout << STD_RED << "Worker destructor called" << STD_BLACK << std::endl;
	while (!tools.empty()) {
		std::set<Tool*>::iterator it = tools.begin();
		(*it)->takeFromWorker();
		tools.erase(tools.begin());
	}

	while (!workshops.empty()) {
		std::set<Workshop*>::iterator it = workshops.begin();
		(*it)->unregisterWorkerByrequest(this);
		workshops.erase(workshops.begin());
	}
}	

Worker::Worker(const Worker& src) {
	std::cout << "Worker copy constructor called" << std::endl;
	*this = src;
}

Worker& Worker::operator=(const Worker& src) {
	std::cout << "Worker assignation operator called" << std::endl;
	if (this != &src) {
		this->coordonnee = src.coordonnee;
		this->stat = src.stat;
		this->tools = src.tools;
		name = src.name;
		workshops = src.workshops;
	}
	return *this;
}

bool Worker::setTool(Tool* toolPtr) {
	if (tools.count(toolPtr)) {
		std::cout << "Shovel already given to worker " << name  << std::endl;
		return false;
	}
	tools.insert(toolPtr);
	toolPtr->giveToWorker(this);
	std::cout << "Tool given to worker " << name  << std::endl;
	return true;
}

void Worker::removeShovel(Tool* toolPtr) {
	if (tools.count(toolPtr)) {
		tools.erase(toolPtr);
		toolPtr->takeFromWorker();
		std::cout << "Tool removed from worker " << name  << std::endl;
	} else {
		std::cout << "Worher don't have this tool" << std::endl;
	}
}

void Worker::useTools() {
	std::set<Tool*>::iterator it = tools.begin();
	while (it != tools.end()) {
		(*it)->use();
		it++;
	}
}

void Worker::unregisterFromWorkshop(Workshop* workshop) {
	std::cout << "Worker unregistered from workshop (by workshop)" << std::endl;
	if (workshops.count(workshop)) {
		workshops.erase(workshop);
	}
}

void Worker::unregisterFromWorkshopByrequest(Workshop* workshop) {
	workshops.erase(workshop);
	if (workshop) {
		workshop->unregisterWorkerByrequest(this);
	}
}

void Worker::work() {
	std::cout << "Worker " << name << " working" << std::endl;
	useTools();
}