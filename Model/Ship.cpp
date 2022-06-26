#include "../libs.h"

Ship::Ship(TypeShip type_ship, StatusShip status_ship)
{
	this->_status_ship = status_ship;
	this->_type_ship = type_ship;
}

TypeShip Ship::getTypeShip()
{
	return this->_type_ship;
}

StatusShip Ship::getStatusShip()
{
	return this->_status_ship;
}
