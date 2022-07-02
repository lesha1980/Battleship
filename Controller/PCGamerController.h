#pragma once

class PCGamerController:public GamerController {

public:
	Gamer* createGamer(string login);
};