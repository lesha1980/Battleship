#include "../libs.h"
#include "Enums/StatusShip.h"
#include "Enums/TypeShip.h"

DoubleDeck::DoubleDeck(int size, bool oriental, int x, int y):MultiDeck(size, oriental)
{
	this->_status_ship = StatusShip::Alive;
	this->_type_ship = TypeShip::DoubleDeck;
	Deck _deck_1;
	Deck _deck_2;
	_deck_1.setNumber(1);
	_deck_2.setNumber(2);
	_deck_1.setStatus(true);
	_deck_2.setStatus(true);
	_deck_1.setX(x);
	_deck_1.setY(y);

	if (this->_oriental)
	{
		_deck_2.setX(x + 1);
		_deck_2.setY(y);
	}
	else {
		_deck_2.setX(x);
		_deck_2.setY(y + 1);
	}
	
}
