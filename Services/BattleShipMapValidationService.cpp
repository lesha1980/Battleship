#include "../libs.h"

BattleShipMapValidationService::BattleShipMapValidationService(BattleMapGenerateService mapGenerateService, BattleShipGenerateService shipGenerateService)
{
	this->_mapGenerateService = mapGenerateService;
	this->_shipGenerateService = shipGenerateService;
}

bool BattleShipMapValidationService::shipPlacingValidation(int x, int y, TypeShip typeShip, bool oriental)
{
	GameBoard _gb = this->_mapGenerateService.getGameBoard();
	int columns = _gb.getColumns();
	int rows = _gb.getRows();
	// перевіряємо чи виходимо за кордони гральної дошки
	if (x > columns || y > rows) {
			return false;
	}

	switch (typeShip) {
	case TypeShip::DoubleDeckShip:
	{
		if (oriental) {
			if (x + 1 > columns) {
				return false;
			}
		}
		else {
			if (y + 1 > rows)
			{
				return false;
			}
		}
	}
	break;
	case TypeShip::ThreeDeckShip: 
	{
		if (oriental) {
			if (x + 2 > columns) {
				return false;
			}
		}
		else {
			if (y + 2 > rows)
			{
				return false;
			}
		}
	}
	break;
	case TypeShip::FourDeckShip:
	{
		if (oriental) {
			if (x + 3 > columns) {
				return false;
			}
		}
		else {
			if (y + 3 > rows)
			{
				return false;
			}
		}
	}
	break;
	}
	
	//перевіряємо розміщення корабля відносно інших кораблів

	for (size_t i = 0; i < this->_shipGenerateService.getCount(); i++) {
		Ship* _ship = this->_shipGenerateService[i];
		if (typeid(SingleDeck) == typeid(_ship))
		{
			SingleDeck* sdeck = (SingleDeck*)_ship;
			
		}
	}
	
	
	return true;
}
