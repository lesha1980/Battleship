#include "../libs.h"

CoordXY::CoordXY()
{
	this->_x = -10;
	this->_y = -10;
}

CoordXY::CoordXY(int x, int y)
{
	this->_x = x;
	this->_y = y;
}

int CoordXY::getX()
{
	return this->_x;
}

int CoordXY::getY()
{
	return this->_y;
}

void CoordXY::setX(int x)
{
	this->_x = x;
}

void CoordXY::setY(int y)
{
	this->_y = y;
}

CoordXY CoordXY::operator+(CoordXY& coord)
{
	this->_x += coord.getX();
	this->_y += coord.getY();
	return *this;
}

CoordXY CoordXY::operator-(CoordXY& coord)
{
	this->_x -= coord.getX();
	this->_y -= coord.getY();
	return *this;
}

bool CoordXY::operator<(const CoordXY& coord)
{
	return false;
}

bool CoordXY::operator>(const CoordXY& coord)
{
	return false;
}

bool CoordXY::operator<=(const CoordXY& coord)
{
	return false;
}

bool CoordXY::operator>=(const CoordXY& coord)
{
	return false;
}

bool CoordXY::operator==(const CoordXY& coord)
{
	return false;
}

bool CoordXY::operator!=(const CoordXY& coord)
{
	return false;
}
