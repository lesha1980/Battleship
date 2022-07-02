#pragma once

class GameMode {

protected:
	PCGamerController _pcgamer_ctrl;
	Gamer* _gamer1;
	Gamer* _gamer2;

public:

	virtual void init() = 0;
	Gamer* getGamer_1();
	Gamer* getGamer_2();
};