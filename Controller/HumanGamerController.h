#pragma once

class HumanGamerController:public GamerController {

public:
	Gamer* createGamer(string login);
};
