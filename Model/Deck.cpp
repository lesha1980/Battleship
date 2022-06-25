#include "../libs.h"


Deck::Deck()
{
}

Deck::Deck(int x, int y)
{
	this->_x = x;
	this->_y = y;
}

void Deck::setX(int x)
{
	this->_x = x;
}

void Deck::setY(int y)
{
	this->_y = y;
}

int Deck::getX()
{
	return this->_x;
}

int Deck::getY()
{
	return this->_y;
}
