
#include <iostream>
#include <vector>
#include "FileLogger.hpp"
#include "StreamLogger.hpp"


// DIP  high-level modules should not depend on low-level modules, and both should depend on abstractions
// use all classes through interfaces
int main() {

	std::vector<ILogger*> loggers;
	std::vector<std::string> logs;

	logs.push_back("Error message!");
	logs.push_back("Warning message!");
	logs.push_back("Info message!");

	loggers.push_back(new FileLogger("log.txt"));
	loggers.push_back(new StreamLogger(std::cout));
	// loggers.push_back(new StdoutLogger());

	for (size_t i = 0; i < logs.size(); i++) {
		for (size_t j = 0; j < loggers.size(); j++) {
			loggers[j]->write(logs[i]);
		}
	}

	for (size_t i = 0; i < loggers.size(); i++) {
		delete loggers[i];
	}

	return 0;
}