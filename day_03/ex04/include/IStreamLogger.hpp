#pragma once
#include <iostream>
#include "ILogger.hpp"

class IStreamLogger : public HeaderLogger
{
public:
	IStreamLogger(std::ostream& stream) : logStream(stream) {}
	virtual ~IStreamLogger() {}
	
	virtual void write_to_ostream(std::string message) = 0;
protected:
	std::ostream& logStream;
};