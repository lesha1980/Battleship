#pragma once
#include "../Utilits/BattleStack.h"

class Gamer {

protected:
	string _login; 
	BattleStack<Turn> _turns;

public:
	Gamer(string login);
	string getLogin();
	

};
