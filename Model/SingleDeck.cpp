#include "../libs.h"
#include "Enums/StatusShip.h"
#include "Enums/TypeShip.h"

SingleDeck::SingleDeck(int x, int y):Ship(TypeShip::SingleDeckShip, StatusShip::Alive)
{
	this->_deck.setNumber(1);
	this->_deck.setX(x);
	this->_deck.setY(y);
	this->_deck.setStatus(true);
}

Deck SingleDeck::getDeck()
{
	return this->_deck;
}
