#pragma once

class GamerController {

public:
	virtual Gamer* createGamer(string login) = 0;
};
