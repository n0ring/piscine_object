#pragma once 

#include <iostream>
#include <fstream>
#include <ctime>

class ILogger
{
public:
	ILogger() {}
	virtual ~ILogger() {}
	
	virtual void write(std::string) = 0;
};

class HeaderLogger : public ILogger
{
public:
	HeaderLogger() {}
	~HeaderLogger() {}

	std::string getHeader()
	{
		std::string header;
		time_t now = time(0);
		tm *ltm = localtime(&now);
		header = std::to_string(1900 + ltm->tm_year) + "/" + std::to_string(1 + ltm->tm_mon) + "/" + std::to_string(ltm->tm_mday) + " ";
		header.append(std::to_string(1 + ltm->tm_hour) + ":" + std::to_string(1 + ltm->tm_min) + ":" + std::to_string(1 + ltm->tm_sec));
		return header;
	}	
};
