
#include <iostream>
#include "employeeManagement.hpp"
#include "hourlyEmployee.hpp"
#include "salariedEmployee.hpp"

int main() {
	EmployeeManager manager;

	TempWorker w1("Elon", 42);
	ContractEmployee w2("Jeff", 69);
	Apprentice w3("Bill", 2);

	manager.addEmployee(&w1);
	manager.addEmployee(&w2);
	manager.addEmployee(&w3);

	w2.addNotWorkedHours(3);
	w3.attendSchool(5);
	w3.addNotWorkedHours(2);
	
	manager.executeWorkday();
	manager.calculatePayroll();

	return 0;
}