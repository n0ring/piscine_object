#include <memory>
#include <iostream>
#include <thread>
#include "ListSingletons.hpp"
#include "persons.hpp"
#include "forms.hpp"

// observer 

// TODO attend class (in, out) for students and professors by cmd from headmaster


// factory method patter to create the form (secretary.createForm) 
// command pattern: the headmaster will receive the form, process it and execute it
// form here is like a command
// headmaster is the invoker and receiver

int main() {
	std::cout << "<--Test for graduate path-->\n";

	std::shared_ptr<Headmaster> headmasterPtr = std::make_shared<Headmaster>();
	StaffList::getInstance().addElement(headmasterPtr);
	std::shared_ptr<Professor> professorPtr = std::make_shared<Professor>("McGonagall", headmasterPtr);
	StaffList::getInstance().addElement(professorPtr);
	std::shared_ptr<Professor> professorPtr2 = std::make_shared<Professor>("Snape", headmasterPtr);
	StaffList::getInstance().addElement(professorPtr2);
	std::shared_ptr<Student> studentPtr = std::make_shared<Student>("Harry Potter", headmasterPtr);
	StudentList::getInstance().addElement(studentPtr);
	std::shared_ptr<Course> coursePtr = professorPtr->createCourse("Defense Against the Dark Arts", 10, 30);
	CourseList::getInstance().addElement(coursePtr);
	professorPtr->gradeStudent(studentPtr, coursePtr);
	
	std::cout << "<--Test for create course path->\n";

	std::shared_ptr<Course> course = professorPtr->createCourse("Transfiguration", 10, 30);
	if (course == nullptr) {
		std::cout << "Course not created\n";
		return 1;
	}
	std::cout << "Course created: " << course->getName() <<  " with " << course->getNumberOfClassToGraduate() << " classes to graduate and " << course->getMaximumNumberOfStudent() << " students\n";

	std::cout << "<-- Test for subscribe student to course path-->\n";
	std::shared_ptr<Course> course2 = professorPtr2->createCourse("Potions", 1, 30);
	CourseList::getInstance().addElement(course2);
	if (course2 == nullptr) {
		std::cout << "Course not created\n";
		return 1;
	}

	std::shared_ptr<Classroom> classroom = professorPtr2->createClassRoom("Secret room");
	RoomList::getInstance().addElement(classroom);
	professorPtr2->setClassRoom(course2, classroom);
	classroom->assignCourse(course2);
	
	studentPtr->subscribeToCourse(course2);

	// professorPtr2->gradeStudent(studentPtr, course2);
	// professorPtr2->teach();
	// professorPtr2->gradeStudent(studentPtr, course2);

	// classroom enter test
	std::cout << std::endl;

	classroom->enter(studentPtr.get());
	classroom->enter(professorPtr2.get());
	classroom->printOccupant();

	classroom->exit(studentPtr.get());
	classroom->exit(professorPtr2.get());
	classroom->printOccupant();

	// observer test
	//  TODO add student

	std::cout << "<--Test for observer-->\n";
	professorPtr2->gradeStudent(studentPtr, course2);

	headmasterPtr->attach(professorPtr2.get());
	headmasterPtr->attach(studentPtr.get());

	headmasterPtr->notify(Event::RingBell);
	headmasterPtr->notify(Event::RingBell);

	professorPtr2->gradeStudent(studentPtr, course2);


	return 0;
}