#include "../libs.h"

void GameHumanPCMode::init()
{
	this->_gamer1 = this->_pcgamer_ctrl.createGamer(this->_login_user);
	this->_gamer2 = this->_pcgamer_ctrl.createGamer("PC-2");
	this->ships = new Ship * [10];
	this->ships_1 = new Ship * [10];
	int field;
	cout << "Необходимо определить, как будет заполняться игровое поле кораблями." << endl;
	cout << "Компьютер расставит корабли — выберите 1" << endl;
	cout << "Игрок самостоятельно расставляет корабли — выберите 2" << endl;
	cin >> field;

	if (field > 2 || field < 1) {
		cout << "Игрок не разобрался, как необходимо расставить корабли. Игра завершается." << endl;
		return;
	}

	int x = -1;
	int y = -1;
	int x_1 = -1;
	int y_1 = -1;
	int x_2 = -1;
	int y_2 = -1;
	int x_3 = -1;
	int y_3 = -1;

	if (field == 2) {
		int count = 0;
		while (true) {
			
			int kind;
			cout << "Какой корабль расставляем? " << endl;
			cout << "Четырехпалубник — 1" << endl;
			cout << "Трехпалубник - 2" << endl;
			cout << "Двупалубник - 3" << endl;
			cout << "Однопалубник - 4" << endl;
			cin >> kind;
			cin.clear();
			if (kind > 4 || kind < 1)
			{
				cout << "Неверно указан корабль" << endl;
				continue;
			}

			if (kind == 1) {
				bool is_four = false;
				for (size_t i = 0; i < count; i++)
				{
					if (this->ships[i]->getTypeShip() == TypeShip::FourDeckShip)
					{
						cout << "Четырехпалубник уже есть среди кораблей" << endl;
						is_four = true;
						break;
					}
				}
				if (!is_four)
				{
					bool oriental;
					cout << "Как расположен четырехпалубник?" << endl;
					cout << "Вертикально — 1" << endl;
					cout << "Горизонтально - 2" << endl;
					cin >> oriental;
					cin.clear();
					if (oriental)
					{
						oriental = true;
					}
					else {
						oriental = false;
					}
					
					cout << "Укажите координаты носа корабля" << endl;
					cout << "Координата x: " << endl;
					cin >> x;
					cout << "Координата y: " << endl;
					cin >> y;
					cin.clear();
					if (x > 10 || x < 0)
					{
						cout << "Неверно указана координата x" << endl;
						continue;
					}
					if (y > 10 || y < 0) {
						cout << "Неверно указана координата y" << endl;
						continue;
					}
					bool place = this->_gboard_ctrl.binderShipBoard(this->_gb_2, this->ships, x, y, TypeShip::FourDeckShip, oriental, count);
				
					if (!place) {
						cout << "Невозможно разместить корабль в данной точке, так как он может соприкаться с другими кораблями" << endl;
						continue;
					}
				}
			}
			else if (kind == 2) {
				bool is_three = false;
				int sum = 0;
				for (size_t i = 0; i < count; i++)
				{
					if (this->ships[i]->getTypeShip() == TypeShip::ThreeDeckShip)
					{
							sum++;
					}
				}

				if (sum == 2) {

					cout << "Трехпалубников уже достаточно" << endl;
					is_three = true;
				}

				if (!is_three)
				{
					bool oriental;
					cout << "Как расположен трехпалубник?" << endl;
					cout << "Вертикально — 1" << endl;
					cout << "Горизонтально - 2" << endl;
					cin >> oriental;
					cin.clear();
					if (oriental)
					{
						oriental = true;
					}
					else {
						oriental = false;
					}
					
					cout << "Укажите координаты носа корабля" << endl;
					cout << "Координата x: " << endl;
					cin >> x_1;
					cout << "Координата y: " << endl;
					cin >> y_1;
					cin.clear();
					if (x_1 > 10 || x_1 < 0)
					{
						cout << "Неверно указана координата x" << endl;
						continue;
					}
					if (y_1 > 10 || y_1 < 0) {
						cout << "Неверно указана координата y" << endl;
						continue;
					}
					bool place = this->_gboard_ctrl.binderShipBoard(this->_gb_2, this->ships, x_1, y_1, TypeShip::ThreeDeckShip, oriental, count);

					if (!place) {
						cout << "Невозможно разместить корабль в данной точке, так как он может соприкаться с другими кораблями" << endl;
						continue;
					}
				}

			}
			else if (kind == 3) {

			bool is_two = false;
			int sum = 0;
			for (size_t i = 0; i < count; i++)
			{
				if (this->ships[i]->getTypeShip() == TypeShip::DoubleDeckShip)
				{
						sum++;	
				}

			}

			if (sum == 3) {

				cout << "Двухпалубников уже достаточно" << endl;
				is_two = true;

			
			}
			if (!is_two)
			{
				bool oriental;
				cout << "Как расположен двухпалубник?" << endl;
				cout << "Вертикально — 1" << endl;
				cout << "Горизонтально - 2" << endl;
				cin >> oriental;
				cin.clear();
				if (oriental)
				{
					oriental = true;
				}
				else {
					oriental = false;
				}
				
				cout << "Укажите координаты носа корабля" << endl;
				cout << "Координата x: " << endl;
				cin >> x_2;
				cout << "Координата y: " << endl;
				cin >> y_2;
				cin.clear();
				if (x_2 > 10 || x_2 < 0)
				{
					cout << "Неверно указана координата x" << endl;
					continue;
				}
				if (y_2 > 10 || y_2 < 0) {
					cout << "Неверно указана координата y" << endl;
					continue;
				}
				bool place = this->_gboard_ctrl.binderShipBoard(this->_gb_2, this->ships, x_2, y_2, TypeShip::DoubleDeckShip, oriental, count);

				if (!place) {
					cout << "Невозможно разместить корабль в данной точке, так как он может соприкаться с другими кораблями" << endl;
					continue;
				}
			}

			}
			else if (kind == 4) {
			bool is_one = false;
			int sum = 0;
			for (size_t i = 0; i < count; i++)
			{
				if (this->ships[i]->getTypeShip() == TypeShip::SingleDeckShip)
				{
					sum++;	
				}
			}

			if (sum == 4) {

				cout << "Однопалубников уже достаточно" << endl;
				is_one = true;

				
			}

			if (!is_one)
			{
				bool oriental =true;
			
				
				cout << "Укажите координаты носа корабля" << endl;
				cout << "Координата x: " << endl;
				cin >> x_3;
				cout << "Координата y: " << endl;
				cin >> y_3;
				cin.clear();
				if (x_3 > 10 || x_3 < 0)
				{
					cout << "Неверно указана координата x" << endl;
					continue;
				}
				if (y_3 > 10 || y_3 < 0) {
					cout << "Неверно указана координата y" << endl;
					continue;
				}
				bool place = this->_gboard_ctrl.binderShipBoard(this->_gb_2, this->ships, x_3, y_3, TypeShip::SingleDeckShip, oriental, count);

				if (!place) {
					cout << "Невозможно разместить корабль в данной точке, так как он может соприкаться с другими кораблями" << endl;
					continue;
				}
			}
			}




			if (count == 10)
			{
				break;
			}
		}
	}
	else if (field == 1) {
		this->_gboard_ctrl.binderShipBoard(this->_gb_2, this->ships);
	}
	this->_gboard_ctrl.binderShipBoard(this->_gb_2_2, this->ships_1);
}

Gamer* GameHumanPCMode::getGamer_1()
{
	return this->_gamer1;
}

Gamer* GameHumanPCMode::getGamer_2()
{
	return this->_gamer2;
}

void GameHumanPCMode::setGamerLogin(string login)
{
	this->_login_user = login;
}

GameBoard GameHumanPCMode::getGameBoard_1()
{
	return this->_gb_1;
}

Ship** GameHumanPCMode::getShips()
{
	return this->ships;
}

GameBoard GameHumanPCMode::getGameBoard_2()
{
	return this->_gb_2;
}

GameBoard GameHumanPCMode::getGameBoard_2_1()
{
	return this->_gb_2_1;
}

GameBoard GameHumanPCMode::getGameBoard_2_2()
{
	return this->_gb_2_2;
}

Ship** GameHumanPCMode::getShips_1()
{
	return this->ships_1;
}

void GameHumanPCMode::setStrategyGamer_1(StrategyGame* strategy)
{
	this->_gaction_ctrl.setStrategyGamer1(strategy);
}

void GameHumanPCMode::setStrategyGamer_2(StrategyGame* strategy)
{
	this->_gaction_ctrl.setStrategyGamer2(strategy);
}

void GameHumanPCMode::setTurnsGamer1(BattleStack<Turn> turns)
{
	this->_gaction_ctrl.setTurnsGamer1(turns);
}

void GameHumanPCMode::setTurnsGamer2(BattleStack<Turn> turns)
{
	this->_gaction_ctrl.setTurnsGamer2(turns);
}

CoordXY GameHumanPCMode::getXYByStrategyGamer1()
{
	return this->_gaction_ctrl.getXYByStrategyGamer1();
}

CoordXY GameHumanPCMode::getXYByStrategyGamer2()
{
	return this->_gaction_ctrl.getXYByStrategyGamer2();
}

