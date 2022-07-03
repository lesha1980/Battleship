#include "../libs.h"


GameBoard BattleMapGenerateService::getGameBoard()
{
	return this->_gameBoard;
}

void BattleMapGenerateService::setGameBoard(GameBoard gboard)
{
	this->_gameBoard = gboard;
}

