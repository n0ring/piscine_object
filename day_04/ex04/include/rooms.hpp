#pragma once 

#include <iostream>
#include <vector>
#include <memory>
#include <set>
#include "course.hpp"

class Form;
class Course;
class Person;

class Room
{
private:
	long long ID;
	std::set<Person* > _occupants;

public:
	Room() = default;
	virtual ~Room() {}
	Room& operator=(const Room& p_room);
	Room(const Room& p_room);
	bool canEnter(Person*);
	void enter(Person*);
	void exit(Person*);
	
	void printOccupant();
};

class Classroom : public Room
{
private:
	std::shared_ptr<Course> _currentCourse;
	std::string _roomName;
public:
	Classroom() {}
	Classroom(std::string p_name) : _roomName(p_name) {}
	void assignCourse(std::shared_ptr<Course> p_course);
	void printOccupant();
	bool canEnter(Person*);
	void enter(Person*);

};

class SecretarialOffice: public Room
{
private:
	std::vector<std::shared_ptr<Form> > _archivedForms;

public:
};

class HeadmasterOffice : public Room
{
private:

public:

};

class StaffRestRoom : public Room
{
private:

public:

};

class Courtyard : public Room
{
private:

public:

};