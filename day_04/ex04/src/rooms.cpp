#include "rooms.hpp"

Room& Room::operator=(const Room& p_room)
{
	if (this == &p_room)
		return (*this);
	ID = p_room.ID;
	_occupants = p_room._occupants;
	return (*this);
}
Room::Room(const Room& p_room)
{
	ID = p_room.ID;
	_occupants = p_room._occupants;
}

bool Room::canEnter(std::shared_ptr<Person>)
{
	return true;
}

void Room::enter(std::shared_ptr<Person> p_person)
{
	_occupants.insert(p_person);
}
void Room::exit(std::shared_ptr<Person> p_person)
{
	if (_occupants.count(p_person))
		_occupants.erase(p_person);
}

void Classroom::assignCourse(std::shared_ptr<Course> p_course)
{
	_currentCourse = p_course;
}

void Room::printOccupant()
{
	for (auto it = _occupants.begin(); it != _occupants.end(); it++)
	{
		std::cout << (*it)->getName() << std::endl;
	}
}

void Classroom::printOccupant()
{
	std::cout << "Classroom: " << _roomName << std::endl;
	if (_currentCourse)
		std::cout << "Course: " << _currentCourse->getName() << std::endl;
	Room::printOccupant();
}

bool Classroom::canEnter(std::shared_ptr<Person> p_person)
{
	if (_currentCourse)
	{
		if (_currentCourse->isPersonAssignedToCourse(p_person.get()))
			return true;
	}
	return false;
}

void  Classroom::enter(std::shared_ptr<Person> p_person)
{
	if (canEnter(p_person))
		Room::enter(p_person);
}



