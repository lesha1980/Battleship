#pragma once

class GamePCPCMode :public GameMode {

	GameBoard _gb_1;
	GameBoard _gb_2;
	GameBoard _gb_2_1;
	GameBoard _gb_2_2;
	Ship** ships;
	Ship** ships_1;
	

public:

	void init();
	Gamer* getGamer_1();
	Gamer* getGamer_2();
	GameBoard getGameBoard_1();
	Ship** getShips();
	GameBoard getGameBoard_2();
	GameBoard getGameBoard_2_1();
	GameBoard getGameBoard_2_2();
	Ship** getShips_1();
	
};
