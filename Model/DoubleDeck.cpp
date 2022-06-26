#include "../libs.h"
#include "Enums/StatusShip.h"
#include "Enums/TypeShip.h"

DoubleDeck::DoubleDeck(bool oriental, int x, int y):MultiDeck(2, oriental, TypeShip::DoubleDeckShip, StatusShip::Alive)
{
	this->_deck_1;
	this-> _deck_2;
	this->_deck_1.setNumber(1);
	this->_deck_2.setNumber(2);
	this->_deck_1.setStatus(true);
	this->_deck_2.setStatus(true);
	this->_deck_1.setX(x);
	this->_deck_1.setY(y);
	CoordXY coord_1;
	CoordXY coord_2;
	CoordXY coord_3;
	CoordXY coord_4;

	if (this->_oriental)
	{
		this->_deck_2.setX(x + 1);
		this->_deck_2.setY(y);
		coord_1.setX(x - 1);
		coord_1.setY(y - 1);
		coord_2.setX(x - 1);
		coord_2.setY(y + 1);
		coord_3.setX(x + 2);
		coord_3.setY(y - 1);
		coord_4.setX(x + 2);
		coord_4.setY(y + 1);
	}
	else {
		this->_deck_2.setX(x);
		this->_deck_2.setY(y + 1);
		coord_1.setX(x - 1);
		coord_1.setY(y - 1);
		coord_2.setX(x + 1);
		coord_2.setY(y - 1);
		coord_3.setX(x - 1);
		coord_3.setY(y + 2);
		coord_4.setX(x + 1);
		coord_4.setY(y + 2);
	}

	
	this->_zoneDeck.setCoord_1(coord_1);
	this->_zoneDeck.setCoord_2(coord_2);
	this->_zoneDeck.setCoord_3(coord_3);
	this->_zoneDeck.setCoord_4(coord_4);
	
}

Deck DoubleDeck::getDeck_1()
{
	return this->_deck_1;
}

Deck DoubleDeck::getDeck_2()
{
	return this->_deck_2;
}
