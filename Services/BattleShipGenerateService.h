#pragma once
//створює набір кораблів у складі: 1 чотирипалубник
//2 трьохпалубники; 3 двопалубники та 4 однопалубники

class BattleShipGenerateService {

	Ship* _ships;

public:

	BattleShipGenerateService();
	Ship* CreateSingleDeck(int x, int y);
	Ship* CreateDoubleDeck(int x, int y, bool oriental);
	Ship* CreateThreeDeck(int x, int y, bool oriental);
	Ship* CreateFourDeck(int x, int y, bool oriental);

};