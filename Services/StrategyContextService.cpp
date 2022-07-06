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
	if (typeid(this->_strategy) == typeid(StrategyDontShotZoneShip))
	{

	}
	return this->_strategy->Strategy();
}
