#pragma once
//створює набір кораблів у складі: 1 чотирипалубник
//2 трьохпалубники; 3 двопалубники та 4 однопалубники

class BattleShipGenerateService {

	Ship** _ships;
	int _count;

public:

	BattleShipGenerateService();
	Ship* CreateSingleDeck(int x, int y);
	Ship* CreateDoubleDeck(int x, int y, bool oriental);
	Ship* CreateThreeDeck(int x, int y, bool oriental);
	Ship* CreateFourDeck(int x, int y, bool oriental);
	void CreateDataSingleShip(Ship* (*SingleDeckCreatorPtr)(int, int), int x, int y, int index);
	void CreateDataDoubleShip(Ship* (*MultiDeckCreatorPtr)(int x, int y, bool oriental), int x, int y, bool oriental, int index);
	Ship** getShips();
	int getCount();

	Ship* operator[](int index);

	virtual ~BattleShipGenerateService();

};