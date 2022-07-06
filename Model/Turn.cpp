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
