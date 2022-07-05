#include "../libs.h"

BattleShipGenerateService::BattleShipGenerateService()
{
	this->_ships = new Ship*[10];
	this->_count = 0;
}

Ship* BattleShipGenerateService::CreateSingleDeck(int x, int y)
{
	return new SingleDeck(x, y);
}

Ship* BattleShipGenerateService::CreateDoubleDeck(int x, int y, bool oriental)
{
	return new DoubleDeck(oriental, x, y);
}

Ship* BattleShipGenerateService::CreateThreeDeck(int x, int y, bool oriental)
{
	return new ThreeDeck(oriental, x, y);
}

Ship* BattleShipGenerateService::CreateFourDeck(int x, int y, bool oriental)
{
	return new FourDeck(oriental, x, y);
}

void BattleShipGenerateService::setShip(Ship* ship)
{
		this->_ships[this->_count] = ship;
		this->_count++;
}

void BattleShipGenerateService::logicDelShip()
{
	this->_count--;
}




/*Ship** BattleShipGenerateService::getShips()
{
	return this->_ships;
}
*/

int BattleShipGenerateService::getCount()
{
	return this->_count;
}

void BattleShipGenerateService::setCount(int count)
{
	this->_count = count;
}

Ship* BattleShipGenerateService::operator[](int index)
{
	return this->_ships[index];
}



BattleShipGenerateService::~BattleShipGenerateService()
{
	for (size_t i = 0; i < this->_count; i++) {
	    delete this->_ships[i];
	}
	delete[] this->_ships;
	
}




