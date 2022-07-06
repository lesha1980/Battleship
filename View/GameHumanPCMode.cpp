#include "../libs.h"

void GameHumanPCMode::init()
{
	this->_gamer1 = this->_pcgamer_ctrl.createGamer(this->_login_user);
	this->_gamer2 = this->_pcgamer_ctrl.createGamer("PC-2");
	this->ships = new Ship * [10];
	this->ships_1 = new Ship * [10];
	int field;
	cout << "���������� ����������, ��� ����� ����������� ������� ���� ���������." << endl;
	cout << "��������� ��������� ������� � �������� 1" << endl;
	cout << "����� �������������� ����������� ������� � �������� 2" << endl;
	cin >> field;

	if (field > 2 || field < 1) {
		cout << "����� �� ����������, ��� ���������� ���������� �������. ���� �����������." << endl;
		return;
	}


	if (field == 2) {
		int count = 0;
		while (true) {
			
			int kind;
			cout << "����� ������� �����������? " << endl;
			cout << "��������������� � 1" << endl;
			cout << "������������ - 2" << endl;
			cout << "����������� - 3" << endl;
			cout << "������������ - 4" << endl;
			cin >> kind;

			if (kind > 4 || kind < 1)
			{
				cout << "������� ������ �������" << endl;
				continue;
			}

			if (kind == 1) {
				bool is_four = false;
				for (size_t i = 0; i < count; i++)
				{
					if (typeid(this->ships[i]) == typeid(FourDeckShip))
					{
						cout << "��������������� ��� ���� ����� ��������" << endl;
						is_four = true;
						break;
					}
				}
				if (!is_four)
				{
					bool oriental;
					cout << "��� ���������� ���������������?" << endl;
					cout << "����������� � 1" << endl;
					cout << "������������� - 2" << endl;
					cin >> oriental;
					if (oriental)
					{
						oriental = true;
					}
					else {
						oriental = false;
					}
					int x, y;
					cout << "������� ���������� ���� �������" << endl;
					cout << "���������� x: " << endl;
					cin >> x;
					cout << "���������� y: " << endl;
					cin >> y;

					if (x > 10 || x < 0)
					{
						cout << "������� ������� ���������� x" << endl;
						continue;
					}
					if (y > 10 || y < 0) {
						cout << "������� ������� ���������� y" << endl;
						continue;
					}
					bool place = this->_gboard_ctrl.binderShipBoard(this->_gb_2, this->ships, x, y, TypeShip::FourDeckShip, oriental, count);
				
					if (!place) {
						cout << "���������� ���������� ������� � ������ �����, ��� ��� �� ����� ����������� � ������� ���������" << endl;
						continue;
					}
				}
			}
			else if (kind == 2) {
				bool is_three = false;
				int sum = 0;
				for (size_t i = 0; i < count; i++)
				{
					if (typeid(this->ships[i]) == typeid(ThreeDeckShip))
					{
						if (sum == 2) {

							cout << "�������������� ��� ����������" << endl;
							is_three = true;

							break;
						}
						else {
							sum++;
						}
					}


				}
				if (!is_three)
				{
					bool oriental;
					cout << "��� ���������� ������������?" << endl;
					cout << "����������� � 1" << endl;
					cout << "������������� - 2" << endl;
					cin >> oriental;
					if (oriental)
					{
						oriental = true;
					}
					else {
						oriental = false;
					}
					int x, y;
					cout << "������� ���������� ���� �������" << endl;
					cout << "���������� x: " << endl;
					cin >> x;
					cout << "���������� y: " << endl;
					cin >> y;

					if (x > 10 || x < 0)
					{
						cout << "������� ������� ���������� x" << endl;
						continue;
					}
					if (y > 10 || y < 0) {
						cout << "������� ������� ���������� y" << endl;
						continue;
					}
					bool place = this->_gboard_ctrl.binderShipBoard(this->_gb_2, this->ships, x, y, TypeShip::ThreeDeckShip, oriental, count);

					if (!place) {
						cout << "���������� ���������� ������� � ������ �����, ��� ��� �� ����� ����������� � ������� ���������" << endl;
						continue;
					}
				}

			}
			else if (kind == 3) {

			bool is_two = false;
			int sum = 0;
			for (size_t i = 0; i < count; i++)
			{
				if (typeid(this->ships[i]) == typeid(DoubleDeckShip))
				{
					if (sum == 3) {

						cout << "�������������� ��� ����������" << endl;
						is_two = true;

						break;
					}
					else {
						sum++;
					}
				}


			}
			if (!is_two)
			{
				bool oriental;
				cout << "��� ���������� ������������?" << endl;
				cout << "����������� � 1" << endl;
				cout << "������������� - 2" << endl;
				cin >> oriental;
				if (oriental)
				{
					oriental = true;
				}
				else {
					oriental = false;
				}
				int x, y;
				cout << "������� ���������� ���� �������" << endl;
				cout << "���������� x: " << endl;
				cin >> x;
				cout << "���������� y: " << endl;
				cin >> y;

				if (x > 10 || x < 0)
				{
					cout << "������� ������� ���������� x" << endl;
					continue;
				}
				if (y > 10 || y < 0) {
					cout << "������� ������� ���������� y" << endl;
					continue;
				}
				bool place = this->_gboard_ctrl.binderShipBoard(this->_gb_2, this->ships, x, y, TypeShip::DoubleDeckShip, oriental, count);

				if (!place) {
					cout << "���������� ���������� ������� � ������ �����, ��� ��� �� ����� ����������� � ������� ���������" << endl;
					continue;
				}
			}

			}
			else if (kind == 4) {
			bool is_one = false;
			int sum = 0;
			for (size_t i = 0; i < count; i++)
			{
				if (typeid(this->ships[i]) == typeid(SingleDeckShip))
				{
					if (sum == 4) {

						cout << "�������������� ��� ����������" << endl;
						is_one = true;

						break;
					}
					else {
						sum++;
					}
				}


			}
			if (!is_one)
			{
				bool oriental =true;
			
				int x, y;
				cout << "������� ���������� ���� �������" << endl;
				cout << "���������� x: " << endl;
				cin >> x;
				cout << "���������� y: " << endl;
				cin >> y;

				if (x > 10 || x < 0)
				{
					cout << "������� ������� ���������� x" << endl;
					continue;
				}
				if (y > 10 || y < 0) {
					cout << "������� ������� ���������� y" << endl;
					continue;
				}
				bool place = this->_gboard_ctrl.binderShipBoard(this->_gb_2, this->ships, x, y, TypeShip::SingleDeckShip, oriental, count);

				if (!place) {
					cout << "���������� ���������� ������� � ������ �����, ��� ��� �� ����� ����������� � ������� ���������" << endl;
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
	return nullptr;
}

Gamer* GameHumanPCMode::getGamer_2()
{
	return nullptr;
}

void GameHumanPCMode::setGamerLogin(string login)
{
	this->_login_user = login;
}

GameBoard GameHumanPCMode::getGameBoard_1()
{
	return GameBoard();
}

Ship** GameHumanPCMode::getShips()
{
	return nullptr;
}

GameBoard GameHumanPCMode::getGameBoard_2()
{
	return GameBoard();
}

GameBoard GameHumanPCMode::getGameBoard_2_1()
{
	return GameBoard();
}

GameBoard GameHumanPCMode::getGameBoard_2_2()
{
	return GameBoard();
}

Ship** GameHumanPCMode::getShips_1()
{
	return nullptr;
}

void GameHumanPCMode::setStrategyGamer_1(StrategyGame* strategy)
{
}

void GameHumanPCMode::setStrategyGamer_2(StrategyGame* strategy)
{
}

CoordXY GameHumanPCMode::getXYByStrategyGamer1()
{
	return CoordXY();
}

CoordXY GameHumanPCMode::getXYByStrategyGamer2()
{
	return CoordXY();
}

