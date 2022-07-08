#include "../libs.h"

void StrategyContextService::setStrategy(StrategyGame* strategy)
{
	this->_strategy = strategy;
}

void StrategyContextService::setTurns(BattleStack<Turn> turns)
{
	this->_turns = turns;
}

CoordXY StrategyContextService::StrategyShot()
{
	return this->_strategy->Strategy();
}
