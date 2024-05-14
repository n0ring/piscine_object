#include <memory>
#include <iostream>
#include <thread>
#include "ListSingletons.hpp"
#include "persons.hpp"
#include "forms.hpp"


// factory method patter to create the form (secretary.createForm) 
// command pattern: the headmaster will receive the form, process it and execute it
// form here is like a command
// headmaster is the invoker and receiver

// TODO assigh students to course 
// TODO students attend course
int main() {
	std::cout << "<--Test for graduate path-->\n";

	std::shared_ptr<Headmaster> headmasterPtr = std::make_shared<Headmaster>();
	std::shared_ptr<Professor> professorPtr = std::make_shared<Professor>("McGonagall", headmasterPtr);
	std::shared_ptr<Professor> professorPtr2 = std::make_shared<Professor>("Snape", headmasterPtr);
	std::shared_ptr<Student> studentPtr = std::make_shared<Student>("Harry Potter", headmasterPtr);

	std::shared_ptr<Course> coursePtr = professorPtr->createCourse("Defense Against the Dark Arts", 10, 30);

	professorPtr->gradeStudent(studentPtr, coursePtr);
	
	std::cout << "<--Test for create course path->\n";

	std::shared_ptr<Course> course = professorPtr->createCourse("Transfiguration", 10, 30);
	if (course == nullptr) {
		std::cout << "Course not created\n";
		return 1;
	}
	std::cout << "Course created: " << course->getName() <<  " with " << course->getNumberOfClassToGraduate() << " classes to graduate and " << course->getMaximumNumberOfStudent() << " students\n";
	CourseList::getInstance().addElement(course);

	std::cout << "<-- Test for subscribe student to course path-->\n";
	std::shared_ptr<Course> course2 = professorPtr2->createCourse("Potions", 10, 30);
	if (course2 == nullptr) {
		std::cout << "Course not created\n";
		return 1;
	}
	studentPtr->subscribeToCourse(course2);


	return 0;
}