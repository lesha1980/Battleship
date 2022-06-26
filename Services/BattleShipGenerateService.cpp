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

void BattleShipGenerateService::CreateDataSingleShip(Ship* (*SingleDeckCreatorPtr)(int, int), int x, int y, int index)
{
		Ship* _ship = SingleDeckCreatorPtr(x, y);
		this->_ships[index] = _ship;
		this->_count++;
}

void BattleShipGenerateService::CreateDataDoubleShip(Ship* (*MultiDeckCreatorPtr)(int x, int y, bool oriental), int x, int y, bool oriental, int index)
{
	Ship* _ship = MultiDeckCreatorPtr(x, y, oriental);
	this->_ships[index] = _ship;
	this->_count++;
}

Ship** BattleShipGenerateService::getShips()
{
	return this->_ships;
}

int BattleShipGenerateService::getCount()
{
	return this->_count;
}

Ship* BattleShipGenerateService::operator[](int index)
{
	return this->_ships[index];
}



BattleShipGenerateService::~BattleShipGenerateService()
{
	for (size_t i = 0; i < 10; i++) {
	    delete this->_ships[i];
	}
	delete[] this->_ships;
}




