#pragma once 

#include <iostream>
#include <stack>
#include <memory>
#include "forms.hpp"

class Form;
class CourseFinishedForm;
class NeedMoreClassRoomForm;
class NeedCourseCreationForm;
class SubscriptionToCourseForm;
class Course;
class Room;
class Classroom;

class Person
{
private:
	std::string _name;
	std::shared_ptr<Room> _currentRoom;
public:
	Person() = default;
	Person(std::string p_name);
	virtual ~Person() {}
	Person& operator=(const Person& p_person);
	Person(const Person& p_person);

	std::shared_ptr<Room> room() {return (_currentRoom);}
};

class Staff : public Person
{
private:

public:
	void sign(std::shared_ptr<Form> p_form) {p_form->sigh();}
};

class Student : public Person
{
private:
	std::vector<std::shared_ptr<Course> > _subscribedCourse;

public:
	Student() = default;
	Student(std::string p_name) : Person(p_name) {}
	~Student() {}
	Student& operator=(const Student& p_student);
	Student(const Student& p_student);
	
	void attendClass(std::shared_ptr<Classroom> p_classroom);
	void exitClass();
	void graduate(std::shared_ptr<Course> p_course);

};

class Headmaster : public Staff
{
private:
	std::stack<std::shared_ptr<Form> > _formToValidate;
	
public:
	void receiveForm(std::shared_ptr<Form> p_form) {_formToValidate.push(p_form);}
	
	bool validateForm(std::shared_ptr<Form> p_form) {return p_form->getTextForm().empty() == false;}
	bool executeForm(std::shared_ptr<Form> p_form);
	void formProcessing();
};

class Secretary : public Staff
{
private:

public:
	std::shared_ptr<Form> createForm(FormType p_formType);
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