#pragma once 

#include "IStreamLogger.hpp"

class StreamLogger : public IStreamLogger
{
public:
	StreamLogger(std::ostream&stream) : IStreamLogger(stream) {}
	~StreamLogger() {}
	
	virtual void write_to_ostream(std::string message)
	{
		logStream << getHeader() << ": " << message << std::endl;
	}
	
	virtual void write(std::string message) // override
	{
		write_to_ostream(message);
	}
};