#include "../libs.h"

MultiDeck::MultiDeck(int size, bool oriental, TypeShip typeShip, StatusShip statusShip): Ship(typeShip, statusShip)
{
	this->_size = size;
	this->_oriental = oriental;
	
}

MultiDeck::~MultiDeck()
{
	
}
