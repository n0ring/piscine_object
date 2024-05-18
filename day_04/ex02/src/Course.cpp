#include "course.hpp"

Course& Course::operator=(const Course& p_course)
{
	if (this == &p_course)
		return (*this);
	_name = p_course._name;
	_responsable = p_course._responsable;
	_students = p_course._students;
	_numberOfClassToGraduate = p_course._numberOfClassToGraduate;
	_maximumNumberOfStudent = p_course._maximumNumberOfStudent;
	return (*this);
}
Course::Course(const Course& p_course)
{
	*this = p_course;
}
