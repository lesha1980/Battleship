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
	void setStrategyGamer_1(StrategyGame* strategy);
	void setStrategyGamer_2(StrategyGame* strategy);
	void setTurnsGamer1(BattleStack<Turn> turns);
	void setTurnsGamer2(BattleStack<Turn> turns);
	CoordXY getXYByStrategyGamer1();
	CoordXY getXYByStrategyGamer2();

	virtual ~GamePCPCMode() {

		for (size_t i = 0; i < 10; i++) {
			delete ships[i];
		}
		delete[] ships;

		for (size_t i = 0; i < 10; i++) {
			delete ships_1[i];
		}
		delete[] ships_1;
	}
	
};
