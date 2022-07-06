#include "../libs.h"

void GameActionController::setStrategyGamer2(StrategyGame* strategy)
{
	this->_strategy_gamer_2.setStrategy(strategy);
}

void GameActionController::setStrategyGamer1(StrategyGame* strategy)
{
	this->_strategy_gamer_1.setStrategy(strategy);
}
