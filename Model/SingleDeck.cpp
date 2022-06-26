#include "../libs.h"
#include "Enums/StatusShip.h"
#include "Enums/TypeShip.h"

SingleDeck::SingleDeck(int x, int y):Ship(TypeShip::SingleDeckShip, StatusShip::Alive)
{
	this->_deck.setNumber(1);
	this->_deck.setX(x);
	this->_deck.setY(y);
	this->_deck.setStatus(true);
	CoordXY coord_1(x - 1, y - 1);
	CoordXY coord_2(x - 1, y + 1);
	CoordXY coord_3(x + 1, y - 1);
	CoordXY coord_4(x + 1, y + 1);
	this->_zoneDeck.setCoord_1(coord_1);
	this->_zoneDeck.setCoord_2(coord_2);
	this->_zoneDeck.setCoord_3(coord_3);
	this->_zoneDeck.setCoord_4(coord_4);
}

Deck SingleDeck::getDeck()
{
	return this->_deck;
}
