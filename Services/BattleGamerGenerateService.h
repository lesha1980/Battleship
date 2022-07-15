#pragma once

class BattleGamerGenerateService {
	
public:
	Gamer* getPCGamer(string login);
	Gamer* getHumanGamer(string login);
};
