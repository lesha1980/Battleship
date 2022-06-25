#include "../libs.h"
#include "Enums/StatusShip.h"
#include "Enums/TypeShip.h"

SingleDeck::SingleDeck(int x, int y)
{
	this->_deck.setNumber(1);
	this->_deck.setX(x);
	this->_deck.setY(y);
	this->_deck.setStatus(true);
	this->_type_ship = TypeShip::SingleDeck;
	this->_status_ship = StatusShip::Alive;
}
