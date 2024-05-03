#pragma once 

#include <string>
#include "employee.hpp"

class SalariedEmployee : public Employee
{
	public:
		SalariedEmployee(std::string name, int salary) : Employee(name, salary), worked_days(0), not_worked_hours(0) {}
		virtual ~SalariedEmployee() {}

		virtual int executeWorkday()
		{
			worked_days += 1;
			return worked_days;
		}
		
		int addNotWorkedHours(int hours)
		{
			not_worked_hours += hours;
			return not_worked_hours;
		}

	protected:
		int worked_days;
		int not_worked_hours;
};

class ContractEmployee : public SalariedEmployee
{
	public:
		ContractEmployee(std::string name, int salary) : SalariedEmployee(name, salary) {}
		virtual ~ContractEmployee() {}

		virtual int calculePayroll() const
		{
			return hourlyValue * (worked_days * 7 - not_worked_hours);
		}
};

class Apprentice : public SalariedEmployee
{
	public:
		Apprentice(std::string name, int salary) : SalariedEmployee(name, salary), school_hours(0) {}
		virtual ~Apprentice() {}

		int attendSchool(int hours)
		{
			school_hours += hours;
			return school_hours;
		}

		virtual int calculePayroll() const
		{
			return hourlyValue * (worked_days * 7 - not_worked_hours) + school_hours * (hourlyValue / 2);
		}


	private:
		int school_hours;
};

