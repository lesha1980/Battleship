#include "../libs.h"

void Screen::printScreenGamer_1(GameBoard& gb_1, GameBoard& gb_2, Ship** ships_1, Ship** ships_2)
{
	this->printScreen(gb_1, gb_2, ships_1, ships_2);
}

void Screen::printScreenGamer_2(GameBoard& gb_1, GameBoard& gb_2, Ship** ships_1, Ship** ships_2)
{
	this->printScreen(gb_1, gb_2, ships_1, ships_2);
}

void Screen::printScreen(GameBoard& gb_1, GameBoard& gb_2, Ship** ships_1, Ship** ships_2)
{
	Cell** cells_1 = gb_1.getBoard();
	Cell** cells_2 = gb_2.getBoard();
	char* lstCols = gb_1.getLstColumns();
	int* lstRows = gb_1.getLstRow();

	for (size_t i = 0; i < strlen(lstCols); i++) {
		cout << lstCols[i] << ' ';
	}

	//Поле для противника геймера 1 
	for (size_t i = 0; i < gb_1.getRows(); i++) {
		cout << lstRows[i] << ' ';
		for (size_t j = 0; j < gb_1.getColumns(); j++)
		{
			bool a = true;
			for (size_t k = 0; k < 10; k++) {
				Ship* _ship = ships_2[k];
				if (_ship->getTypeShip() == TypeShip::SingleDeckShip) {
					SingleDeck* sdeck = (SingleDeck*)_ship;
					Deck d = sdeck->getDeck();
					if (d.getX() == i && d.getY() == j)
					{
						bool st = d.getStatus();
						if (!st) {
							cout << 'x' << ' ';
							a = false;
						}
					}
				}
				if (_ship->getTypeShip() == TypeShip::DoubleDeckShip)
				{
					DoubleDeck* ddeck = (DoubleDeck*)_ship;
					Deck d_1 = ddeck->getDeck_1();
					if (d_1.getX() == i && d_1.getY() == j)
					{
						bool st = d_1.getStatus();
						if (!st) {
							cout << 'x' << ' ';
							a = false;
						}
					}
					Deck d_2 = ddeck->getDeck_2();
					if (d_2.getX() == i && d_2.getY() == j)
					{
						bool st = d_2.getStatus();
						if (!st) {
							cout << 'x' << ' ';
							a = false;
						}
					}

				}
				if (_ship->getTypeShip() == TypeShip::ThreeDeckShip) {
					ThreeDeck* tdeck = (ThreeDeck*)_ship;

					Deck d_1 = tdeck->getDeck_1();
					if (d_1.getX() == i && d_1.getY() == j)
					{
						bool st = d_1.getStatus();
						if (!st) {
							cout << 'x' << ' ';
							a = false;
						}
					}
					Deck d_2 = tdeck->getDeck_2();
					if (d_2.getX() == i && d_2.getY() == j)
					{
						bool st = d_2.getStatus();
						if (!st) {
							cout << 'x' << ' ';
							a = false;
						}
					}
					Deck d_3 = tdeck->getDeck_3();
					if (d_3.getX() == i && d_3.getY() == j)
					{
						bool st = d_3.getStatus();
						if (!st) {
							cout << 'x' << ' ';
							a = false;
						}
					}
					
				}
				if (_ship->getTypeShip() == TypeShip::FourDeckShip) {
					FourDeck* fdeck = (FourDeck*)_ship;
					Deck d_1 = fdeck->getDeck_1();
					if (d_1.getX() == i && d_1.getY() == j)
					{
						bool st = d_1.getStatus();
						if (!st) {
							cout << 'x' << ' ';
							a = false;
						}
					}
					Deck d_2 = fdeck->getDeck_2();
					if (d_2.getX() == i && d_2.getY() == j)
					{
						bool st = d_2.getStatus();
						if (!st) {
							cout << 'x' << ' ';
							a = false;
						}
					}
					Deck d_3 = fdeck->getDeck_3();
					if (d_3.getX() == i && d_3.getY() == j)
					{
						bool st = d_3.getStatus();
						if (!st) {
							cout << 'x' << ' ';
							a = false;
						}
					}
					Deck d_4 = fdeck->getDeck_4();
					if (d_4.getX() == i && d_4.getY() == j)
					{
						bool st = d_4.getStatus();
						if (!st) {
							cout << 'x' << ' ';
							a = false;
						}
					}
				}
			}
			if (a) {
				cout << '0' << ' ';
			}
		}
	}

	for (size_t i = 0; i < strlen(lstCols); i++) {
		cout << lstCols[i] << ' ';
	}

	//Поле власних кораблів геймера 1 
	for (size_t i = 0; i < gb_2.getRows(); i++) {
		cout << lstRows[i] << ' ';
		for (size_t j = 0; j < gb_2.getColumns(); j++)
		{
			if (cells_1[i][j].getStatusCell() == StatusCell::Free) {
				cout << '0' << ' ';
			}
			else if (cells_1[i][j].getStatusCell() == StatusCell::Occupied)
			{
				bool a = true;
				for (size_t k = 0; k < 10; k++) {
					Ship* _ship = ships_1[k];
					if (_ship->getTypeShip() == TypeShip::SingleDeckShip) {
						SingleDeck* sdeck = (SingleDeck*)_ship;
						Deck d = sdeck->getDeck();
						if (d.getX() == i && d.getY() == j)
						{
							bool st = d.getStatus();
							if (!st) {
								cout << 'x' << ' ';
								a = false;
							}
						}
					}
					if (_ship->getTypeShip() == TypeShip::DoubleDeckShip)
					{
						DoubleDeck* ddeck = (DoubleDeck*)_ship;
						Deck d_1 = ddeck->getDeck_1();
						if (d_1.getX() == i && d_1.getY() == j)
						{
							bool st = d_1.getStatus();
							if (!st) {
								cout << 'x' << ' ';
								a = false;
							}
						}
						Deck d_2 = ddeck->getDeck_2();
						if (d_2.getX() == i && d_2.getY() == j)
						{
							bool st = d_2.getStatus();
							if (!st) {
								cout << 'x' << ' ';
								a = false;
							}
						}

					}
					if (_ship->getTypeShip() == TypeShip::ThreeDeckShip) {
						ThreeDeck* tdeck = (ThreeDeck*)_ship;

						Deck d_1 = tdeck->getDeck_1();
						if (d_1.getX() == i && d_1.getY() == j)
						{
							bool st = d_1.getStatus();
							if (!st) {
								cout << 'x' << ' ';
								a = false;
							}
						}
						Deck d_2 = tdeck->getDeck_2();
						if (d_2.getX() == i && d_2.getY() == j)
						{
							bool st = d_2.getStatus();
							if (!st) {
								cout << 'x' << ' ';
								a = false;
							}
						}
						Deck d_3 = tdeck->getDeck_3();
						if (d_3.getX() == i && d_3.getY() == j)
						{
							bool st = d_3.getStatus();
							if (!st) {
								cout << 'x' << ' ';
								a = false;
							}
						}

					}
					if (_ship->getTypeShip() == TypeShip::FourDeckShip) {
						FourDeck* fdeck = (FourDeck*)_ship;
						Deck d_1 = fdeck->getDeck_1();
						if (d_1.getX() == i && d_1.getY() == j)
						{
							bool st = d_1.getStatus();
							if (!st) {
								cout << 'x' << ' ';
								a = false;
							}
						}
						Deck d_2 = fdeck->getDeck_2();
						if (d_2.getX() == i && d_2.getY() == j)
						{
							bool st = d_2.getStatus();
							if (!st) {
								cout << 'x' << ' ';
								a = false;
							}
						}
						Deck d_3 = fdeck->getDeck_3();
						if (d_3.getX() == i && d_3.getY() == j)
						{
							bool st = d_3.getStatus();
							if (!st) {
								cout << 'x' << ' ';
								a = false;
							}
						}
						Deck d_4 = fdeck->getDeck_4();
						if (d_4.getX() == i && d_4.getY() == j)
						{
							bool st = d_4.getStatus();
							if (!st) {
								cout << 'x' << ' ';
								a = false;
							}
						}
					}
				}
				if (a) {
					cout << '1' << ' ';
				}
			}
			else if (cells_1[i][j].getStatusCell() == StatusCell::SingleShot)
			{
				cout << '*' << ' ';
			}
		}
	}



}
