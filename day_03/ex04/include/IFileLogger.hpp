#pragma once 

#include "ILogger.hpp"

class IFileLogger : public HeaderLogger
{
public:
	IFileLogger(std::string fileName) : logFileName(fileName) {}
	virtual ~IFileLogger() {}
	
	virtual void write_to_file(std::string) = 0;
protected:
	std::string logFileName;
};
