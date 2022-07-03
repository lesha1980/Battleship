#pragma once

class GamePCPCMode :public GameMode {

	GameBoard _gb_1;
	GameBoard _gb_2;
	Ship** ships;
	

public:

	void init();
	Gamer* getGamer_1();
	Gamer* getGamer_2();
	GameBoard getGameBoard_1();
	Ship** getShips();
	GameBoard getGameBoard_2();
	
};
