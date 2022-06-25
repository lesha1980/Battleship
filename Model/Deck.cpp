#include "../libs.h"


Deck::Deck()
{
	this->_x = 0;
	this->_y = 0;
	this->_number = 0;
	this->_status = false;
}

Deck::Deck(int x, int y, int number)
{
	this->_x = x;
	this->_y = y;
	this->_number = number;
	this->_status = true;
}

void Deck::setX(int x)
{
	this->_x = x;
}

void Deck::setY(int y)
{
	this->_y = y;
}

void Deck::setNumber(int number)
{
	this->_number = number;
}

void Deck::setStatus(bool status)
{
	this->_status = status;
}

int Deck::getX()
{
	return this->_x;
}

int Deck::getY()
{
	return this->_y;
}

int Deck::getNumber()
{
	return this->_number;
}

bool Deck::getStatus()
{
	return this->_status;
}
