#include "../libs.h"
#include "Enums/StatusShip.h"
#include "Enums/TypeShip.h"

FourDeck::FourDeck(bool oriental, int x, int y):MultiDeck(4, oriental)
{
	this->_status_ship = StatusShip::Alive;
	this->_type_ship = TypeShip::FourDeckShip;
	Deck _deck_1;
	Deck _deck_2;
	Deck _deck_3;
	Deck _deck_4;
	_deck_1.setNumber(1);
	_deck_2.setNumber(2);
	_deck_3.setNumber(3);
	_deck_3.setNumber(4);
	_deck_1.setStatus(true);
	_deck_2.setStatus(true);
	_deck_3.setStatus(true);
	_deck_4.setStatus(true);
	_deck_1.setX(x);
	_deck_1.setY(y);

	if (this->_oriental)
	{
		_deck_2.setX(x + 1);
		_deck_2.setY(y);
		_deck_3.setX(x + 2);
		_deck_3.setY(y);
		_deck_4.setX(x + 3);
		_deck_4.setY(y);
	}
	else {
		_deck_2.setX(x);
		_deck_2.setY(y + 1);
		_deck_3.setX(x);
		_deck_3.setY(y + 2);
		_deck_3.setX(x);
		_deck_3.setY(y + 3);
	}

	this->_deck[0] = _deck_1;
	this->_deck[1] = _deck_2;
	this->_deck[2] = _deck_3;
	this->_deck[3] = _deck_4;
}
