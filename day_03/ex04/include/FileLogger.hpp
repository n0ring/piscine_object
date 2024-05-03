#pragma once 

#include "IFileLogger.hpp"

class FileLogger : public IFileLogger
{
public:
	FileLogger(std::string fileName) : IFileLogger(fileName) {}
	~FileLogger() {}

	virtual void write_to_file(std::string message)
	{
		std::ofstream file(logFileName, std::ios::app);
		if (file.is_open())
		{
			file << getHeader() << ": " << message << std::endl;
			file.close();
		}
	}
	
	void write(std::string message) // override
	{
		write_to_file(message);
	}
private:
	FileLogger() : IFileLogger("log.txt") {}
};
