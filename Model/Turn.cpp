#include "../libs.h"

Turn::Turn()
{
}

Turn::Turn(int clmn, int rw)
{
	this->_clmn = clmn;
	this->_rw - rw;
}

void Turn::setStatusTurn(StatusTurn status)
{
	this->_status_turn = status;
}

StatusTurn Turn::getStatusTurn()
{
	return this->_status_turn;
}

int Turn::getColumn()
{
	return this->_clmn;
}

int Turn::getRow()
{
	return this->_rw;
}
