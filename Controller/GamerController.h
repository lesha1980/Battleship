#pragma once

class GamerController {

protected:
	BattleGamerGenerateService _gamerService;
public:
	virtual Gamer* createGamer(string login) = 0;
};
