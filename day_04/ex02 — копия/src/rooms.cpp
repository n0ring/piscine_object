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