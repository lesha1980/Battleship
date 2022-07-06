#pragma once

class GameHumanPCMode :public GameMode {

	GameBoard _gb_1;
	GameBoard _gb_2;
	GameBoard _gb_2_1;
	GameBoard _gb_2_2;
	Ship** ships;
	Ship** ships_1;
	string _login_user;
public:
	void init();
	Gamer* getGamer_1();
	Gamer* getGamer_2();
	void setGamerLogin(string login);
	GameBoard getGameBoard_1();
	Ship** getShips();
	GameBoard getGameBoard_2();
	GameBoard getGameBoard_2_1();
	GameBoard getGameBoard_2_2();
	Ship** getShips_1();
	void setStrategyGamer_1(StrategyGame* strategy);
	void setStrategyGamer_2(StrategyGame* strategy);
};