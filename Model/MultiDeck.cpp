#include "../libs.h"

MultiDeck::MultiDeck(int size, bool oriental)
{
	this->_size = size;
	this->_oriental = oriental;
	this->_deck = new Deck[this->_size];
}

MultiDeck::~MultiDeck()
{
	delete[] this->_deck;
}
