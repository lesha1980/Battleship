#include "../libs.h"

void GamePCPCMode::init()
{

	this->_gamer1 = this->_pcgamer_ctrl.createGamer("PC-1");
	this->_gamer2 = this->_pcgamer_ctrl.createGamer("PC-2");
	
}

Gamer* GamePCPCMode::getGamer_1()
{
	return this->_gamer1;
}

Gamer* GamePCPCMode::getGamer_2()
{
	return this->_gamer2;
}
