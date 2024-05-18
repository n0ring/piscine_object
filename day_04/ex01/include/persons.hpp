#pragma once 

#include <iostream>
#include <vector>
#include <memory>

class Form;
class Course;
class Room;
class Classroom;
class FormType;


class Person
{
private:
	std::string _name;
	std::shared_ptr<Room> _currentRoom;
public:
	Person() = default;
	Person(std::string p_name);
	virtual ~Person() {}
	Person& operator=(const Person& p_person)
	{
		_name = p_person._name;
		_currentRoom = p_person._currentRoom;
		return (*this);
	}
	Person(const Person& p_person)
	{
		_name = p_person._name;
		_currentRoom = p_person._currentRoom;
	}
	std::shared_ptr<Room> room() {return (_currentRoom);}
};

class Staff : public Person
{
private:

public:
	void sign(std::shared_ptr<Form> p_form);
};

class Student : public Person
{
private:
	std::vector<std::shared_ptr<Course> > _subscribedCourse;

public:
	Student() = default;
	Student(std::string p_name) : Person(p_name) {}
	~Student() {}
	Student& operator=(const Student& p_student)
	{
		_subscribedCourse = p_student._subscribedCourse;
		return (*this);
	}
	Student(const Student& p_student)
	{
		_subscribedCourse = p_student._subscribedCourse;
	}
	
	void attendClass(std::shared_ptr<Classroom> p_classroom);
	void exitClass();
	void graduate(std::shared_ptr<Course> p_course);

};

class Headmaster : public Staff
{
private:
	std::vector<std::shared_ptr<Form> > _formToValidate;
	
public:
	void receiveForm(std::shared_ptr<Form> p_form);
};

class Secretary : public Staff
{
private:

public:
	Form* createForm(FormType p_formType);
	void archiveForm();
};

class Professor : public Staff
{
private:
	std::shared_ptr<Course> _currentCourse;

public:
	void assignCourse(std::shared_ptr<Course> p_course);
	void doClass();
	void closeCourse();
};