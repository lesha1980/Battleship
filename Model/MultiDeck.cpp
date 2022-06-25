#include "../libs.h"

MultiDeck::MultiDeck(int size)
{
	this->_size = size;
	this->_deck = new Deck[this->_size];
}

MultiDeck::~MultiDeck()
{
	delete[] this->_deck;
}
