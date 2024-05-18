#pragma once 

#include <iostream>
#include <vector>
#include <memory>

class Professor;
class Student;
class Student;

enum class Event
{
	RingBell
};

class Course
{
public:
	Course() = default;
	Course(std::string p_name) : _name(p_name) {}
	~Course() {}
	Course& operator=(const Course& p_course); // in cpp
	Course(const Course& p_course); // in cpp

	void assign(std::shared_ptr<Professor> p_professor) {_responsable = p_professor;}
	void subscribe(std::shared_ptr<Student> p_student) {_students.push_back(p_student);}
	int getNumberOfClassToGraduate() {return _numberOfClassToGraduate;}
	int getMaximumNumberOfStudent() {return _maximumNumberOfStudent;}

private:
	std::string _name;
	std::shared_ptr<Professor> _responsable;
	std::vector<std::shared_ptr<Student>> _students;
	int _numberOfClassToGraduate;
	int _maximumNumberOfStudent;
};

