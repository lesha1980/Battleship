#include "../libs.h"


void GamePCPCMode::init()
{

	this->_gamer1 = this->_pcgamer_ctrl.createGamer("PC-1");
	this->_gamer2 = this->_pcgamer_ctrl.createGamer("PC-2");
	this->_gb_1 = this->_gboard_ctrl.getGameBoard();
	this->_gboard_ctrl.binderShipBoard();
	this->_gb_2 = this->_gboard_ctrl.getGameBoard();
	this->ships = this->getShips();
	
	
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
	return GameBoard();
}

Ship** GamePCPCMode::getShips()
{
	return this->ships;
}


GameBoard GamePCPCMode::getGameBoard_2()
{
	return GameBoard();
}


