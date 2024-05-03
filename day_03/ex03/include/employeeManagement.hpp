#pragma once

#include <set>
#include <iostream>
#include "employee.hpp"


class EmployeeManager 
{
	public:
		EmployeeManager() {}
		EmployeeManager(const EmployeeManager& other) {
			*this = other;
		}
		EmployeeManager& operator=(const EmployeeManager& other) {
			employes = other.employes;
			return *this;
		}
		~EmployeeManager() {}
		
		void addEmployee(Employee* employee)
		{
			employes.insert(employee);
		}
		void removeEmployee(Employee* employee)
		{
			if (employes.count(employee))
			{
				employes.erase(employee);
			}
		}
		void executeWorkday()
		{
			std::set<Employee*>::iterator it = employes.begin();
			std::set<Employee*>::iterator ite = employes.end();
			while (it != ite)
			{
				(*it)->executeWorkday();
				it++;
			}
		}
		void calculatePayroll()
		{
			std::set<Employee*>::iterator it = employes.begin();
			std::set<Employee*>::iterator ite = employes.end();
			while (it != ite)
			{
				std::cout << (*it)->get_name() << "'s payroll: " << (*it)->calculePayroll() << std::endl;
				it++;
			}
		}
	private: 
		std::set<Employee*> employes;

};