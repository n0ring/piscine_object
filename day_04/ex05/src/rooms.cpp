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

bool Room::canEnter(Person*)
{
	return true;
}

void Room::enter(Person* p_person)
{
	_occupants.insert(p_person);
}
void Room::exit(Person* p_person)
{
	if (_occupants.count(p_person))
		_occupants.erase(p_person);
}

void Classroom::assignCourse(Course* p_course)
{
	_currentCourse = p_course;
}

void Room::printOccupant()
{
	std::cout << "[";
	for (auto it = _occupants.begin(); it != _occupants.end(); it++)
	{
		std::cout << (*it)->getName() << " ";
	}
	std::cout << "]" << std::endl;
}

void Classroom::printOccupant()
{
	std::cout << "Classroom: "  << _roomName;
	if (_currentCourse)
		std::cout << "Course: " << _currentCourse->getName() << " ";
	Room::printOccupant();
}

bool Classroom::canEnter(Person* p_person)
{
	(void) p_person;
	if (_currentCourse)
	{
		if (_currentCourse->isPersonAssignedToCourse(p_person))
			return true;
	}
	return false;
}

void  Classroom::enter(Person* p_person)
{
	if (canEnter(p_person))
		Room::enter(p_person);
}



