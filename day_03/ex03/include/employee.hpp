#pragma once

#include <string>
#include <iostream>


class Employee 
{
	public:
		friend std::ostream& operator<<(std::ostream& os, const Employee& employee);

		// Employee(void) : hourlyValue(0), name("hidden") {}

		Employee(std::string _name, int salary) : hourlyValue(salary), name(_name), worked_hours(0) {}
		virtual ~Employee() {}
	
		int getHourlyValue() { return hourlyValue;}
		std::string get_name() { return name; }

		virtual int executeWorkday() = 0;
		virtual int calculePayroll() const = 0;
	protected:
		int hourlyValue;
		std::string name;
		int worked_hours;


};


// // the hour it will NOT do (Vacantion, sickness, any reason).
// class ContractEmployee : public Employee
// {
// 	public:
// 		ContractEmployee(std::string _name, int salary) : Employee(_name, salary) {}
// 		ContractEmployee() : Employee() {}
// };

// class Apprentice : public Employee
// {

// };