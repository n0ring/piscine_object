#pragma once 

#include <iostream>
#include <vector>
#include <memory>

class Professor;
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

	void assign(Professor* p_professor) {_responsable = p_professor;}
	bool subscribe(Student* p_student);
	void setNumberOfClasToGraduate(int n) { _numberOfClassToGraduate = n; }
	void setMaxNumberOfStudents(int n ) { _maximumNumberOfStudent = n; }
	
	int getNumberOfClassToGraduate() const {return _numberOfClassToGraduate;}
	int getMaximumNumberOfStudent() const {return _maximumNumberOfStudent;}
	std::string getName() {return _name;}
private:
	std::string _name;
	Professor* _responsable;
	std::vector<Student*> _students;
	int _numberOfClassToGraduate;
	int _maximumNumberOfStudent;
};

