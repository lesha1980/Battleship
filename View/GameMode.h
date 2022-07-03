#pragma once

class GameMode {

protected:
	PCGamerController _pcgamer_ctrl;
	HumanGamerController _hgamer_ctrl;
	GameBoardContextController _gboard_ctrl;
	Gamer* _gamer1;
	Gamer* _gamer2;
	

public:
	GameMode();
	virtual void init() = 0;
	virtual Gamer* getGamer_1() = 0;
	virtual Gamer* getGamer_2() = 0;
};