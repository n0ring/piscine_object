#include <memory>
#include <iostream>
#include <thread>
#include "ListSingletons.hpp"
#include "persons.hpp"
#include "forms.hpp"
#include "School.hpp"


int main() {
	School school;
	school.graduationCeremony();
	school.runDayRoutine();
	school.runDayRoutine();
	school.graduationCeremony();

	return 0;
}