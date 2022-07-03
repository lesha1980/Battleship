#include "../libs.h"


void BattleShipMapValidationService::initShipMapValidationService(BattleMapGenerateService mapGenerateService, BattleShipGenerateService shipGenerateService)
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
		if (_ship->getTypeShip() == TypeShip::SingleDeckShip) {
		    SingleDeck sdeck =(SingleDeck&)_ship;
			ZoneDeck d = sdeck.getZoneDeck();
			bool result = checkZoneDeck(d, x, y, typeShip, oriental);
			if (!result)
				return false;

		}
		if (_ship->getTypeShip() == TypeShip::DoubleDeckShip)
		{
			DoubleDeck ddeck = (DoubleDeck&)_ship;
			ZoneDeck d = ddeck.getZoneDeck();
			bool result = checkZoneDeck(d, x, y, typeShip, oriental);
			if (!result)
				return false;			
			
		}
		if (typeShip == TypeShip::ThreeDeckShip) {
			ThreeDeck tdeck = (ThreeDeck&)_ship;
			ZoneDeck d = tdeck.getZoneDeck();

			bool result = checkZoneDeck(d, x, y, typeShip, oriental);
			if (!result)
				return false;
		}
		if (typeShip == TypeShip::FourDeckShip) {
			FourDeck fdeck = (FourDeck&)_ship;
			ZoneDeck d = fdeck.getZoneDeck();
			bool result = checkZoneDeck(d, x, y, typeShip, oriental);
			if (!result)
				return false;
		}
	}
	
	
	return true;
}

bool BattleShipMapValidationService::checkZoneDeck(ZoneDeck d, int x, int y, TypeShip typeShip, bool oriental)
{
	switch (typeShip) {
	case TypeShip::SingleDeckShip: {
		if (x >= d.getCoord_1().getX() && x <= d.getCoord_3().getX() &&
			y >= d.getCoord_1().getY() && y <= d.getCoord_3().getY())
			return false;
	}break;
	case TypeShip::DoubleDeckShip: {
		if (x >= d.getCoord_1().getX() && x <= d.getCoord_3().getX() &&
			y >= d.getCoord_1().getY() && y <= d.getCoord_3().getY())
			return false;
		if (oriental) {
			if (x + 1 >= d.getCoord_1().getX() && x + 1 <= d.getCoord_3().getX() &&
				y >= d.getCoord_1().getY() && y <= d.getCoord_3().getY())
				return false;
		}
		else {
			if (x >= d.getCoord_1().getX() && x <= d.getCoord_3().getX() &&
				y + 1 >= d.getCoord_1().getY() && y + 1 <= d.getCoord_3().getY())
				return false;
		}

	}break;
	case TypeShip::ThreeDeckShip: {
		if (x >= d.getCoord_1().getX() && x <= d.getCoord_3().getX() &&
			y >= d.getCoord_1().getY() && y <= d.getCoord_3().getY())
			return false;
		if (oriental) {

			if (x + 2 >= d.getCoord_1().getX() && x + 2 <= d.getCoord_3().getX() &&
				y >= d.getCoord_1().getY() && y <= d.getCoord_3().getY())
				return false;
		}
		else {
			if (x >= d.getCoord_1().getX() && x <= d.getCoord_3().getX() &&
				y + 2 >= d.getCoord_1().getY() && y + 2 <= d.getCoord_3().getY())
				return false;
		}

	}break;
	case TypeShip::FourDeckShip: {
		if (x >= d.getCoord_1().getX() && x <= d.getCoord_3().getX() &&
			y >= d.getCoord_1().getY() && y <= d.getCoord_3().getY())
			return false;
		if (oriental) {

			if (x + 3 >= d.getCoord_1().getX() && x + 3 <= d.getCoord_3().getX() &&
				y >= d.getCoord_1().getY() && y <= d.getCoord_3().getY())
				return false;
		}
		else {
			if (x >= d.getCoord_1().getX() && x <= d.getCoord_3().getX() &&
				y + 3 >= d.getCoord_1().getY() && y + 3 <= d.getCoord_3().getY())
				return false;
		}
	}
	}
	return true;
}
