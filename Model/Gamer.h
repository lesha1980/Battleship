#pragma once
#include "../Utilits/BattleStack.h"

class Gamer {

protected:
	string _login; 
	BattleStack<Turn> _turns;

public:
	Gamer() = default;
	Gamer(string login);
	string getLogin();
	void setTurn(Turn turn);
	Turn theLastTurn();

};
