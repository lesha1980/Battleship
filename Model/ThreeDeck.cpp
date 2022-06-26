#include "../libs.h"
#include "Enums/StatusShip.h"
#include "Enums/TypeShip.h"

ThreeDeck::ThreeDeck(bool oriental, int x, int y):MultiDeck(3, oriental, TypeShip::ThreeDeckShip, StatusShip::Alive)
{
	this->_deck_1;
	this->_deck_2;
	this->_deck_3;
	this->_deck_1.setNumber(1);
	this->_deck_2.setNumber(2);
	this->_deck_3.setNumber(3);
	this->_deck_1.setStatus(true);
	this->_deck_2.setStatus(true);
	this->_deck_3.setStatus(true);
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
		this->_deck_3.setX(x + 2);
		this->_deck_3.setY(y);

		coord_1.setX(x - 1);
		coord_1.setY(y - 1);
		coord_2.setX(x - 1);
		coord_2.setY(y + 1);
		coord_3.setX(x + 3);
		coord_3.setY(y - 1);
		coord_4.setX(x + 3);
		coord_4.setY(y + 1);
	}
	else {
		this->_deck_2.setX(x);
		this->_deck_2.setY(y + 1);
		this->_deck_3.setX(x);
		this->_deck_3.setY(y + 2);

		coord_1.setX(x - 1);
		coord_1.setY(y - 1);
		coord_2.setX(x + 1);
		coord_2.setY(y - 1);
		coord_3.setX(x - 1);
		coord_3.setY(y + 3);
		coord_4.setX(x + 1);
		coord_4.setY(y + 3);
	}

	this->_zoneDeck.setCoord_1(coord_1);
	this->_zoneDeck.setCoord_2(coord_2);
	this->_zoneDeck.setCoord_3(coord_3);
	this->_zoneDeck.setCoord_4(coord_4);

}

Deck ThreeDeck::getDeck_1()
{
	return this->_deck_1;
}

Deck ThreeDeck::getDeck_2()
{
	return this->_deck_2;
}

Deck ThreeDeck::getDeck_3()
{
	return this->_deck_3;
}

ZoneDeck ThreeDeck::getZoneDeck()
{
	return this->_zoneDeck;
}
