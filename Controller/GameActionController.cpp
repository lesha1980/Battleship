#include "../libs.h"

void GameActionController::setStrategyGamer2(StrategyGame* strategy)
{
	this->_strategy_gamer_2.setStrategy(strategy);
}

CoordXY GameActionController::getXYByStrategyGamer1()
{
	return CoordXY();
}

CoordXY GameActionController::getXYByStrategyGamer2()
{
	return CoordXY();
}

void GameActionController::setStrategyGamer1(StrategyGame* strategy)
{
	this->_strategy_gamer_1.setStrategy(strategy);
}
