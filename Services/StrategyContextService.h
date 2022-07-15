#pragma once

class StrategyContextService {

	StrategyGame* _strategy;
	BattleStack<Turn> _turns;

public:

	void setStrategy(StrategyGame* strategy);
	void setTurns(BattleStack<Turn> turns);
	CoordXY StrategyShot();

    
};
