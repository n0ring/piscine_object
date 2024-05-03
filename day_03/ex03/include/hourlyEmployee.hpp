#pragma once 

#include <string>
#include "employee.hpp"

class HourlyEmployee : public Employee
{
	public:
		HourlyEmployee(std::string name, int salary) : Employee(name, salary) {}
		virtual ~HourlyEmployee() {}

		virtual int executeWorkday()
		{
			worked_hours += 7;
			return worked_hours;
		}
};

// register every work hour it will do. 
// mobilise it for some hours
class TempWorker : public HourlyEmployee
{
	public:
		TempWorker(std::string name, int salary) : HourlyEmployee(name, salary) {}
		virtual ~TempWorker() {}

		int mobilise(int hours)
		{
			worked_hours += hours;
			return worked_hours;
		}

		virtual int calculePayroll() const
		{
			return hourlyValue * worked_hours;
		}
	};