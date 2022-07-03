#pragma once

class GameHumanPCMode :public GameMode {

public:
	void init();
	Gamer* getGamer_1();
	Gamer* getGamer_2();
};