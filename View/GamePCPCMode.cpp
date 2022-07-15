#include "../libs.h"


void GamePCPCMode::init()
{

	this->_gamer1 = this->_pcgamer_ctrl.createGamer("PC-1");
	this->_gamer2 = this->_pcgamer_ctrl.createGamer("PC-2");
	this->ships = new Ship* [10];
	this->ships_1 = new Ship* [10];
	this->_gboard_ctrl.binderShipBoard(this->_gb_2, this->ships);
	this->_gboard_ctrl.binderShipBoard(this->_gb_2_2, this->ships_1);

	
}

Gamer* GamePCPCMode::getGamer_1()
{
	return this->_gamer1;
}

Gamer* GamePCPCMode::getGamer_2()
{
	return this->_gamer2;
}

GameBoard GamePCPCMode::getGameBoard_1()
{
	return this->_gb_1;
}

Ship** GamePCPCMode::getShips()
{
	return this->ships;
}


GameBoard GamePCPCMode::getGameBoard_2()
{
	return this->_gb_2;
}

GameBoard GamePCPCMode::getGameBoard_2_1()
{
	return this->_gb_2_1;
}

GameBoard GamePCPCMode::getGameBoard_2_2()
{
	return this->_gb_2_2;
}

Ship** GamePCPCMode::getShips_1()
{
	return this->ships_1;
}

void GamePCPCMode::setStrategyGamer_1(StrategyGame* strategy)
{
	this->_gaction_ctrl.setStrategyGamer1(strategy);
}

void GamePCPCMode::setStrategyGamer_2(StrategyGame* strategy)
{
	this->_gaction_ctrl.setStrategyGamer2(strategy);
}

void GamePCPCMode::setTurnsGamer1(BattleStack<Turn> turns)
{
	this->_gaction_ctrl.setTurnsGamer1(turns);
}

void GamePCPCMode::setTurnsGamer2(BattleStack<Turn> turns)
{
	this->_gaction_ctrl.setTurnsGamer2(turns);
}

CoordXY GamePCPCMode::getXYByStrategyGamer1()
{
	return this->_gaction_ctrl.getXYByStrategyGamer1();
}

CoordXY GamePCPCMode::getXYByStrategyGamer2()
{
	return this->_gaction_ctrl.getXYByStrategyGamer2();
}


