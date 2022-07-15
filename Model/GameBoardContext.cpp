#include "../libs.h"

GameBoardContext::GameBoardContext(GameBoard gameBoard, Ship** ship)
{
	this->_gameBoard = gameBoard;
	this->ships = ship;
}
