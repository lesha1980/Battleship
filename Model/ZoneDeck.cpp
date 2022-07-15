#include "../libs.h"

ZoneDeck::ZoneDeck()
{

}

ZoneDeck::ZoneDeck(CoordXY coord_1, CoordXY coord_2, CoordXY coord_3, CoordXY coord_4)
{
	this->_coord_1 = coord_1;
	this->_coord_2 = coord_2;
	this->_coord_3 = coord_3;
	this->_coord_4 = coord_4;
}

CoordXY ZoneDeck::getCoord_1()
{
	return this->_coord_1;
}

CoordXY ZoneDeck::getCoord_2()
{
	return this->_coord_2;
}

CoordXY ZoneDeck::getCoord_3()
{
	return this->_coord_3;
}

CoordXY ZoneDeck::getCoord_4()
{
	return this->_coord_4;
}

void ZoneDeck::setCoord_1(CoordXY coord_1)
{
	this->_coord_1 = coord_1;
}

void ZoneDeck::setCoord_2(CoordXY coord_2)
{
	this->_coord_2 = coord_2;
}

void ZoneDeck::setCoord_3(CoordXY coord_3)
{
	this->_coord_3 = coord_3;
}

void ZoneDeck::setCoord_4(CoordXY coord_4)
{
	this->_coord_4 = coord_4;
}
