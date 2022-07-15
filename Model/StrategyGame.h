#pragma once

class StrategyGame {

protected:
	BattleStack<Turn> _turns;
public:
	virtual CoordXY Strategy() = 0;
	void setTurns(BattleStack<Turn> turns);

	virtual ~StrategyGame() {

	}
};
