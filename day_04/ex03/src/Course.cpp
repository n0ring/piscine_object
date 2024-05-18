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

bool Course::subscribe(Student* p_student)
{
	if (_students.size() < static_cast<size_t>(_maximumNumberOfStudent))
	{
		_students.push_back(p_student);
		return true;
	}
	{
		_students.push_back(p_student);
		return true;
	}
	std::cout << "Course is full" << std::endl;
	return false;
}


void Course::teachStudent()
{
	std::cout << "Course: " << _name << " teaching student" << std::endl;
	for (auto& student : _students)
	{
		student->attendCourse(this);
	}
}

bool Course::assignToClassRoom(std::shared_ptr<Classroom> p_classroom)
{
	if (p_classroom)
	{
		std::cout << "Course: " << _name << " is assigned to classroom" << std::endl;
		_classroom = p_classroom;
		return true;
	}
	return false;
}

