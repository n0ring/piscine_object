#pragma once 

#include <iostream>
#include <vector>
#include <memory>
#include "persons.hpp"
#include "rooms.hpp"

class Professor;
class Student;



class Course
{
public:
	Course() = default;
	Course(std::string p_name) : _name(p_name) {}
	~Course() {}
	Course& operator=(const Course& p_course); 
	Course(const Course& p_course); 

	void assign(Professor* p_professor) {_responsable = p_professor;}
	bool subscribe(Student* p_student);
	bool assignToClassRoom(std::shared_ptr<Classroom> p_classroom);
	Classroom* getClassRoom() {return _classroom;}
	void setNumberOfClasToGraduate(int n) { _numberOfClassToGraduate = n; }
	void setMaxNumberOfStudents(int n ) { _maximumNumberOfStudent = n; }

	int getNumberOfClassToGraduate() const {return _numberOfClassToGraduate;}
	int getMaximumNumberOfStudent() const {return _maximumNumberOfStudent;}
	std::string getName() {return _name;}
	void teachStudent();
	bool isPersonAssignedToCourse(Person* p_person);


private:
	std::string _name;
	Professor* _responsable;
	std::vector<Student*> _students;
	int _numberOfClassToGraduate;
	int _maximumNumberOfStudent;
	Classroom* _classroom;
	
};

