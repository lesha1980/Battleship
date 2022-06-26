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
		if (_ship->getTypeShip() == TypeShip::SingleDeckShip) {
		    SingleDeck sdeck =(SingleDeck&)_ship;
			Deck d = sdeck.getDeck();

			if (d.getX() == x && d.getY() == y)
				return false;

			if (d.getX() == 0 && d.getY() == 0)
			{
				if ((x == 0 && y == 1) || (x == 1 && y == 1) || (x == 1 && y == 0))
					return false;

			}
			else if (d.getX() == 0 && d.getY() == columns) {
				if ((x == 0 && y == columns - 1) || (x == 1 && y == columns - 1) || (x == 1 && y == columns))
					return false;
			}
			else if(d.getX() == rows && d.getY() == 0){
				if ((x == rows - 1 && y == 0) || (x == rows - 1 && y == 1) || (x == rows && y == 1))
					return false;

			}
			else if (d.getX() == rows && d.getY() == columns)
			{
				if ((x == rows - 1 && y == columns) || (x == rows - 1 && y == columns - 1) || (x == rows && y == columns - 1))
					return false;
			}
			else if(d.getX() == 0 && (d.getY() > 0 && d.getY() < columns)) {
				if ((x == 0 && y == (d.getY() + 1)) || (x == 0 && y == (d.getY() - 1)) || (x == 1 && y == d.getY()) || (x == 1 && y == (d.getY() - 1)) || (x == 1 && y == (d.getY() + 1)))
					return false;
				
			}
			else if (d.getX() == rows && (d.getY() > 0 && d.getY() < columns))
			{
				if ((x == rows && y == (d.getY() + 1)) || (x == rows && y == (d.getY() - 1)) || (x == rows - 1 && y == d.getY()) || (x == rows - 1 && y == (d.getY() - 1)) || (x == rows - 1 && y == (d.getY() + 1)))
					return false;
			}
			else if(d.getY() == 0 && (d.getX() > 0 && d.getX() < rows))
			{
				if ((y == 0 && x == d.getX() - 1) || (y == 0 && x == d.getX() + 1) || (y == 1 && x == d.getX()) || (y == 1 && x == d.getX() - 1) || (y == 1 && x == d.getX() + 1))
					return false;
			}
			else if (d.getY() == columns && (d.getX() > 0 && d.getX() < rows)) {
				if ((y == columns && x == d.getX() - 1) || (y == columns && x == d.getX() + 1) || (y == columns - 1 && x == d.getX()) || (y == columns - 1 && x == d.getX() - 1) || (y == columns - 1 && x == d.getX() + 1))
					return false;
			}
			else {
				if ((x == d.getX() - 1 && y == d.getY() - 1) ||
					(x == d.getX() - 1 && y == d.getY()) ||
					(x == d.getX() - 1 && y == d.getY() + 1) ||
					(x == d.getX() && y == d.getY() - 1) ||
					(x == d.getX() && y == d.getY() + 1) ||
					(x == d.getX() + 1 && y == d.getY() - 1)||
					(x == d.getX() + 1 && y == d.getY()) ||
					(x == d.getX() + 1 && y == d.getY() + 1))
				{
					return false;
				}
			}


		}
		if (_ship->getTypeShip() == TypeShip::DoubleDeckShip)
		{
			DoubleDeck ddeck = (DoubleDeck&)_ship;
			Deck deck_1 = ddeck.getDeck_1();
			Deck deck_2 = ddeck.getDeck_2();

			if (x == deck_1.getX() && y == deck_1.getY() || x == deck_2.getX() && y == deck_2.getY())
				return false;

			if (deck_1.getX() == 0 && deck_1.getY() == 0)
			{
				if ((x == 0 && y == 1) || (x == 1 && y == 1) || (x == 1 && y == 0))
					return false;

			}

		}
	}
	
	
	return true;
}
