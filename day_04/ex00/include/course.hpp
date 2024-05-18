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
	Course(std::string p_name);
	void assign(std::shared_ptr<Professor> p_professor);
	void subscribe(std::shared_ptr<Student> p_student);
private:
	std::string _name;
	std::shared_ptr<Professor> _responsable;
	std::vector<std::shared_ptr<Student>> _students;
	int _numberOfClassToGraduate;
	int _maximumNumberOfStudent;
};

