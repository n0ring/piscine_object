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
	Person(std::string p_name);
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
	Secretary() = default;
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