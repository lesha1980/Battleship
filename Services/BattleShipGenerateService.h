#pragma once
//������� ���� ������� � �����: 1 ��������������
//2 ��������������; 3 ������������ �� 4 �������������

class BattleShipGenerateService {

	Ship** _ships;
	int _count;

public:

	BattleShipGenerateService();
	Ship* CreateSingleDeck(int x, int y);
	Ship* CreateDoubleDeck(int x, int y, bool oriental);
	Ship* CreateThreeDeck(int x, int y, bool oriental);
	Ship* CreateFourDeck(int x, int y, bool oriental);
	void setShip(Ship* ship);
	Ship** getShips();
	int getCount();

	Ship* operator[](int index);

	virtual ~BattleShipGenerateService();

};