#include "../libs.h"

void GameActionController::setStrategyGamer2(StrategyGame* strategy)
{
	this->_strategy_gamer_2->setStrategy(strategy);
}

void GameActionController::setTurnsGamer1(BattleStack<Turn> turns)
{
	this->_strategy_gamer_1->setTurns(turns);
}

void GameActionController::setTurnsGamer2(BattleStack<Turn> turns)
{
	this->_strategy_gamer_2->setTurns(turns);
}

CoordXY GameActionController::getXYByStrategyGamer1()
{
	return this->_strategy_gamer_1->StrategyShot();
}

CoordXY GameActionController::getXYByStrategyGamer2()
{
	return this->_strategy_gamer_2->StrategyShot();
}

GameActionController::GameActionController()
{
	this->_strategy_gamer_1 = new StrategyContextService();
	this->_strategy_gamer_2 = new StrategyContextService();
}

void GameActionController::setStrategyGamer1(StrategyGame* strategy)
{
	this->_strategy_gamer_1->setStrategy(strategy);
}
