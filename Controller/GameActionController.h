#pragma once

class GameActionController {

	StrategyContextService* _strategy_gamer_1;
	StrategyContextService* _strategy_gamer_2;

public:
	GameActionController();
	void setStrategyGamer1(StrategyGame* strategy);
	void setStrategyGamer2(StrategyGame* strategy);
	void setTurnsGamer1(BattleStack<Turn> turns);
	void setTurnsGamer2(BattleStack<Turn> turns);
	CoordXY getXYByStrategyGamer1();
	CoordXY getXYByStrategyGamer2();

	~GameActionController() {
	   delete this->_strategy_gamer_1;
	   delete this->_strategy_gamer_2;
	}

};
